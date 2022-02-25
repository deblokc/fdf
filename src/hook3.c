/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:01:50 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 17:02:06 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	minuskey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	if (info->ecart > 1)
		info->ecart -= 1;
	screen(info);
}

void	pluskey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->ecart += 1;
	screen(info);
}

void	zkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->yval += 10;
	screen(info);
}

void	skey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->yval -= 10;
	screen(info);
}

void	qkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->xval += 10;
	screen(info);
}
