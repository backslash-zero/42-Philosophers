/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:39 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/27 19:50:50 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void    thread_start(void *threadid)
{
	long tid;

	tid = (long)threadid;
	printf("Hello World! Thread ID, %d\n", tid);
	pthread_detach(NULL);
}

int     launch_threads(t_philo *philo)
{
	pthread_t threads[philo->number];
	int i;
	int ret_pthread;

	i = 0;
	while (i < philo->number)
	{
		ret_pthread = pthread_create(&threads[i], NULL, thread_start, (void *)i);
		if (ret_pthread != 0)
			return (ft_error("Unable to create thread"));
		i++;
	}
	return (0);

}

int     init_struct(t_philo *philo, int ac, char **av)
{
	if (!(philo = malloc(sizeof(t_philo))))
		return (1);
	if (parser(philo, av, ac) == -1)
		return (1);
	print_struct(philo);
}

int     main(int ac, char **av)
{
	static  t_philo *philo;

	if (init_struct(philo, ac, av) == -1)
		return (1);
	if (launch_threads(philo) == -1)
		return (1);
	free(philo);
	return (0);
}
