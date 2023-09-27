#include "queue.h"
#include <signal.h>

void	server_observer(int sig);

static int	open_connection = 1;

void	char_to_sig(char input, pid_t pid)
{
	char	current;
	char	mask;
	int		n;
	struct sigaction action;
	
	action.sa_handler = server_observer;
	//server_observer is called everytime we received an signal
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	n = 7;
	sigaction(SIGUSR1, &action, NULL);
	// sigaction(SIGUSR2, &action, NULL);
	mask = 1;
	while (n >= 0)
	{	
		if (open_connection == 1)
		{
			current = (input >> n--) & mask;
			if (current == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			open_connection = 0;
		}	
	}
}

void	server_observer(int sig)
{	
	if (sig == SIGUSR1)
		open_connection = 1;
}