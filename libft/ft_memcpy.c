/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:10:27 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 15:10:30 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*buf;
	char			*temp;

	i = 0;
	buf = (char *) dest;
	temp = (char *) src;
	while (i < n)
	{
		*buf++ = *temp++;
		i++;
	}
	return (dest);
}
