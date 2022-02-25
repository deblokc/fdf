/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:02:11 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 17:02:30 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->xval -= 10;
	screen(info);
}

void	rackey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->angley += M_PI / 180;
	screen(info);
}

void	lackey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->angley -= M_PI / 180;
	screen(info);
}

void	zplus(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	if (info->zfact - 0.1 > 0.01)
		info->zfact -= 0.1;
	screen(info);
}

void	zminus(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	info->zfact += 0.1;
	screen(info);
}
