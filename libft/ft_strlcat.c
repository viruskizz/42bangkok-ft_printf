/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:31:51 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 17:31:53 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	my_cp(char *d, const char *s, size_t n);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen >= size)
		return (size + srclen);
	if (srclen + destlen < size)
		my_cp(dest + destlen, src, srclen + 1);
	else
	{
		my_cp(dest + destlen, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen + destlen);
}

static	void	my_cp(char *d, const char *s, size_t n)
{
	while (n-- > 0)
		*d++ = *s++;
}
