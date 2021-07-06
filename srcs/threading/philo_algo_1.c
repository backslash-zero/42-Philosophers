/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algo_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:23:16 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/06 12:48:45 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int         philosophing_conditions(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->settings->mutex_alive);
    if (philosopher->settings->everyone_alive == 0)
        return (0);
    pthread_mutex_unlock(&philosopher->settings->mutex_alive);
    pthread_mutex_lock(&philosopher->settings->mutex_musteat);
    if (philosopher->settings->musteat_max == 1)
        return (0);
    pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
    return (1);
}

void        philosophing(t_philosopher *philosopher)
{
    if (is_even(philosopher->id))
        usleep(300);
    while (philosophing_conditions(philosopher))
    {
        printf("Run of philsophing while loop thread: %d\n", philosopher->id);
        philosopher_eat(philosopher);
        philosopher_sleep(philosopher);
        philosopher_think(philosopher);
    }
}