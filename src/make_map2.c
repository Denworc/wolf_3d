/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 09:41:13 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:44:29 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	make_map3(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if ((y == 4 && ((x > 6 && x < 12) || (x == 15)))
				|| (y == 7 && ((x > 12 && x < 17) || (x == 18)))
				|| (y == 8 && ((x > 7 && x < 12)))
				|| (y == 11 && ((x > 7 && x < 12) || (x > 14 && x < 17)))
				|| (y == 15 && ((x == 10) || (x > 14 && x < 18)))
				|| (y == 17 && ((x == 10) || (x > 11 && x < 15) ||
								(x > 15 && x < 19)))
				|| (y == 6 && ((x == 8) || (x > 9 && x < 12)))
				|| (y == 2 && ((x == 11) || (x > 12 && x < 16)))
				|| (y == 9 && ((x == 11) || (x > 15 && x < 19)))
				|| (x == 18 && (y > 10 && y < 14))
				|| (x == 16 && (y > 11 && y < 14))
				|| (x == 10 && y == 13)
				|| (x == 9 && y == 15))
				i->st->map[x][y] = 1;
	}
}

void	make_map2(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if ((x == 1 && (y == 10 || y == 14)) ||
				(x == 2 && ((y > 0 && y < 5) || (y > 5 && y < 9) ||
							(y == 10) || (y == 12) || (y == 14)))
				|| (x == 3 && ((y == 7) || (y > 9 && y < 13) || (y == 14)))
				|| (x == 4 && ((y > 1 && y < 5) || (y == 7) || (y == 14)))
				|| (x == 5 && ((y == 2) || (y > 5 && y < 9) ||
								(y > 9 && y < 15)))
				|| (x == 6 && ((y == 2) || (y == 4) || (y == 6) || (y == 14)))
				|| (x == 7 && ((y == 2) || (y == 4) || (y == 6) ||
								(y > 7 && y < 12) || (y > 13 && y < 19)))
				|| (x == 12 && ((y > 3 && y < 9) || (y > 10 && y < 16)))
				|| (x == 9 && ((y > 0 && y < 4) || (y > 12 && y < 15) ||
								(y > 16 && y < 19)))
				|| (x == 14 && ((y == 2) || (y > 3 && y < 6) ||
								(y > 8 && y < 16) || (y > 16 && y < 19)))
				|| (x == 17 && ((y > 1 && y < 6) || (y == 9) ||
								(y == 15))))
				i->st->map[x][y] = 1;
	}
}

void	make_map1(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
		{
			if (x == 0 || y == 0 || x == 19 || y == 19)
				i->st->map[x][y] = 1;
			else
				i->st->map[x][y] = 0;
		}
	}
	x = -1;
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
		{
			if (x == 0 || y == 0 || x == 19 || y == 19)
				i->st->map1[x][y] = 1;
			else
				i->st->map1[x][y] = 0;
		}
	}
}

void	make_map4(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if (x == 0 || y == 0 || x == 19 || y == 19)
				i->st->map2[x][y] = 1;
			else
				i->st->map2[x][y] = 0;
	}
	x = -1;
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if (x == 0 || y == 0 || x == 19 || y == 19)
				i->st->map3[x][y] = 1;
			else
				i->st->map3[x][y] = 1;
	}
}

void	make_map6(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
		{
			if (x % 2 != 0)
				i->st->map1[x][y] = 1;
			if ((y == 9) && (x != 0) && (x != 19))
				i->st->map1[x][y] = 0;
			if ((y == 1) && (x != 0) && (x != 19))
				i->st->map1[x][y] = 0;
			if ((y == 18) && (x != 0) && (x != 19))
				i->st->map1[x][y] = 0;
		}
	}
}