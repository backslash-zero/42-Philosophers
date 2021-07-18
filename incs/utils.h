#ifndef UTILS_H
# define UTILS_H

void	free_all(t_settings *settings, t_philosopher *philosopher);
void	free_forks(t_settings *settings);

void	destroy_mutexes(t_settings *settings);
void	destroy_fork_mutexes(t_settings *settings, int n);

void	printtime(int index, char *msg, t_settings *settings);
void	print_eating(t_philosopher *philo);
void	my_wait(long time, t_settings *settings);
long	get_time(t_settings *settings);
int		get_original_time(t_settings *settings);

int		is_even(const int nb);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_conv_num(const char *str);

#endif