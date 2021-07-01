/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:39 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/01 16:47:27 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

static void			assign_forks(t_settings *settings, t_philosopher *philosopher)
{
	int 			i;
	t_philosopher	*to_assign;

	to_assign = philosopher;
	i = 0;
	while (i < settings->number)
	{
		to_assign->fork_left = &settings->forks[i];
		printf("Asssigning Philo-%d with LEFT	fork	%d\n", to_assign->id, i);
		if (i != 0)
		{
			to_assign->fork_right = &settings->forks[i - 1];
			printf("Asssigning Philo-%d with RIGHT	fork	%d\n", to_assign->id, i - 1);
		}
		else
		{
			to_assign->fork_right = &settings->forks[settings->number - 1];
			printf("Asssigning Philo-%d with RIGHT	fork	%d\n", to_assign->id, settings->number - 1);
		}
		i++;
		to_assign = to_assign->next;
	}
}


static int     init_struct(t_settings **settings, t_philosopher **philosopher, int ac, char **av)
{
	*settings = malloc(sizeof(t_settings));
	if (!*settings)
		return (-1);
	if (parser(*settings, ac, av) == -1)
		return (-1);
	*philosopher = create_philosophers(*settings);
	if (!*philosopher)
		return (ft_error("Memory allocation problem"));
	assign_forks(*settings, *philosopher);
	return (0);
}

int     main(int ac, char **av)
{
	static  t_settings *settings;
	t_philosopher   *philosopher;

	if (init_struct(&settings, &philosopher, ac, av) == -1)
		return (1);
	if (threading(settings, philosopher) == -1)
		return (1);
	free_all(settings, philosopher);
	return (0);
}
