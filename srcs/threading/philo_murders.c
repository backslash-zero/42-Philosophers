/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_murders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:41:34 by celestin          #+#    #+#             */
/*   Updated: 2021/07/06 12:41:31 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

// Check if Philos are alive
// create thread that continuously check if everyone alive


// add check for max meals (used on the same thread, no mutex)

// add mutex on "lastmeal" read/write

static int     check_starve(t_philosopher *philosopher)
{
	if (get_time() - philosopher->lastmeal >= philosopher->settings->time2die)
		return (1);
	return (0);
}

static int     check_death(t_philosopher *philosopher)
{
	t_philosopher   *tmp;

	tmp = philosopher;
	while (tmp)
	{
		if (check_starve(tmp) == 1)
		{
			philosopher->settings->everyone_alive = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void    *thread_liveliness_start(void *philosopher_cast)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philosopher_cast;
	while (philosopher->settings->everyone_alive)
	{
		usleep(500);
		check_death(philosopher);
	}
	return (NULL);
}


int		launch_liveliness_check(t_philosopher *philosopher)
{
	int				ret_pthread;
	t_philosopher	*tmp_philo;

	tmp_philo = philosopher;
	ret_pthread = pthread_create(&tmp_philo->settings->tid_liveness_checker, NULL, thread_liveliness_start, (void *)tmp_philo);
	if (ret_pthread != 0)
		return (ft_error("Unable to create thread, see launch_thread function."));
}