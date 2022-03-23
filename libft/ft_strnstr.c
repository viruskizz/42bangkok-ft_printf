/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:21:22 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 18:21:24 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_cmp(const char *str1, const char *str2, size_t n);

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	if (!*find)
		return ((char *) str);
	if (size == 0)
		return (NULL);
	while (size > 0 && *str)
	{
		if (my_cmp(str, find, size))
			return ((char *) str);
		str++;
		size--;
	}
	return (0);
}

static int	my_cmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 && *str2 && n > 0)
	{
		if (*str1++ != *str2++)
			return (0);
		n--;
	}
	if (*str2)
		return (0);
	return (1);
}
