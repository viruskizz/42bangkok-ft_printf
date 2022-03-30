/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:28:34 by araiva            #+#    #+#             */
/*   Updated: 2022/03/26 13:28:35 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

char	*conversion_p(size_t ptr)
{
	char	*hex;
	char	*pstr;

	if (!ptr)
	{
		pstr = ft_calloc(sizeof(char), P_EMPTY_L + 1);
		if (!pstr)
			return (NULL);
		pstr = ft_memcpy(pstr, P_EMPTY, P_EMPTY_L);
		return (pstr);
	}
	pstr = ft_calloc(sizeof(char), 3);
	if (!pstr)
		return (NULL);
	pstr[0] = '0';
	pstr[1] = 'x';
	hex = my_ith(ptr);
	if (!hex)
		return (NULL);
	pstr = my_strcat(pstr, hex);
	if (!pstr)
		return (NULL);
	if (hex)
		free(hex);
	return (pstr);
}
