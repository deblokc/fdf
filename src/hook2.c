/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:01:26 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/25 10:21:57 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closewin(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	freelist(info->line);
	freeinfo(info);
	exit(0);
	return (0);
}

void	upkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->anglex += M_PI / 180;
	if (fabs(remainder(info->anglex, M_PI * 2) - (M_PI / 2 - atan(M_PI / 6))) \
			< 0.001)
		info->anglex = M_PI / 2 - atan(M_PI / 6);
	screen(info);
}

void	rightkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->anglez += M_PI / 180;
	if (fabs(remainder(info->anglez, M_PI * 2) - (M_PI / 4)) < 0.001)
		info->anglez = M_PI / 4;
	screen(info);
}

void	downkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->anglex -= M_PI / 180;
	if (fabs(remainder(info->anglex, M_PI * 2) - (M_PI / 2 - atan(M_PI / 6))) \
			< 0.001)
		info->anglex = M_PI / 2 - atan(M_PI / 6);
	screen(info);
}

void	leftkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->anglez -= M_PI / 180;
	if (fabs(remainder(info->anglez, M_PI * 2) - (M_PI / 4)) < 0.001)
		info->anglez = M_PI / 4;
	screen(info);
}
