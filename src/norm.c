/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:55:49 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 18:03:00 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getmax(t_info *info)
{
	int	max;
	int	y;
	int	x;

	y = 0;
	max = info->map[0][0].z;
	while (y < info->size_line)
	{
		x = 0;
		while (x < info->size_col)
		{
			if (info->map[y][x].z > max)
				max = info->map[y][x].z;
			x++;
		}
		y++;
	}
	return (max);
}

void	printq2(t_info *info)
{
	t_point	tmp;
	t_point	tmp2;

	tmp.x = 55;
	tmp.y = 365;
	tmp2.x = 75;
	tmp2.y = 385;
	while (tmp.y != 375)
	{
		putline_hud(tmp, tmp2, info, 0x00FF00);
		tmp.y++;
		tmp2.x--;
	}
}

void	printq(t_info *info)
{
	int		list[4];

	list[0] = 15;
	list[1] = 335;
	list[2] = 55;
	list[3] = 385;
	while (list[0] != 25)
	{
		putsqr(list, info);
		list[0]++;
		list[1]++;
		list[2]--;
		list[3]--;
	}
	printq2(info);
}

void	button1(int x, int y, t_info *info)
{
	if (x > 80 && x < 160 && y < 80)
		upkey(info);
	else if (x > 160 && x < 240 && y < 80)
		zplus(info);
	else if (x < 80 && y > 80 && y < 160)
		leftkey(info);
	else if (x > 80 && x < 160 && y > 80 && y < 160)
		downkey(info);
	else if (x > 160 && x < 240 && y > 80 && y < 160)
		rightkey(info);
	else if (x < 80 && y > 240 && y < 320)
		minuskey(info);
	else if (x > 160 && x < 240 && y > 240 && y < 320)
		pluskey(info);
	else if (x > 80 && x < 160 && y > 240 && y < 320)
		zkey(info);
	else if (x > 80 && x < 160 && y > 320 && y < 400)
		skey(info);
	else if (x < 80 && y > 320 && y < 400)
		qkey(info);
	else
		info->pressed_left = 1;
}

int	mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 1)
	{
		if (x < 80 && y < 80)
			zminus(info);
		else if (x > 160 && x < 240 && y > 320 && y < 400)
			dkey(info);
		else if (x < 80 && y > 480 && y < 560)
			pkey(info);
		else if (x > 160 && x < 240 && y > 480 && y < 560)
			rkey(info);
		else
			button1(x, y, info);
	}
	if (button == 2)
		info->pressed_mol = 1;
	if (button == 3)
		info->pressed_right = 1;
	if (button == 4)
		pluskey(info);
	if (button == 5)
		minuskey(info);
	info->x_begin = x;
	info->y_begin = y;
	return (0);
}
