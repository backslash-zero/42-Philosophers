#ifndef UTILS_H
# define UTILS_H

void	free_all(t_settings *settings, t_philosopher *philosopher);

void	my_wait(long time);

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif