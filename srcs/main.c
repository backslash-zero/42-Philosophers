/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:22:39 by cmeunier          #+#    #+#             */
/*   Updated: 2021/06/27 17:25:32 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int     main(int av, char **ac)
{
    static  t_philo *philo;

    if (!(philo = malloc(sizeof(t_philo))))
        return (1);
    if (parser(philo, av, ac) == -1)
        return (1);
    print_struct(philo);
    free(philo);
    return (0);
}
