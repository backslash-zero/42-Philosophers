/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:50:17 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 13:45:34 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"


t_philosopher		*create_philosophers(t_settings *settings)
{
	t_philosopher   *first_philosopher;
	t_philosopher   *philosopher;
	t_philosopher   *last_philosopher;
	int				i;

	i = 0;
	while (i < settings->number)
	{
		if (!(philosopher = malloc(sizeof(t_philosopher))))
			return (NULL);
		if (i != 0)
			last_philosopher->next = philosopher;
		else
			first_philosopher = philosopher;
		philosopher->id = i + 1;
		philosopher->settings = settings;
		philosopher->next = NULL;
		last_philosopher = philosopher;
		i++;
	}
	return (first_philosopher);
}
