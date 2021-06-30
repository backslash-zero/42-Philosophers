/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:14:34 by celestin          #+#    #+#             */
/*   Updated: 2021/06/30 21:16:17 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	printtime(long timestamp, int philo_index, char *msg, t_settings *settings)
{
	pthread_mutex_lock(&settings->mutex_stdout);
	printf("%ld %d %s\n", timestamp, philo_index, msg);
	pthread_mutex_unlock(&settings->mutex_stdout);
}

static long convert_time(long value, const char *type)
{
	if (!ft_strncmp(type, "seconds", ft_strlen("seconds")))
		return (value * 1000);
	if (!ft_strncmp(type, "microseconds", ft_strlen("microseconds")))
		return (value / 1000);
	return (0);
}

long	get_time(void)
{
	struct timeval	current_time;
	int 			ret_gettime;          
	ret_gettime = gettimeofday(&current_time, NULL);
	if (ret_gettime != 0)
		return ((long)ft_error("Overflow occured, gettimeofday() returned nonzero."));
	return (convert_time(current_time.tv_sec, "seconds")
		+ convert_time(current_time.tv_usec, "microseconds"));
}

void	my_wait(long time)
{
	long timestamp;

	timestamp = get_time();
	while (get_time() < timestamp + time)
		usleep(500);
}
