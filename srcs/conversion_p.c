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

char	*conversion_p(void *ptr)
{
	char	*hex;
	char	*pstr;
	// long	d;

	// d = (long long int) ptr;
	// printf("\nD: %ld", d);
	if (!ptr)
	{
		pstr = ft_calloc(sizeof(char), 6);
		pstr = ft_memcpy(pstr, "(nil)", 5);
		return (pstr);
	}
	hex = my_ith((long long int) ptr);
	if (!hex)
		return (NULL);
	pstr = ft_calloc(sizeof(char), 3);
	if (!pstr)
		return (NULL);
	pstr[0] = '0';
	pstr[1] = 'x';
	pstr = my_strcat(pstr, hex);
	if (!pstr)
		return (NULL);
	if (hex)
		free(hex);
	return (pstr);
}
