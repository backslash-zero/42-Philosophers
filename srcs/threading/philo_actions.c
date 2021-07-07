/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 18:23:54 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	philosopher_update_lastmeal(t_philosopher *philo, double timestamp)
{
	pthread_mutex_lock(&philo->mutex_lastmeal);
	philo->lastmeal = timestamp;
	pthread_mutex_unlock(&philo->mutex_lastmeal);
}

void	philosopher_eat(t_philosopher *philo)
{
	long	time;

	pickup_forks(philo);
	time = get_time();
	philosopher_update_lastmeal(philo, time);
	if (philosophing_conditions(philo))
	{
		printtime(time, philo->id, "is eating", philo->settings);
		my_wait(philo->settings->time2eat);
		drop_forks(philo);
		philosopher_update_lastmeal(philo, time + philo->settings->time2eat);
		philo->meals += 1;
	}
	else
		drop_forks(philo);
}

void	philosopher_sleep(t_philosopher *philo)
{
	long	timestamp;

	timestamp = get_time();
	if (philosophing_conditions(philo))
	{
		printtime(timestamp, philo->id, "is sleeping", philo->settings);
		my_wait(philo->settings->time2sleep);
	}
}

void	philosopher_think(t_philosopher *philo)
{
	long	timestamp;

	timestamp = get_time();
	if (philosophing_conditions(philo))
		printtime(timestamp, philo->id, "is thinking", philo->settings);
}
