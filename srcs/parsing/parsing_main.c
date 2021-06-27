/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:47 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/27 16:38:09 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int         get_philo(t_philo philo, int ac, char **av)
{
	if (get_number(philo, av) == -1)
		return (ft_error("arg \"number_of_philosophers\" invalid"));
	if (get_time2die(philo, av) == -1)
		return (ft_error("arg \"time_to_die\" invalid"));
	if (get_time2eat(philo, av) == -1)
		return (ft_error("arg \"time_to_eat\" invalid"));
	if (get_time2eat(philo, av) == -1)
		return (ft_error("arg \"time_to_sleep\" invalid"));
	if (get_musteat(philo, ac, av) == -1)
		return (ft_error("Optional arg \"number_of_times_each_philosopher_must_eat\" invalid"));
	philo.everyone_alive = 1;
	return (0);
}

int         check_ac(int ac)
{
	if (ac != 5 && ac != 6)
		return (ft_error("Wrong number of arguments"));
	return (0);
}

int         parser(t_philo philo, int ac, char **av)
{
	if (check_ac(ac) == -1)
		return (-1);
	if (get_philo(philo, ac, av) == -1)
		return (-1);
	return (0);
}