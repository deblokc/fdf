/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:42:24 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/25 10:26:26 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*init_info(t_list *list)
{
	t_info	*info;

	if (!list)
		return (NULL);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (freelist(list), NULL);
	info->size_line = sizeline(list);
	info->size_col = sizecol(list);
	info->line = list;
	info->map = getmap(info);
	if (!info->map)
		return (freelist(list), NULL);
	info->ecart = getecart(info);
	if (!info->ecart)
		return (freelist(list), freeinfo(info), NULL);
	info->color = savecolor(info);
	if (!info->color)
		return (freelist(list), freeinfo(info), NULL);
	init_info_norm(info);
	return (info);
}

t_list	*getlist(char *path)
{
	char	*line;
	int		fd;
	t_list	*list;

	list = NULL;
	fd = open(path, O_RDONLY);
	if (!fd)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (list);
}

void	freelist(t_list *line)
{
	t_list	*current;
	t_list	*tmp;

	current = line;
	while (current)
	{
		tmp = current;
		current = current->prev;
		free(tmp->content);
		free(tmp);
	}
	free(current);
}

void	freeinfo(t_info *info)
{
	int	y;

	y = 0;
	while (info->map && y < info->size_line)
	{
		if (info->map[y])
		{
			free(info->map[y]);
			free(info->color[y]);
		}
		y++;
	}
	if (info->map)
		free(info->map);
	if (info->color)
		free(info->color);
	free(info);
}

int	main(int ac, char **av)
{
	t_info	*info;
	void	*mlx_win;

	if (ac == 2)
	{
		info = init_info(getlist(av[1]));
		if (!info)
			return (0);
		info->mlx = mlx_init();
		mlx_win = mlx_new_window(info->mlx, LENGTH, WIDTH, "fdf");
		info->win = mlx_win;
		puthud(info);
		screen(info);
	}
	return (0);
}
