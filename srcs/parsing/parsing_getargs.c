/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_getargs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:58:45 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 18:33:00 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int	get_number(t_settings *settings, char **av)
{
	if (check_numerical(av[1]) == -1)
		return (-1);
	settings->number = ft_atoi(av[1]);
	if (settings->number <= 0)
		return (-1);
	return (0);
}

int	get_time2die(t_settings *settings, char **av)
{
	if (check_numerical(av[2]) == -1)
		return (-1);
	settings->time2die = ft_atoi(av[2]);
	return (0);
}

int	get_time2eat(t_settings *settings, char **av)
{
	if (check_numerical(av[3]) == -1)
		return (-1);
	settings->time2eat = ft_atoi(av[3]);
	return (0);
}

int	get_time2sleep(t_settings *settings, char **av)
{
	if (check_numerical(av[4]) == -1)
		return (-1);
	settings->time2sleep = ft_atoi(av[4]);
	return (0);
}

int	get_musteat(t_settings *settings, int ac, char **av)
{
	if (ac == 5)
	{
		settings->option = 0;
		settings->musteat = 0;
		return (0);
	}
	if (check_numerical(av[5]) == -1)
		return (-1);
	settings->option = 1;
	settings->musteat = ft_atoi(av[5]);
	return (0);
}
