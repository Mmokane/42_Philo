/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_creat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:05:45 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/10 19:21:48 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int        ph_creat(int ac, char **av, t_flsf **philo, t_utils *utils)
{
    int i;

    utils->philos_size = sizeof(t_flsf) * utils->philo_nb;
    t_flsf *philo = malloc(utils->philos_size);
    if (!philo)
        return (1);
}