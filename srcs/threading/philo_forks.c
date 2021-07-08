/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:23:38 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/08 15:54:19 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	drop_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
}

void	pickup_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printtime(get_time(philo->settings), philo->id, "has taken a fork", philo->settings);
	pthread_mutex_lock(philo->fork_right);
	printtime(get_time(philo->settings), philo->id, "has taken a fork", philo->settings);
}
