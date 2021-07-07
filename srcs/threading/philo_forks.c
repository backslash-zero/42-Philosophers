/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:23:38 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 18:23:57 by cmeunier         ###   ########.fr       */
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
