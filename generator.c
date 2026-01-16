#include <generator.h>

void	fill_str(char *str, int size, char to_fill)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = to_fill;
		i++;
	}
	str[i] = '\0';
}

void	write_str(char *str, int fd)
{
	write(fd, str, strlen(str));
}

void	brute_num(char *str, char *max_str, int size)
{
	int	i;

	while (strcmp(str, max_str) != 0)
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
		write_str(str, STDOUT_FILENO);
		write_str("\n", STDOUT_FILENO);
	}
}

void	start_gen(int size, int max_size)
{
	char	*str;
	char	*max_str;

	while (size <= max_size)
	{
		str = malloc(sizeof(char) * size + 1);
		max_str = malloc(sizeof(char) * size + 1);
		fill_str(max_str, size, '9');
		fill_str(str, size, '0');
		write_str(str, STDOUT_FILENO);
		write_str("\n", STDOUT_FILENO);
		brute_num(str, max_str, size);
		free(max_str);
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
		format_error(argv[1], &error);
	if (error)
		return (1);
	size = atoi(argv[1]);
	max_size = size;
	if (ac == 3)
		max_size = (atoi(argv[2]));
	start_gen(size, max_size);
}
