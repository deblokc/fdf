/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:18:22 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/23 16:18:41 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putup(t_info *info)
{
	t_point	tmp;
	int		list[2];

	tmp.x = 120;
	tmp.y = 15;
	list[0] = 90;
	list[1] = 150;
	fillarrow(tmp, 60, list, info);
}

void	putdown(t_info *info)
{
	t_point	tmp;
	int		list[2];

	tmp.x = 120;
	tmp.y = 145;
	list[0] = 90;
	list[1] = 150;
	fillarrow(tmp, 100, list, info);
}

void	putright(t_info *info)
{
	t_point	tmp;
	int		list[2];

	tmp.x = 225;
	tmp.y = 120;
	list[0] = 90;
	list[1] = 150;
	fillarrow2(tmp, 180, list, info);
}

void	putleft(t_info *info)
{
	t_point	tmp;
	int		list[2];

	tmp.x = 15;
	tmp.y = 120;
	list[0] = 90;
	list[1] = 150;
	fillarrow2(tmp, 60, list, info);
}

void	printminus(t_info *info, int x, int y)
{
	int	list[4];

	list[0] = x;
	list[1] = y;
	list[2] = x + 60;
	list[3] = y + 20;
	while (list[0] != list[2])
	{
		putsqr(list, info);
		list[0]++;
	}
}
