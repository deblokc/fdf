/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:19:43 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 17:52:32 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	realprintp(t_info *info, int x, int y)
{
	int	list[4];

	list[0] = x;
	list[1] = y;
	list[2] = x + 20;
	list[3] = y + 60;
	while (list[0] < list[2])
	{
		putsqr(list, info);
		list[0]++;
	}
	list[2] = x + 60;
	list[3] = y + 40;
	while (list[2] != x + 50)
	{
		putsqr(list, info);
		list[0]++;
		list[1]++;
		list[2]--;
		list[3]--;
	}
}

void	printp(t_info *info)
{
	int	list[4];

	list[0] = 0;
	list[1] = 480;
	list[2] = 80;
	list[3] = 560;
	putsqr(list, info);
	realprintp(info, 10, 490);
}

void	printr(t_info *info)
{
	int	list[4];

	list[0] = 160;
	list[1] = 480;
	list[2] = 240;
	list[3] = 560;
	putsqr(list, info);
	realprintp(info, 170, 490);
	list[0] = 200;
	list[1] = 530;
	list[2] = 220;
	list[3] = 550;
	while (list[0] < list[2])
	{
		putsqr(list, info);
		list[0]++;
	}
}
