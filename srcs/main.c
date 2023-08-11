/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/11 09:41:36 by minabe           ###   ########.fr       */
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

static int		process_stdin(void)
{
	char	*content;
	char	**map;
	t_info	*info;

	content = ft_read(STDIN_FILENO);
	if (check_end_with_newline(content) == FAIL)
		return (FAIL);
	map = ft_split(content, "\n");
	ft_free(content);
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

static int		process_mapfile(int argc, char *argv[], int i)
{
	int		fd;
	char	*content;
	char	**map;
	t_info	*info;

	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
		return (FAIL);
	content = ft_read(fd);
	if (check_end_with_newline(content) == false)
		return (FAIL);
	close(fd);
	map = ft_split(content, "\n");
	ft_free(content);
	if (check_valid_mapinfo(map) == FAIL)
		return (FAIL);
	if (!(info = info_mapinfo(map)))
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	if (!(i + 1 == argc))
		ft_putstr("\n");
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
		for (int i = 0; i < argc; i++)
		{
			if (process_mapfile(argc, argv, i) == FAIL)
				ft_puterror(FT_ERR_MAP);
		}
	}
	return (0);
}
