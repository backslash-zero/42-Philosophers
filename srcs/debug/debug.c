/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:54:41 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/28 13:44:53 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void    debug_print_philo(t_philo *philo)
{
    printf("Struct philo status:\n");
    printf("number: %d\n", philo->number);
    printf("time2die: %d\n", philo->time2die);
    printf("time2eat: %d\n", philo->time2eat);
    printf("time2sleep: %d\n", philo->time2sleep);
    printf("option: %d\n", philo->option);
    printf("musteat: %d\n", philo->musteat);
    printf("everyone_alive: %d\n", philo->everyone_alive);
}

void    debug_print_philosopher(t_philosopher *philosopher)
{
    printf("Struct philosopher status:\n");
    printf("id: %d\n", philosopher->id);
    printf("number: %d\n", philosopher->philo->number);
    printf("time2die: %d\n", philosopher->philo->time2die);
    printf("time2eat: %d\n", philosopher->philo->time2eat);
    printf("time2sleep: %d\n", philosopher->philo->time2sleep);
    printf("option: %d\n", philosopher->philo->option);
    printf("musteat: %d\n", philosopher->philo->musteat);
    printf("everyone_alive: %d\n", philosopher->philo->everyone_alive);
}