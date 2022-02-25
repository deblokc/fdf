/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:00 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:49:29 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printplus(t_info *info, int x, int y)
{
	int	list[4];

	printminus(info, x, y + 20);
	list[0] = x + 20;
	list[1] = y;
	list[2] = x + 40;
	list[3] = y + 60;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
}

void	printz2(t_info *info)
{
	t_point	tmp;
	t_point	tmp2;

	tmp.x = 135;
	tmp.y = 260;
	tmp2.x = 90;
	tmp2.y = 300;
	while (tmp.x != 150)
	{
		putline_hud(tmp, tmp2, info, 0x00FF00);
		tmp.x++;
		tmp2.x++;
	}
}

void	printz(t_info *info)
{
	int		list[4];

	list[0] = 90;
	list[1] = 250;
	list[2] = 150;
	list[3] = 260;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	list[0] = 90;
	list[1] = 300;
	list[2] = 150;
	list[3] = 310;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	printz2(info);
}

void	prints3(t_info *info, int *list)
{
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	list[0] = 100;
	list[1] = 375;
	list[2] = 140;
	list[3] = 385;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	list[0] = 105;
	list[1] = 370;
	list[2] = 95;
	list[3] = 380;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
}

void	prints2(t_info *info, int *list)
{
	list[0] = 105;
	list[1] = 340;
	list[2] = 95;
	list[3] = 360;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	list[0] = 100;
	list[1] = 355;
	list[2] = 140;
	list[3] = 365;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	list[0] = 135;
	list[1] = 360;
	list[2] = 145;
	list[3] = 380;
	prints3(info, list);
}
