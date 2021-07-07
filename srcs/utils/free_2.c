/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:59:30 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 20:35:30 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	destroy_fork_mutexes(t_settings *settings, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&settings->forks[i]);
		i++;
	}
}

void	destroy_mutexes(t_settings *settings)
{
	destroy_fork_mutexes(settings, settings->number);
	pthread_mutex_destroy(&settings->mutex_alive);
	pthread_mutex_destroy(&settings->mutex_musteat);
	pthread_mutex_destroy(&settings->mutex_stdout);
}
