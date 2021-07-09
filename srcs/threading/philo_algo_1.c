/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algo_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:23:16 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/09 14:21:22 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int	philosophing_conditions(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->settings->mutex_alive);
	if (philosopher->settings->everyone_alive == 0)
	{
		pthread_mutex_unlock(&philosopher->settings->mutex_alive);
		return (0);
	}
	pthread_mutex_unlock(&philosopher->settings->mutex_alive);
	pthread_mutex_lock(&philosopher->settings->mutex_musteat);
	if (philosopher->settings->musteat_max == 1)
	{
		pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
		return (0);
	}
	pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
	return (1);
}

static void	unique_philo(t_philosopher *philo)
{
	if (philo->settings->number == 1)
	{
		printtime(get_time(philo->settings),
			philo->id, "has taken a fork",
			philo->settings);
		my_wait(philo->settings->time2die, philo->settings);
		usleep(300);
		pthread_mutex_lock(&philo->settings->mutex_alive);
		philo->settings->everyone_alive = 0;
		pthread_mutex_unlock(&philo->settings->mutex_alive);
	}
}

void	philosophing(t_philosopher *philosopher)
{
	philosopher->lastmeal = get_time(philosopher->settings);
	if (is_even(philosopher->id))
		usleep(300);
	unique_philo(philosopher);
	while (philosophing_conditions(philosopher))
	{
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
}
