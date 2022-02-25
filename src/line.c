/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:29:10 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:02:57 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	colordiff(t_point p0, t_point p1, int step, int diff)
{
	return (create_trgb((double)abs(get_t(p1.color) - get_t(p0.color)) \
				/ (abs(step)) * abs(diff) + get_t(p0.color), \
				((double)abs(get_r(p1.color) - get_r(p0.color))) \
				/ (abs(step)) * abs(diff) + get_r(p0.color), \
				((double)abs(get_g(p1.color) - get_g(p0.color))) \
				/ (abs(step)) * abs(diff) + get_g(p0.color), \
				((double)abs(get_b(p1.color) - get_b(p0.color))) \
				/ (abs(step)) * abs(diff) + get_b(p0.color)));
}

void	putline2(t_point p0, t_point p1, t_info *info)
{
	double	x;
	double	y;
	int		step;
	int		diff;

	step = (p0.y - p1.y);
	diff = p1.y - p0.y;
	while (diff)
	{
		y = p0.y + diff;
		x = round(((double)((y - p0.y) * (p1.x - p0.x)) \
					/ (double)(p1.y - p0.y) + p0.x));
		putpixel(info, (int)round(x), (int)round(y), \
				colordiff(p0, p1, step, diff));
		if (diff < 0)
			diff++;
		else
			diff--;
	}
}

void	putline3(t_point p0, t_point p1, t_info *info)
{
	double	x;
	double	y;
	int		step;
	int		diff;

	step = p0.x - p1.x;
	diff = p1.x - p0.x;
	while (diff)
	{
		x = p0.x + diff;
		y = round(((double)((p1.y - p0.y) * (x - p0.x)) \
					/ (double)(p1.x - p0.x) + p0.y));
		putpixel(info, (int)round(x), (int)round(y), \
				colordiff(p0, p1, step, diff));
		if (diff < 0)
			diff++;
		else
			diff--;
	}
}

int	putline(t_point p0, t_point p1, t_info *info, int color)
{
	if (p0.color > p1.color)
		return (putline(p1, p0, info, color));
	if ((p0.x < 0 && p1.x < 0) || (p0.x > (LENGTH - 1) && p1.x > (LENGTH - 1))
		|| (p0.y < 0 && p1.y < 0) || (p0.y > (WIDTH - 1)
			&& p1.y > (WIDTH - 1)))
		return (0);
	if (abs((p0.x - p1.x)) < abs((p0.y - p1.y)))
		putline2(p0, p1, info);
	else
		putline3(p0, p1, info);
	(void)color;
	return (0);
}
