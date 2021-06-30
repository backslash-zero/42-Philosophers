/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:47 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 21:15:07 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"


static int 	init_othermutexes(t_settings *settings)
{
	if (pthread_mutex_init(&settings->mutex_alive, NULL) != 0)
		return (ft_error("Mutex init has failed"));
	if (pthread_mutex_init(&settings->mutex_musteat, NULL) != 0)
		return (ft_error("Mutex init has failed"));
	if (pthread_mutex_init(&settings->mutex_stdout, NULL) != 0)
		return (ft_error("Mutex init has failed"));
	return (0);
}
static int 	init_forks(t_settings *settings)
{
	pthread_mutex_t *forks;
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

static int 	get_forks(t_settings *settings)
{
	if (init_forks(settings) == -1)
		return (-1);
	return (0);
}

static	int			get_philo(t_settings *settings, int ac, char **av)
{
	if (get_number(settings, av) == -1)
		return (ft_error("arg \"number_of_philosophers\" invalid"));
	if (get_time2die(settings, av) == -1)
		return (ft_error("arg \"time_to_die\" invalid"));
	if (get_time2eat(settings, av) == -1)
		return (ft_error("arg \"time_to_eat\" invalid"));
	if (get_time2sleep(settings, av) == -1)
		return (ft_error("arg \"time_to_sleep\" invalid"));
	if (get_musteat(settings, ac, av) == -1)
		return (ft_error("Optional arg \"number_of_times_each_philosopher_must_eat\" invalid"));
	settings->everyone_alive = 1;
	settings->musteat_max = 0;
	return (0);
}

static int         check_ac(int ac)
{
	if (ac != 5 && ac != 6)
		return (ft_error("Wrong number of arguments"));
	return (0);
}

int         parser(t_settings *settings, int ac, char **av)
{
	if (check_ac(ac) == -1)
		return (-1);
	if (get_philo(settings, ac, av) == -1)
		return (-1);
	if (get_forks(settings) == -1)
		return (-1);
	if (init_othermutexes(settings) == -1)
		return (-1);
	return (0);
}
