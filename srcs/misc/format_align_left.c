/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_align_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:20:07 by araiva            #+#    #+#             */
/*   Updated: 2022/03/29 00:20:09 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

char	*align_left(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		plen;

	i = 0;
	plen = my_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	if (!cfstr)
		return (NULL);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (i < f->width)
	{	
		if (i < plen && (f->type == 's' && *cstr == 0))
			cfstr[i] = ' ';
		else if (i < plen)
			cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	free(cstr);
	return (cfstr);
}
