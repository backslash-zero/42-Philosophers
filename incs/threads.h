#ifndef THREADS_H
# define THREADS_H

# include "parsing.h"

void	philosopher_dies(t_philosopher *philosopher);
void	philosopher_update_lastmeal(t_philosopher *philo, double timestamp);
void	philosopher_eat(t_philosopher *philosopher);
void	philosopher_sleep(t_philosopher *philosopher);
void	philosopher_think(t_philosopher *philosopher);

int		philosophing_conditions(t_philosopher *philosopher);
void	philosophing(t_philosopher *philosopher);

void	drop_forks(t_philosopher *philosopher);
void	pickup_forks(t_philosopher *philosopher);

int		launch_liveliness_check(t_philosopher *philosopher);

int		threading(t_settings *settings, t_philosopher *philosopher);

#endif