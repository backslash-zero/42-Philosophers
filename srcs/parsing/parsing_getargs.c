/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_getargs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:58:45 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/28 12:03:46 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int         get_number(t_philo *philo, char **av)
{
	if (check_numerical(av[1]) == -1)
		return (-1);
	philo->number = ft_atoi(av[1]);
	if (philo->number <= 0)
		return (-1);
	return (0);
}

int         get_time2die(t_philo *philo, char **av)
{
	if (check_numerical(av[2]) == -1)
		return (-1);
	philo->time2die = ft_atoi(av[2]);
	return (0);
}

int         get_time2eat(t_philo *philo, char **av)
{
	if (check_numerical(av[3]) == -1)
		return (-1);
	philo->time2eat = ft_atoi(av[3]);
	return (0);
}
int         get_time2sleep(t_philo *philo, char **av)
{
	if (check_numerical(av[4]) == -1)
		return (-1);
	philo->time2sleep = ft_atoi(av[4]);
	return (0);
}

int         get_musteat(t_philo *philo, int ac, char **av)
{
	if (ac == 5)
	{
		philo->option = 0;
		philo->musteat = 0;
		return (0);
	}
	if (check_numerical(av[5]) == -1)
		return (-1);
	philo->option = 1;
	philo->musteat = ft_atoi(av[5]);
	return (0);
}