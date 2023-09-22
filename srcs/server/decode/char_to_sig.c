#include "queue.h"
#include <signal.h>

void	char_to_sig(char input, pid_t pid)
{
	char	current;
	char	mask;
	int		n;
	
	n = 7;
	mask = 1;
	while (n >= 0)
	{
		current = (input >> n--) & mask;
		if (current == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}