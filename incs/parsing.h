#ifndef PARSING_H
# define PARSING_H

typedef	struct				s_philo
{
	int             number;
	int             time2die;
	int             time2eat;
	int             time2sleep;
    int             option;
	int             musteat;
    int             everyone_alive;
    int             musteat_max;
}							t_philo;

typedef	struct	            s_philosopher
{
	int                     id;
	t_philo					*philo;
	pthread_t 				tid;
	struct s_philosopher    *next;
}				            t_philosopher;

t_philosopher	*create_philosophers(t_philo *philo);

int         	get_number(t_philo *philo, char **av);
int         	get_time2die(t_philo *philo, char **av);
int         	get_time2eat(t_philo *philo, char **av);
int         	get_time2sleep(t_philo *philo, char **av);
int         	get_musteat(t_philo *philo, int ac, char **av);

int         	parser(t_philo *philo, int ac, char **av);
int         	get_philo(t_philo *philo, int ac, char **av);
int         	check_ac(int ac);

int 			check_numerical(char *str);

#endif