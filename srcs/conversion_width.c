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

char	*conversion_width(char	*cstr, t_format *f)
{
	char	*cfstr;
	int		n;

	n = f->width - ft_strlen(cstr);
	if (f->width > 0 && n > 0)
	{
		if (f->minus)
			cfstr = align_left(cstr, f);
		else
			cfstr = align_right(cstr, f);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

static char	*align_left(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(cstr);
	if (len == 0)
		len = 1;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	while (i < f->width)
	{
		if (i < len)
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
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(cstr);
	if (len == 0)
		len = 1;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	while (i < f->width - len)
	{
		if (f->zero)
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	while (j < len)
		cfstr[i++] = cstr[j++];
	return (cfstr);
}
