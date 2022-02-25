/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:16:04 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/25 10:21:40 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "fcntl.h"
# define LENGTH 1920
# define WIDTH 1080

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_info
{
	void	*win;
	void	*mlx;
	t_point	**map;
	t_list	*line;
	t_data	*screen;
	int		size_col;
	int		size_line;
	int		ecart;
	t_point	*center;
	double	anglex;
	double	angley;
	double	anglez;
	int		xval;
	int		yval;
	double	zfact;
	int		pressed_right;
	int		pressed_left;
	int		pressed_mol;
	int		type_color;
	int		already_heat;
	int		already_normal;
	int		already_rgb;
	int		x_begin;
	int		y_begin;
	int		**color;
	int		plat;
}			t_info;

void	button1(int x, int y, t_info *info);
int		mouse_hook(int button, int x, int y, t_info *info);
int		closewin(t_info *info);
int		hook(int keycode, t_info *info);
int		mouse_hook(int button, int x, int y, t_info *info);
int		mouse_release(int button, int x, int y, t_info *info);
int		mouse_move(int x, int y, t_info *info);
void	upkey(t_info *info);
void	rightkey(t_info *info);
void	downkey(t_info *info);
void	leftkey(t_info *info);
void	minuskey(t_info *info);
void	pluskey(t_info *info);
void	zkey(t_info *info);
void	skey(t_info *info);
void	qkey(t_info *info);
void	dkey(t_info *info);
void	rackey(t_info *info);
void	lackey(t_info *info);
void	zplus(t_info *info);
void	zminus(t_info *info);
void	rkey(t_info *info);
void	space(t_info *info);
void	pkey(t_info *info);
void	hook2(int keycode, t_info *info);
void	button1(int x, int y, t_info *info);
void	mouse_move2(int x, int y, t_info *info);
void	mouse_move3(int y, t_info *info);
void	mouse_move4(int x, int y, t_info *info);
int		getmax(t_info *info);
void	printq2(t_info *info);
void	printq(t_info *info);
void	printplus(t_info *info, int x, int y);
void	printz2(t_info *info);
void	printz(t_info *info);
void	prints3(t_info *info, int *list);
void	prints2(t_info *info, int *list);
void	putup(t_info *info);
void	putdown(t_info *info);
void	putright(t_info *info);
void	putleft(t_info *info);
void	printminus(t_info *info, int x, int y);
void	putsqr(int *list, t_info *info);
void	fillarrow(t_point tmp, int y, int *list, t_info *info);
void	fillarrow2(t_point tmp, int x, int *list, t_info *info);
int		putline_hud2(t_point p0, t_point p1, t_info *info, int color);
int		putline_hud(t_point p0, t_point p1, t_info *info, int color);
int		putpixel(t_info *info, int x, int y, unsigned int color);
t_point	rot(t_info *info, t_point point);
void	putpoint2(t_point tmp, t_info *info, int y, int x);
void	putpoint3(t_point tmp, t_info *info, int y, int x);
t_point	**allocmap(t_info *info);
t_point	getnbr(char *str, int end, int start);
int		**savecolor(t_info *info);
int		getecart(t_info *info);
int		sizecol(t_list *list);
int		sizeline(t_list *list);
void	init_info_norm(t_info *info);
void	iso(t_info *info);
void	plat(t_info *info);
void	type1(t_info *info);
void	type2(t_info *info);
int		create_trgb(int t, int r, int g, int b);
void	putpoint(t_info *info);
int		putpixel(t_info *info, int x, int y, unsigned int color);
t_point	**getmap(t_info *info);
void	screen(t_info *info);
int		putline(t_point a, t_point b, t_info *info, int color);
int		closewin(t_info *info);
int		hook(int keycode, t_info *info);
void	freelist(t_list *list);
void	printline(t_info *info);
void	freeinfo(t_info *info);
int		mouse_hook(int button, int x, int y, t_info *info);
int		mouse_release(int button, int x, int y, t_info *info);
int		mouse_move(int x, int y, t_info *info);
void	puthud(t_info *info);
void	next_rgb(t_info *info);
int		get_t(int i);
int		get_b(int i);
int		get_g(int i);
int		get_r(int i);
void	printp(t_info *info);
void	printr(t_info *info);
#endif
