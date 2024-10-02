/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:06:04 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 08:57:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*erase;

	erase = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		erase[i] = '\0';
		i++;
	}
}
