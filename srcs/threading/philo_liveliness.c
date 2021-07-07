/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_liveliness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:41:34 by celestin          #+#    #+#             */
/*   Updated: 2021/07/07 17:07:09 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static int     check_musteat(t_philosopher *philosopher)
{
	t_philosopher   *tmp;

	tmp = philosopher;
	while (tmp)
	{
		if (tmp->meals < tmp->settings->musteat)
			return (0);
		tmp = tmp->next;
	}
	pthread_mutex_lock(&philosopher->settings->mutex_musteat);
	philosopher->settings->musteat_max = 1;
	pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
	return (1);
}

static int     check_starve(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->mutex_lastmeal);
	if ((long)get_time() - philosopher->lastmeal >= (long)philosopher->settings->time2die)
	{
		pthread_mutex_unlock(&philosopher->mutex_lastmeal);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->mutex_lastmeal);
	return (0);
}

static void     check_death(t_philosopher *philosopher)
{
	t_philosopher   *tmp;

	tmp = philosopher;
	while (tmp)
	{
		if (check_starve(tmp) == 1)
		{
			philosopher->settings->everyone_alive = 0;
			printtime(get_time(), tmp->id, "died", philosopher->settings);
			break;
		}
		tmp = tmp->next;
	}
}

static void    *thread_liveliness_start(void *philosopher_cast)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philosopher_cast;
	while (philosophing_conditions(philosopher))
	{
		usleep(500);
		check_death(philosopher);
		if (philosopher->settings->option)
			check_musteat(philosopher);
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
	return (0);
}