/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:14:34 by celestin          #+#    #+#             */
/*   Updated: 2021/07/18 13:52:38 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

static long	convert_time(long value, const char *type)
{
	if (!ft_strncmp(type, "seconds", ft_strlen("seconds")))
		return (value * 1000);
	if (!ft_strncmp(type, "microseconds", ft_strlen("microseconds")))
		return (value / 1000);
	return (0);
}

int	get_original_time(t_settings *settings)
{
	struct timeval	original_time;
	int				ret_gettime;

	ret_gettime = gettimeofday(&original_time, NULL);
	if (ret_gettime != 0)
		return (ft_error("Overflow: gettimeofday() returned nonzero."));
	settings->original_time = convert_time(original_time.tv_sec, "seconds")
		+ convert_time(original_time.tv_usec, "microseconds");
	return (0);
}

long	get_time(t_settings *settings)
{
	struct timeval	current_time;
	int				ret_gettime;

	ret_gettime = gettimeofday(&current_time, NULL);
	if (ret_gettime != 0)
		return ((long)ft_error("Overflow: gettimeofday() returned nonzero."));
	return (convert_time(current_time.tv_sec, "seconds")
		+ convert_time(current_time.tv_usec, "microseconds")
		- settings->original_time);
}

void	my_wait(long time, t_settings *settings)
{
	long	timestamp;

	timestamp = get_time(settings);
	while (get_time(settings) < timestamp + time)
		usleep(500);
}
