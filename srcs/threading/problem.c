/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:23:16 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 21:21:24 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static int         philosophing_conditions(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->settings->mutex_alive);
    if (philosopher->settings->everyone_alive == 0)
        return (0);
    pthread_mutex_unlock(&philosopher->settings->mutex_alive);
    pthread_mutex_lock(&philosopher->settings->mutex_musteat);
    if (philosopher->settings->musteat_max == 1)
        return (0);
    pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
    // and lock mutex on std output
    return (1);
}

void        philosophing(t_philosopher *philosopher)
{
    while (philosophing_conditions(philosopher))
    {
        philosopher_eat(philosopher);
        philosopher_sleep(philosopher);
        philosopher_think(philosopher);
    }
}