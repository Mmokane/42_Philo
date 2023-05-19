/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moskir <moskir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:19:57 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/19 17:14:53 by moskir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				id;
	pthread_t		thread;
	struct s_utils	*utils;
	int				done_eating;
	int				he_ate_x_times;
	long long		last_meal;
}	t_philos;

typedef struct s_utils
{
	int				die;
	pthread_mutex_t	mutex1;
	long long		start;
	int				zlayf;
	pthread_mutex_t	mutex2;
	pthread_mutex_t	mutex3;
	pthread_mutex_t	*forks;
	t_philos		*philos;
	pthread_mutex_t	to_print;
	int				real_time;
	int				philos_nb;
	int				dying_time;
	int				eating_time;
	int				sleeping_time;
	int				eat;
	int				meals;
}	t_utils;

void		check_teb(int meals, int zlayf);
void		unlock(t_philos **philo);
void		lock(t_philos **philo);
long long	real_time(void);
void		ft_usleep(int time);
void		*my_life(void	*arg);
int			main(int ac, char **av);
int			ft_atoi(const char *str);
int			philo_init(t_utils *utils);
int			mutexes_init(t_utils *utils);
int			ft_putstr(char *str, int fd);
int			data_destroy(t_utils *utils);
int			threads_starter(t_utils	*utils);
int			utils_init(t_utils *utils, int ac, char **av);
void		death(t_philos *philo);
void		print_action(t_philos *philos, char *str);
void		philo_think(t_philos *philo);
void		philo_sleep(t_philos *philo);
void		philo_eat(t_philos *philo);
int			check_death(t_philos *philo);

#endif
// mutex  == to_eat
// mutex 1 == mutex
// mutex 2 == to_die
