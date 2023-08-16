/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/16 14:51:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

static void	set_info(t_info *info, char *line);

static bool	check_valid_rowinfo(char *line, int len);

t_info	*init_mapinfo(char **map)
{
	t_info	*info;
	char	*line;
	int		len;

	if (!map[0])
		return (NULL);
	line = map[0];
	len = ft_strlen(line);
	if (check_valid_rowinfo(line, len) == false)
		return (NULL);
	info = ft_malloc(sizeof(t_info));
	set_info(info, line);
	if (!(ft_is_printable(info->empty) && ft_is_printable(info->obstacle) && ft_is_printable(info->full)))
		return (NULL);
	if (info->empty == info->obstacle || info->obstacle == info->full || info->full == info->empty)
		return (NULL);
	return (info);
}

static void	set_info(t_info *info, char *line)
{
	int		len;
	char	*num;

	len = ft_strlen(line);
	num = ft_malloc(sizeof(char) * (len - 3) + 1);
	ft_strlcpy(num, line, len - 2);
	info->num_rows = ft_atoi(num);
	info->empty = line[len - 3];
	info->obstacle = line[len - 2];
	info->full = line[len - 1];
	ft_free(num);
}

static bool	check_valid_rowinfo(char *line, int len)
{
	if (len < INFO_MIN)
		return (false);
	for (int i = 0; i < len - 3; i++)
	{
		if (!ft_isdigit(line[i]))
			return (false);
	}
	return (true);
}
