/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:02:48 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:57:00 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getmin(t_info *info)
{
	int	min;
	int	y;
	int	x;

	y = 0;
	min = info->map[0][0].z;
	while (y < info->size_line)
	{
		x = 0;
		while (x < info->size_col)
		{
			if (info->map[y][x].z < min)
				min = info->map[y][x].z;
			x++;
		}
		y++;
	}
	return (min);
}

int	heatmap3(int color[6][3], int idx1, int idx2, float fractbetween)
{
	return (create_trgb(0, (color[idx2][0] - color[idx1][0]) * \
				fractbetween + color[idx1][0], (color[idx2][1] - \
					color[idx1][1]) * fractbetween + color[idx1][1], \
				(color[idx2][2] - color[idx1][2]) * fractbetween + \
				color[idx1][2]));
}

int	heatmap2(int z, int min, int max, int color[6][3])
{
	float	value;
	float	fractbetween;
	int		idx1;
	int		idx2;

	fractbetween = 0;
	if (min == max)
		value = 0;
	else
		value = (float)(z - min) / (float)(max - min);
	idx1 = 0;
	idx2 = 0;
	if (value >= 1)
	{
		idx1 = 6 - 1;
		idx2 = 6 - 1;
	}
	else
	{
		value *= (6 - 1);
		idx1 = floor(value);
		idx2 = idx1 + 1;
		fractbetween = value - (float)idx1;
	}
	return (heatmap3(color, idx1, idx2, fractbetween));
}

int	heatmap(t_point point, int min, int max)
{
	int		color[6][3];

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
	color[5][2] = 0;
	return (heatmap2(point.z, min, max, color));
}

void	type1(t_info *info)
{
	int	y;
	int	x;
	int	min;
	int	max;

	y = 0;
	min = getmin(info);
	max = getmax(info);
	while (y < info->size_line)
	{
		x = 0;
		while (x < info->size_col)
		{
			info->map[y][x].color = heatmap(info->map[y][x], min, max);
			x++;
		}
		y++;
	}
}
