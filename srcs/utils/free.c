/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:58:28 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/29 15:46:39 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static void        free_philosopher(t_philosopher *philosopher)
{
    t_philosopher *tofree;

    tofree = philosopher;
    free(tofree);
}

static void        free_philosophers(t_philosopher *philosopher)
{
    t_philosopher *next_philosopher;

    next_philosopher = philosopher;
    while(philosopher)
    {
        next_philosopher = philosopher->next;
        free_philosopher(philosopher);
        philosopher = next_philosopher;
    }
}

void        free_all(t_philo *philo, t_philosopher *philosopher)
{
    free(philo);
    free_philosophers(philosopher);
}
