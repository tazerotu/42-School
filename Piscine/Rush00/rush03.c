/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:15:25 by ttas              #+#    #+#             */
/*   Updated: 2024/03/17 10:26:51 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define LEFT_CORNER_TOP 'A'
#define RIGHT_CORNER_TOP 'C'
#define LEFT_CORNER_BOT 'A'
#define RIGHT_CORNER_BOT 'C'
#define SIDE 'B'
#define TOP_BOT 'B'
#define INSIDE ' '

void	ft_putchar(char c);

void	corner(int y, int x, int temp_y, int temp_x)
{
	if (x > 1)
	{
		if ((temp_x == 1) && (temp_y == 1))
			ft_putchar(LEFT_CORNER_TOP);
		if (temp_x == x && temp_y == 1)
			ft_putchar(RIGHT_CORNER_TOP);
		if (y > 1)
		{
			if (temp_x == 1 && temp_y == y)
			{
				ft_putchar(LEFT_CORNER_BOT);
			}
			if ((temp_x == x) && (temp_y == y))
				ft_putchar(RIGHT_CORNER_BOT);
		}
	}
	if ((x == 1) && (temp_x == 1) && (temp_y == 1))
	{
		ft_putchar(LEFT_CORNER_TOP);
	}
	if ((x == 1) && (temp_x == 1) && (temp_y == y) && (y > 1))
	{
		ft_putchar(LEFT_CORNER_BOT);
	}
}

void	top_bot(int y, int x, int temp_y, int temp_x)
{
	if ((temp_x > 1 && temp_x < x) && (temp_y == 1 || temp_y == y))
	{
		ft_putchar(TOP_BOT);
	}
}

void	side(int y, int x, int temp_y, int temp_x)
{
	if ((temp_x == 1 || temp_x == x) && (temp_y > 1 && temp_y < y))
	{
		ft_putchar(SIDE);
	}
	if (temp_x >= x)
	{
		write(1, "\n", 2);
	}
}

void	inside(int y, int x, int temp_y, int temp_x)
{
	if (temp_y > 1 && temp_y < y && temp_x > 1 && temp_x < x)
	{
		ft_putchar(INSIDE);
	}
}

void	rush(int y, int x)
{
	int	temp_x;
	int	temp_y;

	temp_x = 1;
	temp_y = 1;
	if (y < 1 || x < 1)
		write(1, "la figure ne peut pas avoir une valeur de 0\n", 45);
	else
	{
		while (temp_y <= y)
		{
			while (temp_x <= x)
			{
				corner(y, x, temp_y, temp_x);
				top_bot(y, x, temp_y, temp_x);
				side(y, x, temp_y, temp_x);
				inside(y, x, temp_y, temp_x);
				temp_x++;
			}
			temp_x = 0;
			temp_y++;
		}
	}
}
