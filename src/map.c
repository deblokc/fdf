/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:07:59 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/24 11:40:04 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ismin(char *tmp)
{
	while (*tmp)
	{
		if (*tmp >= 'a' && *tmp <= 'z')
			return (1);
		tmp++;
	}
	return (0);
}

int	getcolor(char *str, int	*start)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	*start += 3;
	i = *start;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
	{
		i++;
		j++;
	}
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < j)
		tmp[i++] = str[(*start)++];
	(*start)++;
	tmp[i] = '\0';
	if (ismin(tmp))
		return (ft_atoi_base(tmp, "0123456789abcdef"));
	return (ft_atoi_base(tmp, "0123456789ABCDEF"));
}

void	split_norm(t_point *line, int y, t_info *info)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	while (info->line->content[i] && x < info->size_col)
	{
		while (info->line->content[i] && info->line->content[i] == ' ')
			i++;
		j = i;
		while (info->line->content[j] && info->line->content[j] != ' '
			&& info->line->content[j] != ',')
			j++;
		line[x] = getnbr(info->line->content, j, i);
		line[x].color = 0xFFFFFF;
		if (info->line->content[j] == ',')
			line[x].color = getcolor(info->line->content, &j);
		line[x].x = x - (info->size_col / 2);
		line[x].y = y - (info->size_line / 2);
		x++;
		i = j;
		while (info->line->content[i] && info->line->content[i] == ' ')
			i++;
	}
}

t_point	*getlinep(t_info *info, int y)
{
	t_point	*line;

	line = (t_point *)malloc(sizeof(t_point) * info->size_col + 1);
	if (!line)
		return (NULL);
	split_norm(line, y, info);
	if (info->line->next)
		info->line = info->line->next;
	return (line);
}

t_point	**getmap(t_info *info)
{
	int		y;
	t_point	**map;

	y = 0;
	map = allocmap(info);
	if (!map)
		return (NULL);
	while (y < info->size_line)
	{
		map[y] = getlinep(info, y);
		if (!map[y])
			return (NULL);
		y++;
	}
	info->center = &map[info->size_line / 2][info->size_col / 2];
	return (map);
}
