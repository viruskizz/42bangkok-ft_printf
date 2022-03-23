/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:49:43 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 21:49:45 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *) str1;
	buf2 = (unsigned char *) str2;
	while (n > 0)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		buf1++;
		buf2++;
		n--;
	}
	return (0);
}
