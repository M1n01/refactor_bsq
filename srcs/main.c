/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/22 14:06:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

static void	free_map(char ***map)
{
	int i;

	i = 0;
	while ((*map)[i])
	{
		ft_free((*map)[i]);
		i++;
	}
	ft_free(*map);
	*map = NULL;
}

static char	**make_map(int fd)
{
	char	*content;
	char	**map;

	content = ft_read(fd);
	if (check_end_with_newline(content) == false)
		return (NULL);
	map = ft_split(content, "\n");
	ft_free(content);
	return (map);
}

static int		read_map_and_put_max_square(int fd)
{
	char	**map;
	t_info	*info;

	map = make_map(fd);
	if (map == NULL)
		return (FAIL);
	info = init_mapinfo(map);
	if (info == NULL)
		return (FAIL);
	if (check_valid_map(map, info) == false)
		return (FAIL);
	ft_make_map(map, info);
	free_map(&map);
	ft_free(info);
	return (SUCCESS);
}

static int		read_maps_and_put_max_square(int argc, char *argv[])
{
	int		fd;

	for (int i = 1; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (FAIL);
		if (read_map_and_put_max_square(fd) == FAIL)
		{
			close(fd);
			return (FAIL);
		}
		close(fd);
		if (i + 1 != argc)
			ft_putstr("\n");
	}
	return (SUCCESS);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
	{
		/* 標準入力から処理する */
		if (read_map_and_put_max_square(STDIN_FILENO) == FAIL)
			ft_puterror(FT_ERR_MAP);
	}
	else
	{
		/* マップファイルから1つ以上処理する */
		if (read_maps_and_put_max_square(argc, argv) == FAIL)
			ft_puterror(FT_ERR_MAP);
	}
	return (0);
}
