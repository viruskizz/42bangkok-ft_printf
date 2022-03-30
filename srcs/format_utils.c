/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:14:03 by araiva            #+#    #+#             */
/*   Updated: 2022/03/28 01:14:05 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

int	is_type(char c)
{
	char	*ptr;

	ptr = F_TYPE;
	while (*ptr)
		if (*ptr++ == c)
			return (1);
	return (0);
}

int	set_star(char c, va_list ap, t_format *f)
{
	int		star;

	if (c != '*')
		return (0);
	if (f->dot)
	{
		star = (va_arg(ap, int));
		f->pcs = star;
	}
	else
	{
		star = (va_arg(ap, int));
		if (star < 0)
		{
			f->minus = 1;
			star *= -1;
		}
		f->width = star;
	}
	return (1);
}

int	set_format(char c, va_list ap, t_format *f)
{
	if (set_star(c, ap, f))
		return (1);
	else if (f->dot && ft_isdigit(c))
		f->pcs = (f->pcs * 10) + (c - '0');
	else if (is_type(c))
		f->type = c;
	else if (c == '-')
		f->minus = 1;
	else if (c == '+')
		f->plus = 1;
	else if (c == ' ')
		f->space += 1;
	else if (c == '0' && f->width == 0)
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == '.')
		f->dot = 1;
	else if (ft_isdigit(c))
		f->width = (f->width * 10) + (c - '0');
	else
		return (0);
	return (1);
}

void	reset_format(t_format *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->dot = 0;
	f->width = 0;
	f->pcs = 0;
	f->type = 0;
}

char	*set_format_str(char *fstr, char c, int i)
{
	if (!fstr)
		fstr = ft_calloc(sizeof(char), i + 2);
	else
		fstr = my_realloc(fstr, i + 2);
	if (!fstr)
		return (NULL);
	fstr[i] = c;
	return (fstr);
}
