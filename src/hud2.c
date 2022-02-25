/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:17:58 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:18:17 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	putline_hud2(t_point p0, t_point p1, t_info *info, int color)
{
	double	x;
	double	y;
	int		diff;

	diff = p1.x - p0.x;
	while (diff)
	{
		x = p0.x + diff;
		y = round(((double)((p1.y - p0.y) * (x - p0.x)) \
					/ (double)(p1.x - p0.x) + p0.y));
		mlx_pixel_put(info->mlx, info->win, (int)round(x), \
				(int)round(y), (unsigned int)color);
		if (diff < 0)
			diff++;
		else
			diff--;
	}
	return (0);
}

int	putline_hud(t_point p0, t_point p1, t_info *info, int color)
{
	double	x;
	double	y;
	int		diff;

	if ((p0.x < 0 && p1.x < 0) || (p0.x > (LENGTH - 1) && p1.x > (LENGTH - 1))
		|| (p0.y < 0 && p1.y < 0) || (p0.y > (WIDTH - 1)
			&& p1.y > (WIDTH - 1)))
		return (0);
	if (abs((p0.x - p1.x)) < abs((p0.y - p1.y)))
	{
		diff = p1.y - p0.y;
		while (diff)
		{
			y = p0.y + diff;
			x = round(((double)((y - p0.y) * (p1.x - p0.x)) \
						/ (double)(p1.y - p0.y) + p0.x));
			mlx_pixel_put(info->mlx, info->win, (int)round(x), \
					(int)round(y), (unsigned int)color);
			if (diff < 0)
				diff++;
			else
				diff--;
		}
	}
	return (putline_hud2(p0, p1, info, color));
}

void	putsqr(int *list, t_info *info)
{
	t_point	tmp;
	t_point	tmp2;

	tmp.x = list[0];
	tmp.y = list[1];
	tmp2.x = list[0];
	tmp2.y = list[3];
	putline_hud(tmp, tmp2, info, 0x00FF00);
	tmp2.x = list[2];
	tmp2.y = list[1];
	putline_hud(tmp, tmp2, info, 0x00FF00);
	tmp.x = list[2];
	tmp.y = list[3];
	putline_hud(tmp, tmp2, info, 0x00FF00);
	tmp2.x = list[0];
	tmp2.y = list[3];
	putline_hud(tmp, tmp2, info, 0x00FF00);
}

void	fillarrow(t_point tmp, int y, int *list, t_info *info)
{
	t_point	tmp2;

	tmp2.y = y;
	while (list[0] != list[1])
	{
		tmp2.x = list[0];
		putline_hud(tmp, tmp2, info, 0x00FF00);
		list[0]++;
	}
}

void	fillarrow2(t_point tmp, int x, int *list, t_info *info)
{
	t_point	tmp2;

	tmp2.x = x;
	while (list[0] != list[1])
	{
		tmp2.y = list[0];
		putline_hud(tmp, tmp2, info, 0x00FF00);
		list[0]++;
	}
}
