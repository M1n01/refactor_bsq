/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square_on_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/16 19:41:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

extern	int g_max;
extern	int g_col;
extern	int g_row;

bool	ft_check_2(char **map, t_tempcrs *tempcrs, t_info *info)
{
	int i;

	i = 0;
	while (i <= tempcrs->size)
	{
		if (tempcrs->col + i == count_map_colsize(map))
			return (false);
		if (tempcrs->row + i == info->num_rows + 1)
			return (false);
		if (map[tempcrs->row][tempcrs->col + i] == info->obstacle || map[tempcrs->row][tempcrs->col + i] == '\0')
			return (false);
		if (map[tempcrs->row + i][tempcrs->col] == info->obstacle || map[tempcrs->row + i][tempcrs->col] == '\0')
			return (false);
		i++;
	}
	return (true);
}

void	ft_check_3(char **map, t_tempcrs *tempcrs, t_info *info)
{
	tempcrs->size = 0;
	while (ft_check_2(map, tempcrs, info) == true)
	{
		tempcrs->size++;
	}
	if (g_max < tempcrs->size)
	{
		g_max = tempcrs->size;
		g_col = tempcrs->col;
		g_row = tempcrs->row;
	}
}

static void	put_map(char **map, t_info *info)
{
	int i;
	int j;

	i = 1;
	while (i <= info->num_rows)
	{
		j = 0;
		while (j < count_map_colsize(map))
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static void	make_square_on_map(char **map, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_max)
	{
		j = 0;
		while (j < g_max)
		{
			map[g_row + i][g_col + j] = info->full;
			j++;
		}
		i++;
	}
	return ;
}

void	ft_make_map(char **map, t_info *info)
{
	t_tempcrs tempcrs;

	g_max = 0;
	g_col = 0;
	g_row = 0;
	set_tempcrs(&tempcrs);
	while (tempcrs.row <= info->num_rows)
	{
		tempcrs.col = 0;
		while (tempcrs.col < count_map_colsize(map))
		{
			if (ft_check_1(map, tempcrs.col, tempcrs.row, info) == true)
			{
				ft_check_3(map, &tempcrs, info);
			}
			tempcrs.col++;
		}
		tempcrs.row++;
	}
	make_square_on_map(map, info);
	put_map(map, info);
	return ;
}
