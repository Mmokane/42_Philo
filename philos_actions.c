/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 03:27:10 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/18 05:05:25 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    death(t_philos *philo)
{
	pthread_mutex_lock(&philo->utils->to_print);
	printf("%lld %d died\n", real_time() - philo->utils->start, philo->id);
}

void    print_action(t_philos *philos, char *str)
{
	pthread_mutex_lock(&philos->utils->to_print);
    printf("%lld %d %s\n", real_time() - philos->utils->start, philos->id, str);
	pthread_mutex_unlock(&philos->utils->to_print);
}

void	philo_think(t_philos *philo)
{
	print_action(philo, "is thinking");
}
void	philo_sleep(t_philos *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->utils->sleeping_time);
}

void	philo_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->utils->forks[philo->id - 1]);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->utils->forks[philo->id
		% philo->utils->philos_nb]);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->utils->mutex2);
	philo->last_meal = real_time();
	pthread_mutex_unlock(&philo->utils->mutex2);
	ft_usleep(philo->utils->eating_time);
	pthread_mutex_unlock(&philo->utils->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->utils->forks[philo->id
		% philo->utils->philos_nb]);
}