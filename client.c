#include "minitalk.h"

void	send_str(pid_t pid, const char *str)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (str[j])
	{
		while (i >= 0)
		{
			if (str[j] & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(150);
			i--;
		}
		j++;
		i = 7;
	}
}


int	main(int argc, char **argv)
{
	pid_t	pid;
	if (argc != 3)
	{
		ft_putstr_fd("Wrong amount of arguments\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
