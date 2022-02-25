/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:08:54 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/24 11:42:21 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**allocmap(t_info *info)
{
	t_point	**map;

	map = (t_point **)malloc(sizeof(t_point *) * info->size_line + 1);
	if (!map)
		return (NULL);
	return (map);
}

t_point	getnbr(char *str, int end, int start)
{
	char	*tmp;
	int		i;
	t_point	ret;

	ret.x = 0;
	ret.y = 0;
	ret.z = 0;
	tmp = (char *)malloc(sizeof(char) * end - start + 1);
	if (!tmp)
		return (ret);
	i = 0;
	while (end - start)
		tmp[i++] = str[start++];
	tmp[i] = '\0';
	ret.z = ft_atoi(tmp);
	free(tmp);
	return (ret);
}
