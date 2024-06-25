/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:11:53 by ttas              #+#    #+#             */
/*   Updated: 2024/03/18 14:24:30 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tempsize;
	int	tempvalue;

	tempsize = 0;
	while (tempsize != (size / 2))
	{
		tempvalue = tab[tempsize];
		tab[tempsize] = tab[((size - 1) - tempsize)];
		tab[((size - 1) - tempsize)] = tempvalue;
		tempsize++;
	}
}
