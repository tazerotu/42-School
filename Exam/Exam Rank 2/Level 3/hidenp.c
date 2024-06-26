#include <unistd.h>

int	main(int ac, char **av)
{
	int j = 0;
	if (ac == 3)
	{
		int i = 0;
		while (av[2][i])
		{
			if (av[2][i] == av[1][j])
			{
				j++;
			}
			i++;
		}
		if (av[1][j] == '\0')
		{
			write(1, "1", 1);
		}
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}