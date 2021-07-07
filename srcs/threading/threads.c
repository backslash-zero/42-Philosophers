/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:00:56 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 18:05:06 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static void	*thread_start(void *philosopher_cast)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)philosopher_cast;
	philosophing(philosopher);
	return (NULL);
}

static int	join_threads(t_philosopher *philosopher)
{
	t_philosopher	*tmp;
	int				ret_join;

	tmp = philosopher;
	while (tmp)
	{
		ret_join = pthread_join(tmp->tid, NULL);
		if (ret_join != 0)
			return (ft_error("There was a problem joining a thread."));
		tmp = tmp->next;
	}
	ret_join = pthread_join(philosopher->settings->tid_liveness_checker, NULL);
	if (ret_join != 0)
		return (ft_error("There was a problem joining a thread."));
	return (0);
}

static int	launch_threads(const t_settings *s, t_philosopher *philosopher)
{
	int				i;
	int				ret;
	t_philosopher	*tmp;

	i = 0;
	tmp = philosopher;
	while (i < s->number)
	{
		ret = pthread_create(&tmp->tid, NULL, thread_start, (void *)tmp);
		if (ret != 0)
			return (ft_error("Unable to create thread."));
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	threading(t_settings *settings, t_philosopher *philosopher)
{
	if (launch_threads(settings, philosopher) == -1)
		return (-1);
	if (launch_liveliness_check(philosopher) == -1)
		return (-1);
	if (join_threads(philosopher) == -1)
		return (-1);
	return (0);
}
