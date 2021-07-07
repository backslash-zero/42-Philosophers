/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 13:45:34 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	drop_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
}

void	pickup_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->fork_left);
	pthread_mutex_lock(philosopher->fork_right);
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
	pthread_mutex_lock(&philosopher->mutex_lastmeal);
	philosopher->lastmeal = timestamp;
	pthread_mutex_unlock(&philosopher->mutex_lastmeal);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	long	timestamp;
	
	pickup_forks(philosopher);
	timestamp = get_time();
	philosopher_update_lastmeal(philosopher, timestamp);
	if (philosophing_conditions(philosopher))
	{
		printtime(timestamp, philosopher->id, "is eating", philosopher->settings);
		my_wait(philosopher->settings->time2eat);
		drop_forks(philosopher);
		philosopher_update_lastmeal(philosopher, timestamp + philosopher->settings->time2eat);
		philosopher->meals += 1;
	}
	else
		drop_forks(philosopher);
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
