/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:39 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/28 13:38:31 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void    *thread_start(void *philosopher_cast)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philosopher_cast;
	debug_print_philosopher(philosopher);
	return (NULL);
}

int		launch_threads(t_philo *philo)
{
	pthread_t 		tid;
	int 			i;
	int				ret_pthread;
	t_philosopher   *philosopher;

	printf("launching threads\n");
	i = 0;
	if (!(philosopher = create_philosophers(philo)))
		return (ft_error("Memory allocation problem"));
	printf("philosophers created\n");
	while (i < philo->number)
	{
		debug_print_philosopher(philosopher);
		ret_pthread = pthread_create(&tid, NULL, thread_start, (void *)philosopher);
		if (ret_pthread != 0)
			return (ft_error("Unable to create thread, see launch_thread function."));
		i++;
		philosopher = philosopher->next;
	}
	return (0);
}

int     init_struct(t_philo **philo, int ac, char **av)
{
	if (!(*philo = malloc(sizeof(t_philo))))
		return (-1);
	if (parser(*philo, ac, av) == -1)
		return (-1);
	return (0);
}

int     main(int ac, char **av)
{
	static  t_philo *philo;

	if (init_struct(&philo, ac, av) == -1)
		return (1);
	debug_print_philo(philo);
	if (launch_threads(philo) == -1)
		return (1);
	free(philo);
	return (0);
}
