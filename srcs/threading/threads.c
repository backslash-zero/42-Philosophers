/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:00:56 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/01 16:22:13 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static void    *thread_start(void *philosopher_cast)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philosopher_cast;
	printf("Start of the thread%d\n", philosopher->id);
	philosophing(philosopher);
	return (NULL);
}

static int		join_threads(t_philosopher *philosopher)
{
	t_philosopher *tmp = philosopher;
	int	ret_join;

	while (tmp)
	{
		ret_join = pthread_join(tmp->tid, NULL);
		if (ret_join != 0)
			return (ft_error("There was a problem joining a thread."));
		tmp = tmp->next;
	}
	return (0);
}

static int		launch_threads(const t_settings *settings, t_philosopher *philosopher)
{
	int 			i;
	int				ret_pthread;
	t_philosopher	*tmp_philo;
	
	i = 0;
	tmp_philo = philosopher;
	while (i < settings->number)
	{
		ret_pthread = pthread_create(&tmp_philo->tid, NULL, thread_start, (void *)tmp_philo);
		if (ret_pthread != 0)
			return (ft_error("Unable to create thread, see launch_thread function."));
		i++;
		tmp_philo = tmp_philo->next;
	}
	return (0);
}

int     threading(t_settings *settings, t_philosopher *philosopher)
{
	if (launch_threads(settings, philosopher) == -1)
		return (-1);
	if (join_threads(philosopher) == -1)
		return (-1);
	return (0);
}