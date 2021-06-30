/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:39 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 11:11:56 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

static int     init_struct(t_philo **philo, t_philosopher **philosopher, int ac, char **av)
{
	*philo = malloc(sizeof(t_philo));
	if (!*philo)
		return (-1);
	if (parser(*philo, ac, av) == -1)
		return (-1);
	*philosopher = create_philosophers(*philo);
	if (!*philosopher)
		return (ft_error("Memory allocation problem"));
	return (0);
}

int     main(int ac, char **av)
{
	static  t_philo *philo;
	t_philosopher   *philosopher;

	if (init_struct(&philo, &philosopher, ac, av) == -1)
		return (1);
	if (threading(philo, philosopher) == -1)
		return (1);
	free_all(philo, philosopher);
	return (0);
}
