int	main(void)
{
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	char *line;
	for (int i = 0; i < 25; i++)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("Line %d: %s", i + 1, line);
			free(line);
		}
		else
		{
			printf("End of file or error reading file.\n");
			break ;
		}
	}

	close(fd);
	return (0);
}
