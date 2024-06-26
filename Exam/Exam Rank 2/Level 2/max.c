/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:19:50 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 15:19:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int max = -2147483648;
	if(tab == NULL)
		return 0;
	while (tab[len > 0])
	{
		if(max < tab[len])
			max = tab[len];
		len--;
	}
	return (max);
}