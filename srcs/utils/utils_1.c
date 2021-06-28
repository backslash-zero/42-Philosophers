/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:37:04 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/28 13:06:16 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

int		ft_atoi(const char *str)
{
	int value;
	int isneg;

	value = 0;
	isneg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		isneg = (*str == '-' ? 1 : 0);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += 48 - *str;
		str++;
	}
	return (isneg ? value : -value);
}
