/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:58:28 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 20:35:28 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	free_forks(t_settings *settings)
{
	pthread_mutex_t	*tofree;

	tofree = settings->forks;
	free(tofree);
}

static void	free_philosopher(t_philosopher *philosopher)
{
	t_philosopher	*tofree;

	tofree = philosopher;
	pthread_mutex_destroy(&tofree->mutex_lastmeal);
	free(tofree);
}

static void	free_philosophers(t_philosopher *philosopher)
{
	t_philosopher	*next_philosopher;

	next_philosopher = philosopher;
	while (philosopher)
	{
		next_philosopher = philosopher->next;
		free_philosopher(philosopher);
		philosopher = next_philosopher;
	}
}

void	free_all(t_settings *settings, t_philosopher *philosopher)
{
	destroy_mutexes(settings);
	free_forks(settings);
	free_philosophers(philosopher);
	free(settings);
}
