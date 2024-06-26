#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int				*range;
	unsigned int	i;

	i = 0;
	range = malloc((end - start) * sizeof(int));
	while (start < end)
	{
		range[i] = start;
		start++;
		i++;
	}
	return (range);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int *range = ft_range(atoi(av[1]), atoi(av[2]));
		for (int i = 0; i < (atoi(av[2]) - atoi(av[1])); i++)
			printf("%d", range[i]);
	}
	return (0);
}