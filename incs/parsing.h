#ifndef PARSING_H
# define PARSING_H

int         parser(void);

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

#endif