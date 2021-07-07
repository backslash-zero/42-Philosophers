/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algo_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:23:16 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 13:48:27 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int         philosophing_conditions(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->settings->mutex_alive);
    if (philosopher->settings->everyone_alive == 0)
    {
        printf("Philo-%d every1 alive failed!\n", philosopher->id);
        pthread_mutex_unlock(&philosopher->settings->mutex_alive);
        return (0);
    }
    pthread_mutex_unlock(&philosopher->settings->mutex_alive);
    pthread_mutex_lock(&philosopher->settings->mutex_musteat);
    if (philosopher->settings->musteat_max == 1)
    {
        printf("Philo-%d musteat failed!: ate %d times\n", philosopher->id, philosopher->meals);
        pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
        return (0);
    }
    pthread_mutex_unlock(&philosopher->settings->mutex_musteat);
    return (1);
}

void        philosophing(t_philosopher *philosopher)
{
    philosopher->lastmeal = get_time();
    if (is_even(philosopher->id))
        usleep(300);
    while (philosophing_conditions(philosopher))
    {
        philosopher_eat(philosopher);
        philosopher_sleep(philosopher);
        philosopher_think(philosopher);
    }
}