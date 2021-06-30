/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:23:16 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 11:48:41 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void         philosopher_dies(t_philosopher *philosopher)
{
    philosopher->philo->everyone_alive = 0;
}

int         philosophing_conditions(t_philosopher *philosopher)
{
    if (philosopher->philo->everyone_alive == 0)
        return (0);
    if (philosopher->philo->musteat_max == 1)
        return (0);
    // and lock mutex on std output
    return (1);
}

void        philosophing(t_philosopher *philosopher)
{
    while (philosophing_conditions(philosopher))
    {
        philo_eat(philosopher);
        philo_sleep(philosopher);
        philo_think(philosopher);
    }
}