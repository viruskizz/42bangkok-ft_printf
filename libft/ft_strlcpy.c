/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:45:43 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 16:45:47 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_cp(char *d, const char *s, size_t n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (srclen < size)
		my_cp(dest, src, srclen + 1);
	else
	{
		my_cp(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}

static	void	my_cp(char *d, const char *s, size_t n)
{
	while (n-- > 0)
		*d++ = *s++;
}
