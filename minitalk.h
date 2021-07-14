#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdlib.h>

void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
int     ft_atoi(const char *str);

#endif