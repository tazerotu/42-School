/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:08 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:08:16 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*get_next_line(int fd);
char	*ft_free_join(char *s1, char *s2);
char	*ft_current_line(char *buffer);
char	*ft_read_file(int fd, char *res);
char	*ft_next_line(char *buffer);

// char	*ft_strjoin(char *s1, char *s2);
// void	ft_bzero(void *s, size_t n);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlen(const char *s);
// void	*ft_calloc(size_t nmemb, size_t size);

#endif
