#ifndef PARSING_H
# define PARSING_H

typedef struct s_settings
{
	int						number;
	pthread_t				tid_liveness_checker;
	int						time2die;
	int						time2eat;
	int						time2sleep;
	int						option;
	int						musteat;
	int						everyone_alive;
	pthread_mutex_t			mutex_alive;
	int						musteat_max;
	pthread_mutex_t			mutex_musteat;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_stdout;
	long					original_time;
}							t_settings;

typedef struct s_philosopher
{
	int						id;
	pthread_t				tid;
	long					lastmeal;
	pthread_mutex_t			mutex_lastmeal;
	int						meals;
	t_settings				*settings;
	struct s_philosopher	*next;
	pthread_mutex_t			*fork_left;
	pthread_mutex_t			*fork_right;
}							t_philosopher;

int				get_forks(t_settings *settings);

t_philosopher	*create_philosophers(t_settings *settings);

int				get_number(t_settings *settings, char **av);
int				get_time2die(t_settings *settings, char **av);
int				get_time2eat(t_settings *settings, char **av);
int				get_time2sleep(t_settings *settings, char **av);
int				get_musteat(t_settings *settings, int ac, char **av);

int				parser(t_settings *settings, int ac, char **av);

int				check_numerical(char *str);

#endif