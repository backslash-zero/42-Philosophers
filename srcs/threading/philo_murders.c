/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_murders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:41:34 by celestin          #+#    #+#             */
/*   Updated: 2021/07/06 18:46:45 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static int     check_starve(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->mutex_lastmeal);
	if ((long)get_time() - philosopher->lastmeal >= (long)philosopher->settings->time2die)
	{
		printf("lastmeal = %ld\n", philosopher->lastmeal);
		printf("(double)get_time() - (double)philosopher->lastmeal = %ld\n", (long)get_time() - philosopher->lastmeal);
		printf("philosopher->settings->time2die = %ld\n", (long)philosopher->settings->time2die);
		pthread_mutex_unlock(&philosopher->mutex_lastmeal);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->mutex_lastmeal);
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
			printf("!Philo-%d is starving\n", tmp->id);
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

	debug_message("Launched livelinesss thread");
	philosopher = (t_philosopher *)philosopher_cast;
	while (philosophing_conditions(philosopher))
	{
		usleep(500);
		check_death(philosopher);
	}
	debug_message("Exited livelinesss thread");
	printf("Everyone alive; %d\nmusteat_max; %d\n",philosopher->settings->everyone_alive, philosopher->settings->musteat_max);
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