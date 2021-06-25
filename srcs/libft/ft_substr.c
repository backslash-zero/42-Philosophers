/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:18:40 by cmeunier          #+#    #+#             */
/*   Updated: 2020/06/10 23:19:59 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_calloc(1, 1));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
