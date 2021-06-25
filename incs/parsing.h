#ifndef PARSING_H
# define PARSING_H

typedef	struct	s_philosopher
{
	int             index;
	int             alive;
	t_philosopher   *next;
}				t_philosopher;

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