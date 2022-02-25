/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:37:50 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 17:20:17 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	prints(t_info *info)
{
	int	list[4];

	list[0] = 100;
	list[1] = 335;
	list[2] = 140;
	list[3] = 345;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	list[0] = 135;
	list[1] = 340;
	list[2] = 145;
	list[3] = 350;
	while (list[1] != list[3])
	{
		putsqr(list, info);
		list[1]++;
	}
	prints2(info, list);
}

void	printd2(t_info *info, int *list)
{
	list[0] = 230;
	list[1] = 375;
	while (list[2] != list[0])
	{
		putsqr(list, info);
		list[2]++;
	}
	list[0] = 215;
	list[1] = 375;
	list[2] = 185;
	list[3] = 385;
	while (list[2] != list[0])
	{
		putsqr(list, info);
		list[2]++;
	}
}

void	printd(t_info *info)
{
	int	list[4];

	list[0] = 175;
	list[1] = 330;
	list[2] = 190;
	list[3] = 385;
	while (list[2] != list[0])
	{
		putsqr(list, info);
		list[2]--;
	}
	list[2] = 215;
	list[3] = 340;
	while (list[0] != list[2])
	{
		putsqr(list, info);
		list[0]++;
	}
	printd2(info, list);
}

void	puthud2(t_info *info, int *list)
{
	list[0] = 80;
	list[1] = 240;
	list[2] = 160;
	list[3] = 400;
	putsqr(list, info);
	list[0] = 0;
	list[1] = 320;
	list[2] = 240;
	list[3] = 400;
	putsqr(list, info);
	printminus(info, 10, 270);
	printplus(info, 170, 250);
	printz(info);
	prints(info);
	printq(info);
	printd(info);
	printp(info);
	printr(info);
}

void	puthud(t_info *info)
{
	int	list[4];

	list[0] = 0;
	list[1] = 80;
	list[2] = 240;
	list[3] = 160;
	putsqr(list, info);
	list[0] = 80;
	list[1] = 0;
	list[2] = 160;
	putsqr(list, info);
	putup(info);
	putdown(info);
	putright(info);
	putleft(info);
	printminus(info, 10, 30);
	printplus(info, 170, 10);
	puthud2(info, list);
}
