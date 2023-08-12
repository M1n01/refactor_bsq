/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 14:52:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

bool	check_valid_mapinfo(char **map)
{
	int		len;
	char	*line;
	int		i;

	if (!map[0])
		return (false);
	line = map[0];
	len = ft_strlen(line);
	if (len < 4)
		return (false);
	i = -1;
	while (++i < len - 3)
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (false);
	if (!(ft_is_printable(line[len - 1]) &&
				ft_is_printable(line[len - 2]) &&
				ft_is_printable(line[len - 3])))
		return (false);
	if (line[len - 1] == line[len - 2] ||
			line[len - 2] == line[len - 3] ||
			line[len - 3] == line[len - 1])
		return (false);
	return (true);
}

t_info	*init_mapinfo(char **map)
{
	t_info	*info;
	char	*line;
	int		len;
	int		i;
	char	*num;

	line = map[0];
	len = ft_strlen(line);
	info = ft_malloc(sizeof(t_info *));
	num = ft_malloc(sizeof(char) * (len - 3) + 1);
	i = -1;
	while (++i < len - 3)
		num[i] = line[i];
	num[i] = '\0';
	info->num_rows = ft_atoi(num);
	info->empty = line[len - 3];
	info->obstacle = line[len - 2];
	info->full = line[len - 1];
	ft_free(num);
	return (info);
}
