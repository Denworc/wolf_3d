/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:19:14 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:49:30 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	text_load2(t_mlx *i, int w, int h)
{
	i->wall = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/04.XPM", &w, &h);
	i->floor = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/wall6.xpm", &w, &h);
	i->ceiling = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand.xpm", &w, &h);
	i->wsx[0] = 0;
	i->wsy[0] = 0;
	i->wmx[0] = 512;
	i->wmy[0] = 512;
	i->wsx[1] = 0;
	i->wsy[1] = 0;
	i->wmx[1] = 1024;
	i->wmy[1] = 1024;
	i->wsx[2] = 0;
	i->wsy[2] = 0;
	i->wmx[2] = 493;
	i->wmy[2] = 457;
}

void	text_load5(t_mlx *i, int w, int h)
{
	i->wall = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/wall2.XPM", &w, &h);
	i->ceiling = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand1.XPM", &w, &h);
	i->floor = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand1.XPM", &w, &h);
	i->wsx[0] = 0;
	i->wsy[0] = 0;
	i->wmx[0] = 512;
	i->wmy[0] = 512;
	i->wsx[1] = 0;
	i->wsy[1] = 0;
	i->wmx[1] = 564;
	i->wmy[1] = 564;
	i->wsx[2] = 0;
	i->wsy[2] = 0;
	i->wmx[2] = 512;
	i->wmy[2] = 512;
}

void	text_load3(t_mlx *i, int w, int h)
{
	i->wall = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand2.XPM", &w, &h);
	i->floor = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand2.XPM", &w, &h);
	i->ceiling = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand2.XPM", &w, &h);
	i->wsx[0] = 0;
	i->wsy[0] = 0;
	i->wmx[0] = 512;
	i->wmy[0] = 512;
	i->wsx[1] = 0;
	i->wsy[1] = 0;
	i->wmx[1] = 512;
	i->wmy[1] = 512;
	i->wsx[2] = 0;
	i->wsy[2] = 0;
	i->wmx[2] = 512;
	i->wmy[2] = 512;
}

void	text_load4(t_mlx *i, int w, int h)
{
	i->wall = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/wall.xpm", &w, &h);
	i->floor = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/stone.xpm", &w, &h);
	i->ceiling = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/stone.xpm", &w, &h);
	i->wsx[0] = 0;
	i->wsy[0] = 0;
	i->wmx[0] = 512;
	i->wmy[0] = 512;
	i->wsx[1] = 0;
	i->wsy[1] = 0;
	i->wmx[1] = 512;
	i->wmy[1] = 512;
	i->wsx[2] = 0;
	i->wsy[2] = 0;
	i->wmx[2] = 512;
	i->wmy[2] = 512;
}

void	text_load1(t_mlx *i, int w, int h)
{
	i->ceiling = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/stone3.XPM", &w, &h);
	i->wall = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/wall8.XPM", &w, &h);
	i->floor = mlx_xpm_file_to_image(i->mlx,
									"./include/textures/sand4.XPM", &w, &h);
	i->wsx[0] = 0;
	i->wsy[0] = 0;
	i->wmx[0] = 1024;
	i->wmy[0] = 1024;
	i->wsx[1] = 4;
	i->wsy[1] = 0;
	i->wmx[1] = 1020;
	i->wmy[1] = 1024;
	i->wsx[2] = 0;
	i->wsy[2] = 0;
	i->wmx[2] = 512;
	i->wmy[2] = 512;
}
