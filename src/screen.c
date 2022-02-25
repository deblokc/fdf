/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:13:53 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:12:14 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpoint(t_info *info)
{
	int		x;
	int		y;
	t_point	tmp;
	t_point	tmp2;

	y = 0;
	while (y < info->size_line)
	{
		x = 0;
		while (x < info->size_col)
		{
			tmp = rot(info, info->map[y][x]);
			if (x > 0)
				putpoint2(tmp, info, y, x);
			if (y > 0)
				putpoint3(tmp, info, y, x);
			putpixel(info, tmp.x, tmp.y, (unsigned int)tmp.color);
			x++;
		}
		y++;
	}
	(void)tmp2;
}

void	changecolor(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->size_line)
	{
		x = 0;
		while (x < info->size_col)
		{
			info->map[y][x].color = info->color[y][x];
			x++;
		}
		y++;
	}
}

void	screen3(t_info *info)
{
	info->already_normal = 0;
	if (info->type_color == 1)
	{
		info->already_rgb = 0;
		if (!info->already_heat)
		{
			info->already_heat = 1;
			type1(info);
		}
	}
	else if (!info->plat)
	{
		info->already_heat = 0;
		if (!info->already_rgb)
		{
			info->already_rgb = 1;
			type2(info);
		}
		else
			next_rgb(info);
	}
}

void	screen2(t_info *info)
{
	if (info->type_color)
		screen3(info);
	else
	{
		info->already_heat = 0;
		info->already_rgb = 0;
		if (!info->already_normal)
			changecolor(info);
	}
	if (info->plat)
	{
		plat(info);
		if (info->already_rgb)
		{
			changecolor(info);
			info->type_color = 0;
		}
	}
	else if (!info->anglex || !info->anglez)
		iso(info);
}

void	screen(t_info *info)
{
	t_data	screen;

	screen.img = mlx_new_image(info->mlx, LENGTH, WIDTH);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel,
			&screen.line_length, &screen.endian);
	info->screen = &screen;
	screen2(info);
	putpoint(info);
	mlx_put_image_to_window(info->mlx, info->win, screen.img, 241, 0);
	mlx_hook(info->win, 17, 0, closewin, info);
	mlx_hook(info->win, 2, 1L << 0, hook, info);
	mlx_hook(info->win, 4, 1L << 2, mouse_hook, info);
	mlx_hook(info->win, 5, 1L << 3, mouse_release, info);
	mlx_hook(info->win, 6, 1L << 6, mouse_move, info);
	mlx_loop(info->mlx);
}
