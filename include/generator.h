#ifndef GENERATOR_H
# define GENERATOR_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void	arg_error(int ac, int *error);
void	format_error(char *arg, int *error);
void	write_str(char *str, int fd, int *error);

#endif
