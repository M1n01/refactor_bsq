/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmakesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/11 20:54:37 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

extern	int g_max;
extern	int g_col;
extern	int g_row;

int		ft_map_colsize(char **map)
{
	int count;

	count = 0;
	while (map[1][count] != '\0')
		count++;
	return (count);
}

void	set_tempcrs(t_tempcrs *p_tempcrs)
{
	p_tempcrs->row = 1;
	p_tempcrs->col = 0;
	p_tempcrs->size = 0;
}

bool	ft_check_1(char **map, int col, int row, t_info *p_info)
{
	if (col == ft_map_colsize(map))
		return (false);
	if (row == p_info->num_rows + 1)
		return (false);
	if (map[row][col] == p_info->obstacle || map[row][col] == '\0')
		return (false);
	return (true);
}

void	set_bsq(t_bsq *p_bsq)
{
	p_bsq->x = g_col;
	p_bsq->y = g_row;
	p_bsq->size = g_max;
}
