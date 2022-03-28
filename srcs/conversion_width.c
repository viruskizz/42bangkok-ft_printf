/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:08:59 by araiva            #+#    #+#             */
/*   Updated: 2022/03/28 15:09:00 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

static char	*align_left(char *cstr, t_format *f);
static char	*align_right(char *cstr, t_format *f);
static char	*align_left_digit(char *cstr, t_format *f);
static char	*align_right_digit(char *cstr, t_format *f);

char	*conversion_width(char	*cstr, t_format *f)
{
	char	*cfstr;
	int		n;

	n = f->width - ft_strlen(cstr);
	if (n <= 0)
		return (cstr);
	else if (f->type == 's' && (f->dot && f->pcs == 0))
	{
		cfstr = ft_calloc(sizeof(char), 1);
		free(cstr);
		return (cfstr);
	}
	else
	{
		if (f->minus)
			if (f->type == 'd')
				cfstr = align_left_digit(cstr, f);
			else
				cfstr = align_left(cstr, f);
		else
			if (f->type == 'd')
				cfstr = align_right_digit(cstr, f);
			else
				cfstr = align_right(cstr, f);
		free(cstr);
		return (cfstr);
	}
	
}

static char	*align_left(char *cstr, t_format *f)
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

static char	*align_right(char *cstr, t_format *f)
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
		if (i < plen)
			if (f->dot && f->pcs == 0)
				cfstr[i] = ' ';
			else
				cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	return (cfstr);
}

static char	*align_right_digit(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	plen = my_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	if (cstr[0] == '-' && (f->zero && !f->dot))
	{
		cfstr[i++] = cstr[j++];
		f->width++;
	}	
	while (i < f->width - plen)
	{
		if (f->zero && !f->dot)
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	while (j < plen)
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
