/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/18 19:01:19 by cmeunier         ###   ########.fr       */
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
	pickup_forks(philo);
	if (philosophing_conditions(philo))
	{
		print_eating(philo);
		my_wait(philo->settings->time2eat, philo->settings);
		drop_forks(philo);
		philo->meals += 1;
	}
	else
		drop_forks(philo);
}

void	philosopher_sleep(t_philosopher *philo)
{
	if (philosophing_conditions(philo))
	{
		printtime(philo->id, "is sleeping", philo->settings);
		my_wait(philo->settings->time2sleep, philo->settings);
	}
}

void	philosopher_think(t_philosopher *philo)
{
	if (philosophing_conditions(philo))
		printtime(philo->id, "is thinking", philo->settings);
}
