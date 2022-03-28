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
static char	*format_pcs_digit(char *cstr, t_format *f);

char	*conversion_flag(char	*cstr, t_format *f)
{
	char	*buf;

	buf = ft_calloc(sizeof(char), ft_strlen(cstr) + 1);
	ft_memcpy(buf, cstr, ft_strlen(cstr));
	cstr = format_plus(cstr, f);
	cstr = format_hash(cstr, f);
	cstr = format_pcs(cstr, f);
	cstr = format_pcs_digit(cstr, f);
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
		if (nb < 0)
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

	if (f->pcs && f->type == 's')
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

static char	*format_pcs_digit(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(cstr);
	i = 0;
	j = 0;
	if (f->type != 'd' || !f->dot)
		return (cstr);
	else if (cstr[0] == '0' && f->pcs == 0)
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 1);
		free(cstr);
		return (cfstr);
	}
	else if (f->pcs - len >= 0)
	{
		if (cstr[0] == '-')
		{
			cfstr = ft_calloc(sizeof(char), f->pcs + 2);
			cfstr[0] = '-';
			i++;
			j++;
			len--;
			f->pcs++;
		}
		else
			cfstr = ft_calloc(sizeof(char), f->pcs + 1);
		while (i < f->pcs)
		{
			if (i < f->pcs - len)
				cfstr[i] = '0';
			else
				cfstr[i] = cstr[j++];
			i++;
		}
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}