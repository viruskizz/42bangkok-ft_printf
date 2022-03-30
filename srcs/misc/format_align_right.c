/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_align_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:23:43 by araiva            #+#    #+#             */
/*   Updated: 2022/03/29 00:23:44 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

static int	fill_prefix(char *cfstr, int i, int n, t_format *f);

char	*align_right(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	plen = my_printlen(cstr);
	if (!cfstr)
		return (NULL);
	if (cstr[0] == '-' && (f->zero && (!f->dot || f->pcs < 0)))
	{
		cfstr[i++] = cstr[j++];
		f->width++;
	}
	i = fill_prefix(cfstr, i, plen, f);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (j < plen)
		cfstr[i++] = cstr[j++];
	free(cstr);
	return (cfstr);
}

static int	fill_prefix(char *cfstr, int i, int n, t_format *f)
{
	while (i < f->width - n)
	{
		if (f->zero && (!f->dot || f->pcs < 0))
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	return (i);
}
