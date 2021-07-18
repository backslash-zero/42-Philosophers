/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:52:05 by celestin          #+#    #+#             */
/*   Updated: 2021/07/18 14:09:09 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static void print_status(long time, int index, char *msg)
{
    printf("%ldms\t%d %s\n", time, index, msg);
}

void    print_eating(t_philosopher *philo)
{
    long	time;

    pthread_mutex_lock(&philo->settings->mutex_stdout);
	pthread_mutex_lock(&philo->settings->mutex_alive);
    time = get_time(philo->settings);
    philosopher_update_lastmeal(philo, time);
	if (philo->settings->everyone_alive)
		printf_status(time, philo->id, "is eating");
	pthread_mutex_unlock(&philo->settings->mutex_stdout);
	pthread_mutex_unlock(&philo->settings->mutex_alive);
}

void	printtime(int index, char *msg, t_settings *settings)
{
    long	time;

	pthread_mutex_lock(&settings->mutex_stdout);
	pthread_mutex_lock(&settings->mutex_alive);
    time = get_time(settings);
	if (settings->everyone_alive)
		printf_status(time, index, msg);
	pthread_mutex_unlock(&settings->mutex_stdout);
	pthread_mutex_unlock(&settings->mutex_alive);
}
