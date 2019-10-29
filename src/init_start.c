/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:25:47 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:47:05 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_start(t_mlx *i)
{
	i->st->px = 18.5;
	i->st->py = 1.5;
	i->st->dx = -1;
	i->st->dy = 0;
	i->st->plx = 0;
	i->st->ply = 0.60;
	system("killall afplay 2&>/dev/null >/dev/null");
	if (i->nm == 2)
		system("afplay ./include/music/2.mp3&");
	else if (i->nm == 3)
		system("afplay ./include/music/3.mp3&");
	else if (i->nm == 4)
		system("afplay ./include/music/4.mp3&");
}

void	free_map(t_mlx *i, int j)
{
	while (++j < 20)
		free(i->st->map[j]);
	free(i->st->map);
}

void	ch_map(t_mlx *i)
{
	if ((i->nm == 1) && (floor(i->st->px) == 9) && (floor(i->st->py) == 9))
	{
		i->nm = 2;
		init_start(i);
		free_map(i, -1);
		i->st->map = i->st->map1;
	}
	else if ((i->nm == 2) && (floor(i->st->px) == 1) && (floor(i->st->py) == 9))
	{
		i->nm = 3;
		init_start(i);
		free_map(i, -1);
		i->st->map = i->st->map2;
	}
	else if ((i->nm == 3) && (floor(i->st->px) > 8) && (floor(i->st->px) < 11)
				&& (floor(i->st->py) > 8) && (floor(i->st->py) < 11))
	{
		i->nm = 4;
		init_start(i);
		free_map(i, -1);
		i->st->map = i->st->map3;
	}
}

int		press_check_(int k, t_mlx *i)
{
	if (k == 15)
		i->st->k_c = -300;
	else if (k == 3)
		i->st->k_c = 300;
	else if ((k == 36 && i->start != 1) || (k == 76 && i->start != 1))
	{
		i->start = 1;
		i->c_mode = 0;
		init_start(i);
		system("afplay ./include/music/1.mp3&");
	}
	else if (k == 17 && i->c_mode != 5)
	{
		i->re = 1;
		i->c_mode++;
	}
	else if (k == 17 && i->c_mode == 5)
		i->c_mode = 0;
	else if (k == 14 && i->start == 1)
		ch_map(i);
	return (0);
}

int		press_check(int k, t_mlx *i)
{
	if (k == 13 || k == 126)
		i->st->k_up = 1;
	else if (k == 125 || k == 1)
		i->st->k_down = 1;
	else if (k == 123 || k == 0)
		i->st->k_left = 1;
	else if (k == 124 || k == 2)
		i->st->k_right = 1;
	else if (k == 257 || k == 258)
		i->st->k_run = 1;
	else
		press_check_(k, i);
	return (0);
}
