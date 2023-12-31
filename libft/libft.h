/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:39:32 by minabe            #+#    #+#             */
/*   Updated: 2023/08/16 14:38:16 by minabe           ###   ########.fr       */
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
# define FT_BUFSIZ 320000
# define FT_ERR_MALLOC "malloc error\n"

bool			ft_isspace(char c);
bool			ft_is_printable(char c);
bool			ft_isdigit(char c);

int				ft_strlen(char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_atoi(char *str);

ssize_t			ft_putchar(char c);
ssize_t			ft_putstr(char *str);
void			ft_puterror(char *str);

char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *str, char *charset);

char			*ft_read(int fd);
void			ft_free(void *ptr);
void			*ft_malloc(size_t size);

#endif