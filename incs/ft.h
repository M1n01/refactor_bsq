/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/23 14:58:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libgen.h>
# include "../libft/libft.h"

# define SUCCESS 1
# define FAIL 0
# define FT_ERR_MAP "map error\n"
# define INFO_MIN 4

typedef	struct	s_bsq
{
	int			x;
	int			y;
	int			size;
}				t_bsq;

typedef	struct	s_info
{
	int		num_rows;
	char	empty;
	char	obstacle;
	char	full;
}				t_info;

typedef	struct	s_temps
{
	int	col;
	int	row;
	int	size;
}				t_temps;

int				g_max;
int				g_col;
int				g_row;

t_info			*init_mapinfo(char **map);

bool			check_valid_map(char **map, t_info *info);
bool			check_end_with_newline(char *content);
void			set_temps(t_temps *temps);
bool			check_put_full(char **map, int col, int row, t_info *info);
void			ft_make_map(char **map, t_info *info);
int				count_map_colsize(char **map);

#endif
