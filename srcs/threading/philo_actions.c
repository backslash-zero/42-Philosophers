/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/06 18:03:17 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	drop_forks(t_philosopher *philosopher)
{
	printf("Philo-%d: Dropping forks\n", philosopher->id);
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
	printf("Philo-%d: Forks dropped\n", philosopher->id);
}

void	pickup_forks(t_philosopher *philosopher)
{
	printf("Philo-%d: Picking up forks\n", philosopher->id);
	pthread_mutex_lock(philosopher->fork_left);
	pthread_mutex_lock(philosopher->fork_right);
	printf("Philo-%d: Forks pickd up\n", philosopher->id);
}

void	philosopher_dies(t_philosopher *philosopher)
{
	long	timestamp;
	if (philosopher->settings->everyone_alive != 0)
	{
		philosopher->settings->everyone_alive = 0;
		timestamp = get_time();
		printtime(timestamp, philosopher->id, "died", philosopher->settings);
	}
}

void	philosopher_update_lastmeal(t_philosopher *philosopher, double timestamp)
{
	printf("Philo-%d: updating last meal\n", philosopher->id);
	pthread_mutex_lock(&philosopher->mutex_lastmeal);
	philosopher->lastmeal = timestamp;
	pthread_mutex_unlock(&philosopher->mutex_lastmeal);
	printf("Philo-%d: updated last meal\n", philosopher->id);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	long	timestamp;
	
	pickup_forks(philosopher);
	timestamp = get_time();
	philosopher_update_lastmeal(philosopher, timestamp);
	if (philosophing_conditions(philosopher))
	{
		printf("Philo-%d: ready to eat\n", philosopher->id);
		printtime(timestamp, philosopher->id, "is eating", philosopher->settings);
		my_wait(philosopher->settings->time2eat);
		drop_forks(philosopher);
		philosopher_update_lastmeal(philosopher, timestamp + philosopher->settings->time2eat);
		philosopher->meals += 1;
		if (philosopher->meals >= philosopher->settings->musteat && philosopher->settings->option == 1)
		{
			pthread_mutex_lock(&philosopher->settings->mutex_musteat);
			philosopher->settings->musteat_max = 1;
			pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
		}
	}
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	long	timestamp;
	
	timestamp = get_time();
	if (philosophing_conditions(philosopher))
	{
		printtime(timestamp, philosopher->id, "is sleeping", philosopher->settings);
		my_wait(philosopher->settings->time2sleep);
	}

}

void	philosopher_think(t_philosopher *philosopher)
{
	long	timestamp;
	
	timestamp = get_time();
	if (philosophing_conditions(philosopher))
		printtime(timestamp, philosopher->id, "is thinking", philosopher->settings);
}
