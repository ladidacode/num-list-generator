#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

void	write_str(char *str, int size)
{
	write(STDOUT_FILENO, str, size);
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
		write_str(str, size);
		write_str("\n", 1);
	}
}

int	main(int ac, char **argv)
{
	int		size;
	char	*str;
	char	*max_str;
	int		max_size;

	if (ac > 3 || ac < 2)
		return (0);
	size = atoi(argv[1]);
	max_size = size;
	if (ac == 3)
		max_size = (atoi(argv[2]));
	while (size <= max_size)
	{
		str = malloc(sizeof(char) * size + 1);
		max_str = malloc(sizeof(char) * size + 1);
		fill_str(max_str, size, '9');
		fill_str(str, size, '0');
		write_str(str, size);
		write_str("\n", 1);
		brute_num(str, max_str, size);
		free(max_str);
		free(str);
		size++;
	}
}
