/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:50:17 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 18:34:14 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

t_philosopher	*create_philosophers(t_settings *settings)
{
	t_philosopher	*first_philosopher;
	t_philosopher	*philosopher;
	t_philosopher	*last_philosopher;
	int				i;

	i = 0;
	while (i < settings->number)
	{
		philosopher = malloc(sizeof(t_philosopher));
		if (!philosopher)
			return ((t_philosopher *)ft_error_null("Malloc has failed"));
		if (i != 0)
			last_philosopher->next = philosopher;
		else
			first_philosopher = philosopher;
		philosopher->id = i + 1;
		philosopher->meals = 0;
		philosopher->settings = settings;
		if (pthread_mutex_init(&philosopher->mutex_lastmeal, NULL) != 0)
			return ((t_philosopher *)ft_error_null("Mutex init has failed"));
		philosopher->next = NULL;
		last_philosopher = philosopher;
		i++;
	}
	return (first_philosopher);
}
