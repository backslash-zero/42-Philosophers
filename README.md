# Philosophers

## Problem
Several philosophers are sitting at a round table doing one of three things: eating,
thinking, or sleeping.

While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.

The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are some forks on the table. As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.

The philosophers must never be starving. Every philosopher needs to eat.

Philosophers don’t speak with each other. Philosophers don’t know when another philosopher is about to die.

Each time a philosopher has finished eating, he will drop his forks and start sleeping.
When a philosopher is done sleeping, he will start thinking.

The simulation stops when a philosopher dies.

One fork between each philosopher, therefore if they are multiple philosophers, there
will be a fork at the right and the left of each philosopher.

To avoid philosophers duplicating forks, you should protect the forks state with a
mutex for each of them.

Each philosopher should be a thread.

## Concepts

### Threads
A thread is a single sequence stream within in a process. Threads are not independent of one other like processes as a result threads shares with other threads their code section, data section and OS resources like open files and signals.

Compiling a C program with Threads with gcc/clang: `-lpthread`

## Static Variables
Static variables have a property of preserving their value even after they are out of their scope!Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope.
Static variables are allocated memory in data segment, not stack segment.

### Mutex


## Code struture
### Parsing




## Allowed functions

### usleep
The usleep() function suspends execution of the calling thread for (at least) usec microseconds.

### gettimeofday
The gettimeofday() function gets the system’s clock time.

### pthread_create
Create a new thread. 
The first argument is a pointer to thread_id which is set by this function.
The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
The third argument is name of function to be executed for the thread to be created.
The fourth argument is used to pass arguments to the function, myThreadFun.

### pthread_detach


### pthread_join
The pthread_join() function for threads is the equivalent of wait() for processes. A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.

### pthread_mutex_init

### pthread_mutex_destroy

### pthread_mutex_lock

### pthread_mutex_unlock
