/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:28 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 08:52:25 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < size)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}

// size_t	d_len;
// size_t	s_len;
// size_t	offset;
// size_t	src_index;

// d_len = ft_strlen(dst);
// s_len = ft_strlen(src);
// offset = d_len;
// src_index = 0;
// while (*(src + src_index) != '\0')
// {
// 	*(dst + offset) = *(src + src_index);
// 	offset++;
// 	src_index++;
// 	if (offset == size - 1)
// 		break ;
// }
// *(dst + offset) = '\0';
// return (d_len + s_len);