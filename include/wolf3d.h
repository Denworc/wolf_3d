/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 20:26:25 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:37:39 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

typedef	struct s_rgb	t_rgb;
typedef	struct s_c		t_c;
typedef	struct s_mlx	t_mlx;

struct					s_rgb
{
	int					r;
	int					g;
	int					b;
};

struct					s_c
{
	int					x;
	int					y;
	int					**map;
	int					**map1;
	int					**map2;
	int					**map3;
	int					mx;
	int					my;
	int					stx;
	int					sty;
	double				px;
	double				py;
	double				dx;
	double				dy;
	double				plx;
	double				ply;
	double				rpx;
	double				rpy;
	double				rdx;
	double				rdy;
	int					hit;
	int					side;
	int					lh;
	int					ds;
	int					de;
	int					k_c;
	int					k_run;
	int					k_up;
	int					k_down;
	int					k_right;
	int					k_left;
	int					wall;
	double				t;
	double				ot;
	double				fr;
	double				cx;
	double				sdx;
	double				sdy;
	double				ddx;
	double				ddy;
	double				pwd;
	double				rs;
	double				ms;
	double				tx;
	double				wx;
	double				fx;
	double				fy;
	double				w;
	double				dw;
	double				dp;
	double				cd;
	double				cfx;
	double				cfy;
	int					ftx;
	int					fty;
	double				e;
	double				s;
};

struct					s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*tab;
	int					bpp;
	int					sl;
	int					e;
	int					hei;
	int					wid;
	t_c					*st;
	int					c_mode;
	int					start;
	void				*wall;
	void				*ceiling;
	void				*floor;
	t_rgb				*c;
	int					wsx[3];
	int					wsy[3];
	int					wmx[3];
	int					wmy[3];
	int					re;
	int					nm;
};

void					make_map(t_mlx *i);
void					make_map6(t_mlx *i, int x, int y);
void					make_map3(t_mlx *i, int x, int y);
void					make_map2(t_mlx *i, int x, int y);
void					make_map1(t_mlx *i, int x, int y);
void					make_map4(t_mlx *i, int x, int y);
void					make_map5(t_mlx *i, int x, int y);
void					pixel_put(t_mlx *i, int x, int y, t_rgb *c);
void					add_color(t_rgb *c, int r, int g, int b);
void					put_color(t_mlx *i, t_rgb *c, int x);
void					get_frame(t_mlx *i);
void					take_color(t_mlx *i, t_rgb *c);
void					ft_ray(t_mlx *i, int x);
void					check_step(t_mlx *i);
void					dda_algoritm(t_mlx *i);
void					wall_text(t_mlx *i);
void					floor_text(t_mlx *i);
void					check_dist(t_mlx *i);
void					draw_rec(t_mlx *t, int y, int x, t_rgb *col);
void					draw_ex(t_mlx *i);
void					minimap(t_mlx *i);
int						start_menu(t_mlx *i, int w, int h);
void					get_pixel(void *c, int x, int y, t_rgb *s);
void					take_texture_(t_mlx *i, int x, int y, t_rgb *s);
void					take_texture_2(t_mlx *i, int x, int y, t_rgb *s);
void					take_texture(t_mlx *i, int x);
int						raycasting(t_mlx *i);
void					text_load2(t_mlx *i, int w, int h);
void					text_load5(t_mlx *i, int w, int h);
void					text_load3(t_mlx *i, int w, int h);
void					text_load4(t_mlx *i, int w, int h);
void					text_load1(t_mlx *i, int w, int h);
void					text_load(t_mlx *i, int w, int h);
void					init_var(t_mlx *i);
void					my_init(t_mlx *i);
void					turn_check(t_mlx *i, int dir);
void					move_check(t_mlx *i);
void					init_start(t_mlx *i);
void					free_map(t_mlx *i, int j);
void					ch_map(t_mlx *i);
int						press_check_(int k, t_mlx *i);
int						press_check(int k, t_mlx *i);
int						release_check(int k, t_mlx *i);
int						exit_hook(t_mlx *i);

#endif
