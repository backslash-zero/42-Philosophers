/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:39 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/08 16:55:53 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

static void	assign_forks(t_settings *settings, t_philosopher *philosopher)
{
	t_philosopher	*to_assign;

	to_assign = philosopher;
	while (to_assign)
	{
		to_assign->fork_left = &settings->forks[to_assign->id - 1];
		if (to_assign->id != 1 && settings->number != 1)
			to_assign->fork_right = &settings->forks[to_assign->id - 2];
		else
			to_assign->fork_right = &settings->forks[settings->number - 1];
		to_assign = to_assign->next;
	}
}

static int	init_struct(t_settings **s, t_philosopher **phil, int ac, char **av)
{
	*s = malloc(sizeof(t_settings));
	if (!*s)
		return (-1);
	if (parser(*s, ac, av) == -1)
	{
		free(*s);
		return (-1);
	}
	*phil = create_philosophers(*s);
	if (!*phil)
	{
		destroy_mutexes(*s);
		free_forks(*s);
		free(*s);
		return (ft_error("Problem creating philosophers :("));
	}
	assign_forks(*s, *phil);
	return (0);
}

int	main(int ac, char **av)
{
	static t_settings	*settings;
	t_philosopher		*philosopher;

	if (init_struct(&settings, &philosopher, ac, av) == -1)
		return (1);
	if (threading(settings, philosopher) == -1)
	{	
		return (1);
		free_all(settings, philosopher);
	}
	usleep(300);
	free_all(settings, philosopher);
	return (0);
}
