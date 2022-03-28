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

static char	*align_right_str(char *cstr, t_format *f);
static char	*align_right_digit(char *cstr, t_format *f);
static int	fill_prefix_digit(char *cfstr, int i, int n, t_format *f);

char	*align_right(char *cstr, t_format *f)
{
	char	*cfstr;

	if (f->type == 'd' || f->type == 'i' || f->type == 'u'
		|| f->type == 'x' || f->type == 'X')
		cfstr = align_right_digit(cstr, f);
	else
		cfstr = align_right_str(cstr, f);
	free(cstr);
	return (cfstr);
}

static char	*align_right_str(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	plen = my_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	while (i < f->width - plen)
	{
		if (f->zero)
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	while (j < plen)
		cfstr[i++] = cstr[j++];
	return (cfstr);
}

static char	*align_right_digit(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	if (cstr[0] == '-' && (f->zero && !f->dot))
	{
		cfstr[i++] = cstr[j++];
		f->width++;
	}
	i = fill_prefix_digit(cfstr, i, my_printlen(cstr), f);
	while (j < my_printlen(cstr))
	{
		if (f->dot && f->pcs == 0)
		{
			cfstr[i++] = ' ';
			j++;
		}	
		else
			cfstr[i++] = cstr[j++];
	}
	return (cfstr);
}

static int	fill_prefix_digit(char *cfstr, int i, int n, t_format *f)
{
	while (i < f->width - n)
	{
		if (f->zero && !f->dot)
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	return (i);
}
