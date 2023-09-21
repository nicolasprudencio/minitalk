#include "signal.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	pid_t	PID = atoi(argv[1]);

	if (argc != 2)
		return (1);
	kill(PID, SIGUSR1);
	return (0);
}