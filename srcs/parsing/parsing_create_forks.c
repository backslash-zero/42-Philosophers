/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_forks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:17:35 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/09 14:20:18 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static int	init_forks(t_settings *settings)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * settings->number);
	if (forks == NULL)
		return (ft_error("Memory allocation problem"));
	i = 0;
	while (i < settings->number)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (ft_error("Mutex init has failed"));
		i++;
	}
	settings->forks = forks;
	return (0);
}

int	get_forks(t_settings *settings)
{
	int	ret;

	ret = init_forks(settings);
	if (ret != 0)
	{
		destroy_fork_mutexes(settings, ret);
		return (-1);
	}
	return (0);
}
