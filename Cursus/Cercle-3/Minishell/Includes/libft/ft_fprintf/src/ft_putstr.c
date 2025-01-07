/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:43:27 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 10:27:42 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fprintf.h"

int	ft_putstr_fd_fprintf(int fd, char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
