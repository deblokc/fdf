/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:12:46 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 11:44:47 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	normtrgb(int color[7][3], int idx1, int idx2, float fractbetween)
{
	return (create_trgb(0, (color[idx2][0] - color[idx1][0]) * \
				fractbetween + color[idx1][0], (color[idx2][1] - \
					color[idx1][1]) * fractbetween + color[idx1][1], \
				(color[idx2][2] - color[idx1][2]) * fractbetween + \
				color[idx1][2]));
}

int	rgb2(int x, int min, int max, int color[7][3])
{
	float	value;
	float	fractbetween;
	int		idx1;
	int		idx2;

	fractbetween = 0;
	if (min == max)
		value = 0;
	else
		value = (float)(x - min) / (float)(max - min);
	idx1 = 0;
	idx2 = 0;
	if (value >= 1)
	{
		idx1 = 7 - 1;
		idx2 = 7 - 1;
	}
	else
	{
		value *= (7 - 1);
		idx1 = floor(value);
		idx2 = idx1 + 1;
		fractbetween = value - (float)idx1;
	}
	return (normtrgb(color, idx1, idx2, fractbetween));
}

int	rgb(int x, int min, int max)
{
	int		color[7][3];

	color[0][0] = 0;
	color[0][1] = 0;
	color[0][2] = 255;
	color[1][0] = 0;
	color[1][1] = 255;
	color[1][2] = 255;
	color[2][0] = 0;
	color[2][1] = 255;
	color[2][2] = 0;
	color[3][0] = 255;
	color[3][1] = 255;
	color[3][2] = 0;
	color[4][0] = 255;
	color[4][1] = 0;
	color[4][2] = 0;
	color[5][0] = 255;
	color[5][1] = 0;
	color[5][2] = 255;
	color[6][0] = 0;
	color[6][1] = 0;
	color[6][2] = 255;
	return (rgb2(x, min, max, color));
}

void	type2(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->size_line)
	{
		x = 0;
		while (x < info->size_col)
		{
			info->map[y][x].color = rgb(x, 0, info->size_col - 1);
			x++;
		}
		y++;
	}
}

void	next_rgb(t_info *info)
{
	int	y;
	int	x;
	int	tmp;

	y = 0;
	while (y < info->size_line)
	{
		x = info->size_col - 1;
		while (x > -1)
		{
			if (x == info->size_col - 1)
			{
				tmp = info->map[y][x].color;
			}
			if (x)
			{
				info->map[y][x].color = info->map[y][x - 1].color;
			}
			else
				info->map[y][x].color = tmp;
			x--;
		}
		y++;
	}
}
