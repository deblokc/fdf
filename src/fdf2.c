/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:05:18 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/24 11:48:13 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sizeline(t_list *list)
{
	t_list	*current;
	int		i;

	i = 0;
	current = list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	sizecol(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list->content[i])
	{
		while (list->content[i] && list->content[i] == ' ')
			i++;
		if (list->content[i] && list->content[i] != ' '
			&& list->content[i] != '\n')
			j++;
		while (list->content[i] && list->content[i] != ' ')
			i++;
	}
	return (j);
}

int	getecart(t_info *info)
{
	if (info->size_col - 1 && info->size_line - 1)
	{
		if (LENGTH / (info->size_col - 1) < WIDTH / (info->size_line - 1))
			return (LENGTH / (info->size_col - 1) / 2);
		return (WIDTH / (info->size_line - 1) / 2);
	}
	if (info->size_col - 1)
		return (LENGTH / (info->size_col - 1) / 2);
	if (info->size_line - 1)
		return (WIDTH / (info->size_line - 1) / 2);
	return (1);
}

int	**savecolor(t_info *info)
{
	int	x;
	int	y;
	int	**color;

	color = (int **)malloc(sizeof(int *) * info->size_line + 1);
	if (!color)
		return (NULL);
	y = 0;
	while (y < info->size_line)
	{
		color[y] = (int *)malloc(sizeof(int) * info->size_col + 1);
		if (!color[y])
			return (NULL);
		x = 0;
		while (x < info->size_col)
		{
			color[y][x] = info->map[y][x].color;
			x++;
		}
		y++;
	}
	return (color);
}

void	init_info_norm(t_info *info)
{
	info->anglez = M_PI / 4;
	info->angley = 0;
	info->anglex = M_PI / 2 - atan(M_PI / 6);
	info->xval = LENGTH / 2;
	info->yval = WIDTH / 2;
	info->zfact = 1;
	info->pressed_right = 0;
	info->pressed_left = 0;
	info->pressed_mol = 0;
	info->already_heat = 0;
	info->already_normal = 0;
	info->type_color = 0;
	info->plat = 0;
}
