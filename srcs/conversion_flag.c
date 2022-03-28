/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:53 by araiva            #+#    #+#             */
/*   Updated: 2022/03/28 14:23:54 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

static char	*format_plus(char	*cstr, t_format *f);
static char	*format_hash(char	*cstr, t_format *f);
static char	*format_pcs(char	*cstr, t_format *f);

char	*conversion_flag(char	*cstr, t_format *f)
{
	char	*buf;

	buf = ft_calloc(sizeof(char), ft_strlen(cstr) + 1);
	ft_memcpy(buf, cstr, ft_strlen(cstr));
	cstr = format_plus(cstr, f);
	cstr = format_hash(cstr, f);
	cstr = format_pcs(cstr, f);
	free(buf);
	return (cstr);
}

static char	*format_plus(char	*cstr, t_format *f)
{
	int		nb;
	char	*cfstr;

	if ((f->plus || f->space) && (f->type == 'd' || f->type == 'i'))
	{
		nb = ft_atoi(cstr);
		if (nb <= 0)
			return (cstr);
		cfstr = ft_calloc(sizeof(char), 2);
		if (f->plus)
			cfstr[0] = '+';
		else
			cfstr[0] = ' ';
		cfstr = my_strcat(cfstr, cstr);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

static char	*format_hash(char	*cstr, t_format *f)
{
	char	*cfstr;

	if (f->hash && (f->type == 'x' || f->type == 'X'))
	{
		cfstr = ft_calloc(sizeof(char), 3);
		cfstr[0] = '0';
		cfstr[1] = f->type;
		cfstr = my_strcat(cfstr, cstr);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

static char	*format_pcs(char *cstr, t_format *f)
{
	char	*cfstr;

	if (f->pcs && (f->type == 's'))
	{
		if (ft_strncmp(cstr, "(null)", 6) == 0 && f->pcs < 6)
		{
			cfstr = malloc(sizeof(char) * 1);
			cfstr[0] = 0;
		}
		else
			cfstr = ft_substr(cstr, 0, f->pcs);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}
