/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:41:49 by minabe            #+#    #+#             */
/*   Updated: 2023/08/12 15:14:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (true);
	else
		return (false);
}

bool	ft_is_printable(char c)
{
	if (c < 0x20 || c == 0x7f)
		return (false);
	return (true);
}

bool	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}