/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:02:40 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 17:03:01 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rkey(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	if (info->type_color == 2 || (info->type_color == 1 && info->plat))
		info->type_color = 0;
	else
		info->type_color++;
	screen(info);
}

void	space(t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	screen(info);
}

void	pkey(t_info *info)
{
	if (!info->plat)
		info->plat = 1;
	else if (info->plat)
		info->plat = 0;
	mlx_destroy_image(info->mlx, info->screen->img);
	screen(info);
}

void	hook2(int keycode, t_info *info)
{
	if (keycode == 122)
		zkey(info);
	if (keycode == 115)
		skey(info);
	if (keycode == 113)
		qkey(info);
	if (keycode == 100)
		dkey(info);
	if (keycode == 93)
		rackey(info);
	if (keycode == 91)
		lackey(info);
	if (keycode == 61)
		zplus(info);
	if (keycode == 45)
		zminus(info);
	if (keycode == 114)
		rkey(info);
	if (keycode == 32)
		space(info);
	if (keycode == 112)
		pkey(info);
}

int	hook(int keycode, t_info *info)
{
	if (keycode == 65307)
		closewin(info);
	if (keycode == 65364)
		upkey(info);
	if (keycode == 65363)
		rightkey(info);
	if (keycode == 65362)
		downkey(info);
	if (keycode == 65361)
		leftkey(info);
	if (keycode == 65453)
		minuskey(info);
	if (keycode == 65451)
		pluskey(info);
	hook2(keycode, info);
	return (0);
}
