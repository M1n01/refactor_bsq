/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:39:11 by minabe            #+#    #+#             */
/*   Updated: 2023/08/11 09:39:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		size;

	content = NULL;
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, FT_BUFSIZ);
		if (size == -1)
			return (NULL);
		buf[size] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
			content = ft_strjoin(content, buf);
	}
	return (content);
}