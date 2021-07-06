/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/06 12:48:39 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	drop_forks(t_philosopher *philosopher)
{
	printf("Dropping forks\n");
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
	printf("Forks dropped\n");
}

void	pickup_forks(t_philosopher *philosopher)
{
	printf("Picking up forks\n");
	pthread_mutex_lock(philosopher->fork_left);
	pthread_mutex_lock(philosopher->fork_right);
	printf("Forks pickd up\n");
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

void	philosopher_eating_update(t_philosopher *philosopher)
{
	philosopher->meals += 1;
	if (philosopher->meals >= philosopher->settings->musteat)
	{
		pthread_mutex_lock(&philosopher->settings->mutex_musteat);
		philosopher->settings->musteat_max == 1;
		pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
	}
}

void	philosopher_eat(t_philosopher *philosopher)
{
	long	timestamp;
	
	pickup_forks(philosopher);

	// pass timestamp to eating_update
	// use mutex lock for lastmeal!
	timestamp = get_time();
	philosopher_eating_update(philosopher);
	philosopher->lastmeal = timestamp + (philosopher->settings->time2eat);
	if (philosophing_conditions(philosopher))
	{
		printtime(timestamp, philosopher->id, "is eating", philosopher->settings);
		my_wait(philosopher->settings->time2eat);
		drop_forks(philosopher);
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
