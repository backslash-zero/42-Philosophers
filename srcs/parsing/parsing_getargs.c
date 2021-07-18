/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_getargs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:58:45 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/18 19:16:37 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int	get_number(t_settings *settings, char **av)
{
	if (check_numerical(av[1]) == -1)
		return (-1);
	settings->number = ft_conv_num(av[1]);
	if (settings->number <= 0)
		return (-1);
	return (0);
}

int	get_time2die(t_settings *settings, char **av)
{
	if (check_numerical(av[2]) == -1)
		return (-1);
	settings->time2die = ft_conv_num(av[2]);
	if (settings->time2die < 0)
		return (-1);
	return (0);
}

int	get_time2eat(t_settings *settings, char **av)
{
	if (check_numerical(av[3]) == -1)
		return (-1);
	settings->time2eat = ft_conv_num(av[3]);
	if (settings->time2eat < 0)
		return (-1);
	return (0);
}

int	get_time2sleep(t_settings *settings, char **av)
{
	if (check_numerical(av[4]) == -1)
		return (-1);
	settings->time2sleep = ft_conv_num(av[4]);
	if (settings->time2sleep < 0)
		return (-1);
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
	settings->musteat = ft_conv_num(av[5]);
	if (settings->musteat <= 0)
		return (-1);
	return (0);
}
