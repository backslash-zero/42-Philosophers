#ifndef PARSING_H
# define PARSING_H

typedef	struct	            s_philosopher
{
	int                     index;
	int                     alive;
	struct s_philosopher    *next;
}				            t_philosopher;

typedef	struct	s_philo
{
	int             number;
	int             time2die;
	int             time2eat;
	int             time2sleep;
    int             option;
	int             musteat;
    int             everyone_alive;
}				t_philo;

int         parser(t_philo *philo, int ac, char **av);
int         get_philo(t_philo *philo, int ac, char **av);
int         check_ac(int ac);


int         get_number(t_philo *philo, char **av);
int         get_time2die(t_philo *philo, char **av);
int         get_time2eat(t_philo *philo, char **av);
int         get_time2sleep(t_philo *philo, char **av);
int         get_musteat(t_philo *philo, int ac, char **av);

int 		check_numerical(char *str);

#endif