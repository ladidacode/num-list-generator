#include <generator.h>

void	arg_error(int ac, int *error)
{
	if (ac > 3 || ac < 2)
	{
		write_str("usage:\tTwo arguments required\n", STDERR_FILENO, error);
		write_str("\tFirst argument = minimum size of string\n",
			STDERR_FILENO, error);
		write_str("\tSecond argument = maximum size of string\n",
			STDERR_FILENO, error);
		write_str("if only one argument provided", STDERR_FILENO, error);
		write_str("it will generate a string of unique size\n",
			STDERR_FILENO, error);
		*error = 1;
	}
}

void	format_error(char *arg, int *error)
{
	int	i;

	if (*error == 1)
		return ;
	i = 0;
	while (arg[1] && *error == 0)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			write_str("Format Error: the arguments must strictily be numbers\n",
				STDERR_FILENO, error);
			*error = 1;
		}
		i++;
	}
}
