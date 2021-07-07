#ifndef UTILS_H
# define UTILS_H

void	free_all(t_settings *settings, t_philosopher *philosopher);

void	printtime(long time, int index, char *msg, t_settings *settings);
void	my_wait(long time);
long	get_time(void);

int		ft_atoi(const char *str);
int		is_even(const int nb);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif