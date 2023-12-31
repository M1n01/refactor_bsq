/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/11 09:50:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		g_word_index = 0;
int		g_start = 0;
int		g_end = 0;
int		g_state = 0;

static bool	ft_is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (true);
		i++;
	}
	return (false);
}

int		ft_get_wc(char *str, char *charset)
{
	int wc;
	int state;

	wc = 0;
	state = OUT;
	while (*str)
	{
		if (ft_is_in_charset(*str, charset))
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
		++str;
	}
	return (wc);
}

void	ft_update_in_word(int i)
{
	if (g_state == OUT)
	{
		g_state = IN;
		g_start = i;
		g_end = i;
	}
	else
		g_end = i;
}

void	ft_add_last_word(char **res, char *str, int i)
{
	int j;

	if (g_state == IN)
	{
		res[g_word_index] = ft_malloc(sizeof(char) * ((i - g_start) + 2));
		j = -1;
		while (g_start <= i)
			res[g_word_index][++j] = str[g_start++];
		res[g_word_index][++j] = '\0';
		g_word_index++;
	}
	res[g_word_index] = 0;
	g_word_index = 0;
	g_start = 0;
	g_end = 0;
	g_state = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	res = ft_malloc(sizeof(char *) * (ft_get_wc(str, charset) + 1));
	i = -1;
	while (str[++i])
	{
		if (ft_is_in_charset(str[i], charset))
		{
			if (g_state == OUT)
				continue;
			g_state = OUT;
			res[g_word_index] = ft_malloc(sizeof(char) * ((g_end - g_start) + 2));
			for (j = 0; g_start <= g_end; j++, g_start++)
				res[g_word_index][j] = str[g_start];
			res[g_word_index][j] = '\0';
			g_word_index++;
		}
		else
			ft_update_in_word(i);
	}
	ft_add_last_word(res, str, i);
	return (res);
}
