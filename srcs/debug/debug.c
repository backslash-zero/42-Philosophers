/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:54:41 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/27 17:17:17 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void    print_struct(t_philo *philo)
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