/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 12:08:44 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	philosopher_dies(t_philosopher *philosopher)
{
	philosopher->settings->everyone_alive = 0;
}

void	philosopher_eat(t_philosopher *philosopher)
{
	long	timestamp;
	
	timestamp = get_time();
	printtime(timestamp, philosopher->id, "is eating");
	my_wait(philosopher->settings->time2eat);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	long	timestamp;
	
	timestamp = get_time();
	printtime(timestamp, philosopher->id, "is sleeping");
	my_wait(philosopher->settings->time2sleep);

}

void	philosopher_think(t_philosopher *philosopher)
{
	long	timestamp;
	
	timestamp = get_time();
	printtime(timestamp, philosopher->id, "is thinking");
}
