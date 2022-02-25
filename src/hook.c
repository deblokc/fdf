/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:59:53 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 17:07:23 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_release(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == 1)
		info->pressed_left = 0;
	if (button == 2)
		info->pressed_mol = 0;
	if (button == 3)
		info->pressed_right = 0;
	return (0);
}

void	mouse_move2(int x, int y, t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	if (x - info->x_begin > 100)
		info->xval += 10;
	else if (x - info->x_begin < -100)
		info->xval -= 10;
	if (y - info->y_begin > 100)
		info->yval += 10;
	else if (y - info->y_begin < -100)
		info->yval -= 10;
	screen(info);
}

void	mouse_move3(int y, t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	if (y - info->y_begin > 100)
		info->zfact += 0.1;
	else if (y - info->y_begin < -100)
		if (info->zfact - 0.1 > 0.01)
			info->zfact -= 0.1;
	screen(info);
}

void	mouse_move4(int x, int y, t_info *info)
{
	mlx_destroy_image(info->mlx, info->screen->img);
	if (x - info->x_begin > 100)
		info->anglez -= M_PI / 180;
	else if (x - info->x_begin < -100)
		info->anglez += M_PI / 180;
	if (y - info->y_begin > 100)
		info->anglex -= M_PI / 180;
	else if (y - info->y_begin < -100)
		info->anglex += M_PI / 180;
	screen(info);
}

int	mouse_move(int x, int y, t_info *info)
{
	if (info->pressed_left)
		mouse_move2(x, y, info);
	if (info->pressed_mol)
		mouse_move3(y, info);
	if (info->pressed_right)
		mouse_move4(x, y, info);
	return (0);
}
