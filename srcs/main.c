/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/11 10:46:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

void	free_map(char ***map)
{
	long int i;

	i = 0;
	while ((*map)[i])
	{
		ft_free((*map)[i]);
		i++;
	}
	ft_free(*map);
	*map = NULL;
}

static int	put_square_on_map(char **map, t_info *info)
{
	if (check_valid_mapinfo(map) == false)
		return (FAIL);
	if (!(info = info_mapinfo(map)))
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	free_map(&map);
	ft_free(info);
	return (SUCCESS);
}

static int		process_stdin(void)
{
	char	*content;
	char	**map;
	t_info	*info;

	content = ft_read(STDIN_FILENO);
	if (check_end_with_newline(content) == false)
		return (FAIL);
	map = ft_split(content, "\n");
	ft_free(content);
	if (put_square_on_map(map, info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int		process_mapfile(char *filename)
{
	int		fd;
	char	*content;
	char	**map;
	t_info	*info;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	content = ft_read(fd);
	if (check_end_with_newline(content) == false)
		return (FAIL);
	close(fd);
	map = ft_split(content, "\n");
	ft_free(content);
	if (put_square_on_map(map, info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
	{
		if (process_stdin() == FAIL)
			ft_puterror(FT_ERR_MAP);
	}
	else
	{
		for (int i = 0; i < argc; i++)
		{
			if (process_mapfile(argv[i]) == FAIL)
				ft_puterror(FT_ERR_MAP);
			if (i + 1 != argc)
				ft_putstr("\n");
		}
	}
	return (0);
}
