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
#include "libft.h"
#include "my_utils.h"
static char	*hexlmit(long long int nb);

char	*conversion_p(void *ptr)
{
	char	*hex;
	char	*pstr;

	if (!ptr)
	{
		pstr = ft_calloc(sizeof(char), 6);
		pstr = ft_memcpy(pstr, "(nil)", 5);
		return (pstr);
	}
	pstr = ft_calloc(sizeof(char), 3);
	if (!pstr)
		return (NULL);
	pstr[0] = '0';
	pstr[1] = 'x';
	hex = hexlmit((long long int) ptr);
	if (!hex)
		hex = my_ith((long long int) ptr);
	if (!hex)
		return (NULL);
	pstr = my_strcat(pstr, hex);
	if (!pstr)
		return (NULL);
	if (hex)
		free(hex);
	return (pstr);
}


static char	*hexlmit(long long int nb)
{
	char	*str;

	if (nb == LONG_MIN)
	{
		// 8000000000000000
		str = ft_calloc(sizeof(char), 16 + 1);
		if (!str)
			return (NULL);
		str = ft_memcpy(str, "8000000000000000", 16);
		return (str);
	}
	else if ((long unsigned int) nb == ULONG_MAX)
	{
		// ffffffffffffffff
		str = ft_calloc(sizeof(char), 16 + 1);
		if (!str)
			return (NULL);
		str = ft_memcpy(str, "ffffffffffffffff", 16);
		return (str);
	}
	return (NULL);
}