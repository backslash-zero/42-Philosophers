#ifndef THREADS_H
# define THREADS_H

# include "parsing.h"

void	philosopher_dies(t_philosopher *philosopher);
void	philosopher_eat(t_philosopher *philosopher);
void	philosopher_sleep(t_philosopher *philosopher);
void	philosopher_think(t_philosopher *philosopher);

int     philosophing_conditions(t_philosopher *philosopher);
void    philosophing(t_philosopher *philosopher);

int     threading(t_settings *settings, t_philosopher *philosopher);

#endif