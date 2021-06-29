/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:14:34 by celestin          #+#    #+#             */
/*   Updated: 2021/06/29 18:53:14 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static convert_time(long value, char *type)
{
	if (type == "seconds")
		return (value * 1000);
	if (type == "microseconds")
		return (value / 1000);
}

long	get_time(void)
{
	struct timeval	current_time;
	int 			ret_gettime;          
	ret_gettime = gettimeofday(&current_time, DST_WET);
	if (ret_gettime != 0)
		return ((long)ft_error("Overflow occured, gettimeofday() returned nonzero."));
	return (convert_time(current_time.tv_sec, "seconds")
		+ convert_time(current_time.tv_usec, "microseconds"));
}

void	my_wait(long time)
{
	long timestamp;

	timestamp = get_time();
	if (timestamp == -1)
		return (-1);
	while (get_time() < timestamp + time)
		usleep(500);
	return (0);
}