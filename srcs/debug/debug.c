/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:54:41 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 17:41:29 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	debug_message(char *str)
{
	printf("\033[0;36m");
	printf("Debug info: %s\n", str);
	printf("\033[0m");
}

void	debug_print_settings(t_settings *settings)
{
	printf("\033[0;33m");
	printf("Struct settings status:\n");
	printf("number: %d\n", settings->number);
	printf("time2die: %d\n", settings->time2die);
	printf("time2eat: %d\n", settings->time2eat);
	printf("time2sleep: %d\n", settings->time2sleep);
	printf("option: %d\n", settings->option);
	printf("musteat: %d\n", settings->musteat);
	printf("everyone_alive: %d\n", settings->everyone_alive);
	printf("musteat_max: %d\n", settings->musteat_max);
	printf("\033[0m");
}

void	debug_print_philosopher(t_philosopher *philosopher)
{
	printf("\033[0;36m");
	printf("Struct philosopher:\n");
	printf("id:         %d\n", philosopher->id);
	printf("meals:      %d\n", philosopher->meals);
	printf("lastmeal:   %ld\n", philosopher->lastmeal);
	printf("\033[0m");
}
