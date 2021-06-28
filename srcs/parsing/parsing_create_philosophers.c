/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:50:17 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/28 13:31:38 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"


t_philosopher		*create_philosophers(t_philo *philo)
{
	t_philosopher   *first_philosopher;
	t_philosopher   *philosopher;
	t_philosopher   *last_philosopher;
	int				i;

	i = 0;
	printf("Create philosophers: %d\n", philo->number);
	while (i < philo->number)
	{
		printf("Create philosopher %d\n", i);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		if (!(philosopher = malloc(sizeof(t_philosopher))))
			return (NULL);
		if (i != 0)
			last_philosopher->next = philosopher;
		else
			first_philosopher = philosopher;
		philosopher->id = i + 1;
		philosopher->philo = philo;
		philosopher->next = NULL;
		last_philosopher = philosopher;
		i++;
	}
	return (first_philosopher);
}
