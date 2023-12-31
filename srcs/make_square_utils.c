/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/23 14:58:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

extern	int g_max;
extern	int g_col;
extern	int g_row;

int		count_map_colsize(char **map)
{
	int count;

	count = 0;
	while (map[1][count] != '\0')
		count++;
	return (count);
}

void	set_temps(t_temps *temp)
{
	temp->row = 1;
	temp->col = 0;
	temp->size = 0;
}

/* fullが置けるかどうかを判定する関数 */
bool	check_put_full(char **map, int col, int row, t_info *info)
{
	if (col == count_map_colsize(map))
		return (false);
	if (row == info->num_rows + 1)
		return (false);
	if (map[row][col] == info->obstacle || map[row][col] == '\0')
		return (false);
	return (true);
}
