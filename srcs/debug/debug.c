/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:54:41 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/30 12:08:29 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void    debug_print_settings(t_settings *settings)
{
    printf("Struct settings status:\n");
    printf("number: %d\n", settings->number);
    printf("time2die: %d\n", settings->time2die);
    printf("time2eat: %d\n", settings->time2eat);
    printf("time2sleep: %d\n", settings->time2sleep);
    printf("option: %d\n", settings->option);
    printf("musteat: %d\n", settings->musteat);
    printf("everyone_alive: %d\n", settings->everyone_alive);
}

void    debug_print_philosopher(t_philosopher *philosopher)
{
    printf("Struct philosopher status:\n");
    printf("id: %d\n", philosopher->id);
    printf("number: %d\n", philosopher->settings->number);
    printf("time2die: %d\n", philosopher->settings->time2die);
    printf("time2eat: %d\n", philosopher->settings->time2eat);
    printf("time2sleep: %d\n", philosopher->settings->time2sleep);
    printf("option: %d\n", philosopher->settings->option);
    printf("musteat: %d\n", philosopher->settings->musteat);
    printf("everyone_alive: %d\n", philosopher->settings->everyone_alive);
}