/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:58:10 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 14:58:15 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	char			*buf;

	i = 0;
	buf = str;
	while (i < n)
	{
		buf[i] = c;
		i++;
	}
	return (str);
}
