/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/10 23:14:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft.h"

void	ft_free(char ***map)
{
	long int i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

char	*ft_read(int fd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	content = NULL;
	while ((n = read(fd, buf, FT_BUFSIZ)) > 0)
	{
		buf[n] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
			content = ft_strjoin(content, buf);
	}
	return (content);
}

static int		process_stdin(void)
{
	char	*content;
	char	**map;
	t_info	*info;

	content = ft_read(0);
	if (check_end_with_newline(content) == FAIL)
		return (FAIL);
	map = ft_split(content, "\n");
	free(content);
	if (check_valid_mapinfo(map) == FAIL)
		return (FAIL);
	if (!(info = info_mapinfo(map)))
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	ft_free(&map);
	free(info);
	return (SUCCESS);
}

static int		process_mapfile(int argc, char *argv[], int i)
{
	int		fd;
	char	*content;
	char	**map;
	t_info	*info;

	if ((fd = open(argv[i], O_RDONLY)) == -1)
		return (FAIL);
	content = ft_read(fd);
	if (check_end_with_newline(content) == FAIL)
		return (FAIL);
	close(fd);
	map = ft_split(content, "\n");
	free(content);
	if (check_valid_mapinfo(map) == FAIL)
		return (FAIL);
	if (!(info = info_mapinfo(map)))
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	if (!(i + 1 == argc))
		ft_putstr("\n");
	ft_free(&map);
	free(info);
	return (SUCCESS);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
	{
		if (process_stdin() == FAIL)
			ft_puterror(FT_ERR_MAP);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (process_mapfile(argc, argv, i) == FAIL)
				ft_puterror(FT_ERR_MAP);
		}
	}
	return (0);
}
