#include <generator.h>

void	fill_str(char *str, int size, char to_fill, int *error)
{
	int	i;

	i = 0;
	while (i < size && *error == 0)
	{
		str[i] = to_fill;
		i++;
	}
	str[i] = '\0';
}

void	write_str(char *str, int fd, int *error)
{
	size_t	i;

	i = write(fd, str, strlen(str));
	if (i != strlen(str))
	{
		write_str("Error file descriptor write", STDERR_FILENO, error);
		*error = 1;
	}
}

void	brute_num(char *str, char *max_str, int size, int *error)
{
	int	i;

	while (strcmp(str, max_str) != 0 && *error == 0)
	{
		i = size - 1;
		if (str[i] == '9')
		{
			while (str[i] == '9')
			{
				str[i] = '0';
				i--;
			}
			str[i]++;
			i = size - 1;
		}
		else
			str[i]++;
		write_str(str, STDOUT_FILENO, error);
		write_str("\n", STDOUT_FILENO, error);
	}
}

void	start_gen(int size, int max_size, int *error)
{
	char	*str;
	char	*max_str;

	while (size <= max_size && *error == 0)
	{
		str = malloc(sizeof(char) * size + 1);
		max_str = malloc(sizeof(char) * size + 1);
		if (!str || !max_str)
		{
			write_str("Allocation error", STDERR_FILENO, error);
			*error = 1;
		}
		fill_str(max_str, size, '9', error);
		fill_str(str, size, '0', error);
		write_str(str, STDOUT_FILENO, error);
		write_str("\n", STDOUT_FILENO, error);
		brute_num(str, max_str, size, error);
		if (max_str)
			free(max_str);
		if (str)
			free(str);
		size++;
	}
}

int	main(int ac, char **argv)
{
	int		size;
	int		max_size;
	int		error;

	error = 0;
	arg_error(ac, &error);
	format_error(argv[1], &error);
	if (ac == 3)
		format_error(argv[2], &error);
	if (error)
		return (1);
	size = atoi(argv[1]);
	max_size = size;
	if (ac == 3)
		max_size = (atoi(argv[2]));
	start_gen(size, max_size, &error);
}
