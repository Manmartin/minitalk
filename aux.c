#include "minitalk.h"
static int	get_pow(long int n)
{
	int	pow;

	pow = 1;
	while (n > 9)
	{
		n /= 10;
		pow *= 10;
	}
	return (pow);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int			sign;
	int			pow;
	long int	n;

	if (nb < 0)
		sign = -1;
	else
		sign = 1;
	n = nb;
	n *= sign;
	pow = get_pow(n);
	if (sign < 0)
		ft_putchar_fd('-', fd);
	while (pow > 0)
	{
		ft_putchar_fd((n / pow) + '0', fd);
		n = n % pow;
		pow /= 10;
	}
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s && fd)
	{
		while (s[i])
			ft_putchar_fd(s[i++], fd);
	}
}

int	ft_atoi(const char *str)
{
	long double	sign;
	long double	number;

	number = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= 48 && *str <= 57)
		number = number * 10 + (*str++ - '0');
	if (number * sign > INT_MAX)
		return (-1);
	if (number * sign < INT_MIN)
		return (0);
	return (number * sign);
}
