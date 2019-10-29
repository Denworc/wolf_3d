/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 09:46:16 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:43:46 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	make_map5(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if ((x % 2 == 0) && (y % 2 == 0))
				i->st->map2[x][y] = 1;
			else if ((x % 3 == 0) && (y % 3 == 0))
				i->st->map2[x][y] = 1;
			else if ((x % 2 == 0) && (y % 2 == 0))
				i->st->map2[x][y] = 1;
	}
}

void	make_map7(t_mlx *i, int x, int y)
{
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
		{
			if (((x - y) > -2) && ((x - y) < 2))
				i->st->map2[x][y] = 0;
			if (((y == 9) || (y == 10)) && (x != 0) && (x != 19))
				i->st->map2[x][y] = 0;
			if (((x == 9) || (x == 10)) && (y != 0) && (y != 19))
				i->st->map2[x][y] = 0;
			if (((x + y) > 17) && ((x + y) < 21))
				i->st->map2[x][y] = 0;
			if ((y == 1) && (x != 0) && (x != 19))
				i->st->map2[x][y] = 0;
			if ((y == 18) && (x != 0) && (x != 19))
				i->st->map2[x][y] = 0;
			if (x == 0 || y == 0 || x == 19 || y == 19)
				i->st->map2[x][y] = 1;
		}
	}
}

void	make_map(t_mlx *i)
{
	int		**m;

	make_map1(i, -1, -1);
	make_map2(i, -1, -1);
	make_map3(i, -1, -1);
	make_map4(i, -1, -1);
	make_map5(i, -1, -1);
	i->st->map[7][18] = 0;
	i->st->map2[9][9] = 0;
	m = i->st->map;
	i->st->map = i->st->map2;
	i->st->map2 = i->st->map3;
	i->st->map3 = m;
	make_map6(i, -1, -1);
	make_map7(i, -1, -1);
}
