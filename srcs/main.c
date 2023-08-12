/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 14:56:46 by minabe           ###   ########.fr       */
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

static int		process_stdin(void)
{
	char	**map;
	t_info	*info;

	map = make_map(STDIN_FILENO);
	if (map == NULL)
		return (FAIL);
	/* 以下同じ */
	if (check_valid_mapinfo(map) == false)
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

static int		process_mapfile(char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	map = make_map(fd);
	if (map == NULL)
		return (FAIL);
	close(fd);
	/* 以下同じ */
	if (check_valid_mapinfo(map) == false)
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

int		main(int argc, char *argv[])
{
	if (argc < 2)
	{
		if (process_stdin() == FAIL)
			ft_puterror(FT_ERR_MAP);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (process_mapfile(argv[i]) == FAIL)
				ft_puterror(FT_ERR_MAP);
			if (i + 1 != argc)
				ft_putstr("\n");
		}
	}
	return (0);
}
