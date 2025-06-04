/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_no_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:05:01 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 18:05:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_free_join(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}

char	*ft_next_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free_join(NULL, buffer));
	i++;
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_current_line(char *buffer)
{
	unsigned int	i;
	char			*line;

	i = 0;
	while (!(buffer[i] == '\n' || buffer[i] == '\0'))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!(ft_strchr(res, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_join(buffer, res));
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(res, buffer);
		free(res);
		res = tmp;
		if (res == NULL)
			return (ft_free_join(buffer, NULL));
	}
	free(buffer);
	if (bytes_read == 0 && res[0] == '\0')
		return (ft_free_join(NULL, res));
	return (res);
}

char	*get_next_line_no_static(int fd, char **buffer)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	if (*buffer == NULL)
		*buffer = ft_calloc(1, 1);
	*buffer = ft_read_file(fd, *buffer);
	if (*buffer == NULL)
		return (NULL);
	line = ft_current_line(*buffer);
	*buffer = ft_next_line(*buffer);
	return (line);
}
