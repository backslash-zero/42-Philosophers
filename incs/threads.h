#ifndef THREADS_H
# define THREADS_H

# include "parsing.h"

void	*thread_start(void *philosopher_cast);
int		join_threads(const t_philosopher *philosopher);
int		launch_threads(const t_philo *philo, const t_philosopher *philosopher);
int		threading(const t_philo *philo, const t_philosopher *philosopher);

#endif