/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:18:11 by tsomsa            #+#    #+#             */
/*   Updated: 2022/03/02 23:11:07 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buf;

	buf = malloc(n * size);
	if (!buf)
		return (NULL);
	if (buf)
		ft_bzero(buf, n * size);
	return (buf);
}
