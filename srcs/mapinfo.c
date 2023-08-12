/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 15:31:37 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

t_info	*init_mapinfo(char **map)
{
	t_info	*info;
	char	*line;
	int		len;
	int		i;
	char	*num;

	if (!map[0])
		return (NULL);
	line = map[0];
	len = ft_strlen(line);
	if (len < INFO_MIN)
		return (NULL);
	for (int i = 0; i < len - 3; i++)
	{
		if (!ft_isdigit(line[i]))
			return (NULL);
	}
	info = ft_malloc(sizeof(t_info));
	num = ft_malloc(sizeof(char) * (len - 3) + 1);
	/* strlcpyに変更 */
	for (i = 0; i < len - 3; i++)
		num[i] = line[i];
	num[i] = '\0';
	info->num_rows = ft_atoi(num);
	info->empty = line[len - 3];
	info->obstacle = line[len - 2];
	info->full = line[len - 1];
	if (!(ft_is_printable(info->empty) && ft_is_printable(info->obstacle) && ft_is_printable(info->full)))
		return (NULL);
	if (info->empty == info->obstacle || info->obstacle == info->full || info->full == info->empty)
		return (false);
	ft_free(num);
	return (info);
}
