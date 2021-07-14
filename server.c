#include "minitalk.h"

void	putbit(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 7;

	(void)context;
	(void)info;
	if (sig == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		if (c)
			write(1, &c, 1);
		else
		{
			usleep(100);
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		i = 7;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	set;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&set.sa_mask);
	set.sa_sigaction = putbit;
	set.sa_flags = 0;
	sigaction(SIGUSR2, &set, NULL);
	sigaction(SIGUSR1, &set, NULL);
	while (1)
		pause();
	return (0);
}
