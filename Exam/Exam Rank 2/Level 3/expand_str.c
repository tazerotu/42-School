#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int isspace = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' && isspace == 0)
			{
				isspace = 4;
				while (isspace > 1)
				{
					write(1, &argv[1][i], 1);
					isspace--;
				}
			}
			if (argv[1][i] != ' ')
			{
				write(1, &argv[1][i], 1);
				isspace = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
	return (0);
}