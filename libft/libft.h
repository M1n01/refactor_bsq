/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:39:32 by minabe            #+#    #+#             */
/*   Updated: 2023/08/09 23:19:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define IN 1
# define OUT 0

bool	ft_isspace(char c);
int		ft_is_printable(char c);

int		ft_strlen(char *str);
int		ft_atoi(char *str);

ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_puterror(char *str);

char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char *charset);

#endif