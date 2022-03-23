/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:44:44 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 15:44:46 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *) dest;
	csrc = (char *) src;
	if (cdest == csrc || n == 0)
		return (dest);
	if (cdest < csrc)
		while (n-- > 0)
			*cdest++ = *csrc++;
	else
	{
		cdest = cdest + n - 1;
		csrc = csrc + n - 1;
		while (n-- > 0)
			*cdest-- = *csrc--;
	}
	return (dest);
}
