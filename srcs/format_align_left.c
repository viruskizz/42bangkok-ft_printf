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

static char	*align_left_str(char *cstr, t_format *f);
static char	*align_left_digit(char *cstr, t_format *f);

char	*align_left(char *cstr, t_format *f)
{
	char	*cfstr;

	if (f->type == 'd' || f->type == 'i' || f->type == 'u'
		|| f->type == 'x' || f->type == 'X')
		cfstr = align_left_digit(cstr, f);
	else
		cfstr = align_left_str(cstr, f);
	free(cstr);
	return (cfstr);
}

static char	*align_left_str(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		plen;

	i = 0;
	plen = my_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	while (i < f->width)
	{	
		if (i < plen)
			cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	return (cfstr);
}

static char	*align_left_digit(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		plen;

	i = 0;
	plen = my_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	while (i < f->width)
	{	
		if (i < plen && (f->dot && f->pcs == 0))
			cfstr[i] = ' ';
		else if (i < plen)
			cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	return (cfstr);
}
