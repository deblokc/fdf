/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:11:31 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:12:02 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	putpixel(t_info *info, int x, int y, unsigned int color)
{
	char	*dst;

	if (x > 0 && x < LENGTH - 1 && y > 0 && y < WIDTH)
	{
		dst = info->screen->addr + (y * info->screen->line_length + x \
				* (info->screen->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		return (1);
	}
	return (0);
}

t_point	rot(t_info *info, t_point point)
{
	t_point	ret;

	ret.x = (info->ecart * (cos(info->anglez) * \
				point.x - sin(info->anglez) * point.y));
	ret.y = (info->ecart * (sin(info->anglez) * \
				point.x + cos(info->anglez) * point.y));
	ret.y = (ret.y * cos(info->anglex)) - \
			((point.z * info->ecart / info->zfact) * sin(info->anglex));
	ret.x = (info->xval + (ret.x));
	ret.y = (info->yval + (ret.y));
	ret.z = point.z;
	ret.color = point.color;
	return (ret);
}

void	putpoint2(t_point tmp, t_info *info, int y, int x)
{
	int		color;
	t_point	tmp2;

	tmp2 = rot(info, info->map[y][x - 1]);
	if (tmp2.z > tmp.z)
		color = tmp2.color;
	else
		color = tmp.color;
	putline(tmp, tmp2, info, color);
}

void	putpoint3(t_point tmp, t_info *info, int y, int x)
{
	int		color;
	t_point	tmp2;

	tmp2 = rot(info, info->map[y - 1][x]);
	if (tmp2.z > tmp.z)
		color = tmp2.color;
	else
		color = tmp.color;
	putline(tmp, tmp2, info, color);
}
