#include "minitalk.h"

void	putbit(int sig)
{
	static char	c = 0;
	static int	i = 7;

	if (sig == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 7;
	}
}


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, putbit);
		signal(SIGUSR1, putbit);
		pause();
	}
	return (0);
}
