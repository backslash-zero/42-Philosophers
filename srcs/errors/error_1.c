/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:03:15 by cmeunier          #+#    #+#             */
/*   Updated: 2021/07/07 17:42:13 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/philosophers.h"

void	*ft_error_null(char *str)
{
	printf("\033[0;31mError:\033[0m %s\n", str);
	return (NULL);
}

int	ft_error(char *str)
{
	printf("\033[0;31mError:\033[0m %s\n", str);
	return (-1);
}
