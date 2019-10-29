/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:29:09 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:31:07 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		release_check(int k, t_mlx *i)
{
	if (k == 53)
		exit_hook(i);
	else if (k == 13 || k == 126)
		i->st->k_up = 0;
	else if (k == 125 || k == 1)
		i->st->k_down = 0;
	else if (k == 123 || k == 0)
		i->st->k_left = 0;
	else if (k == 124 || k == 2)
		i->st->k_right = 0;
	else if (k == 257 || k == 258)
		i->st->k_run = 0;
	else if (k == 15)
		i->st->k_c = 0;
	else if (k == 3)
		i->st->k_c = 0;
	return (0);
}

int		exit_hook(t_mlx *i)
{
	free_map(i, -1);
	mlx_destroy_image(i->mlx, i->img);
	mlx_destroy_window(i->mlx, i->win);
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(0);
	return (0);
}

void	my_hooks(t_mlx *i)
{
	mlx_do_key_autorepeatoff(i->mlx);
	mlx_hook(i->win, 2, 0, press_check, i);
	mlx_hook(i->win, 3, 0, release_check, i);
	mlx_hook(i->win, 17, 0, exit_hook, i);
	mlx_loop_hook(i->mlx, raycasting, i);
	mlx_loop(i->mlx);
}

void	my_ui(void)
{
	ft_putstr("/********** W O L F 3 D **********\\\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|             Controls            |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|  Forward:     ^ or W            |\n");
	ft_putstr("|  Back:        v or S            |\n");
	ft_putstr("|  Left:        < or A            |\n");
	ft_putstr("|  Right:       > or D            |\n");
	ft_putstr("|  Run:         Shift             |\n");
	ft_putstr("|  Look up:     R                 |\n");
	ft_putstr("|  Look down:   F                 |\n");
	ft_putstr("|  Textures:    T                 |\n");
	ft_putstr("|  Next level:  E (on checkpoint) |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|  Quit:        Esc               |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("\\********** W O L F 3 D **********/\n");
}

int		main(void)
{
	t_mlx	i;

	my_ui();
	my_init(&i);
	system("afplay ./include/music/5.mp3&");
	my_hooks(&i);
	return (0);
}
