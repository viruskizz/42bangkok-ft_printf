/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:38:31 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 21:38:33 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *) str;
	while (i < n && buf)
	{
		if (*buf == (unsigned char) c)
			return ((unsigned char *) buf);
		buf++;
		i++;
	}
	return (NULL);
}
