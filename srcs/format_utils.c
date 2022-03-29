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
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == '%')
		return (1);
	else
		return (0);
}

int		set_star(char c, va_list ap, t_format *f)
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
	return (star);
}

int	set_format(char c, va_list ap, t_format *f)
{
	int		star;

	star = set_star(c, ap, f);
	if (star)
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
	int		n;

	n = i + 2;
	if (!fstr)
		fstr = malloc(sizeof(char) * n);
	else
		fstr = my_realloc(fstr, n);
	if (!fstr)
		return (NULL);
	fstr[i] = c;
	fstr[n - 1] = 0;
	return (fstr);
}

void	inspect_f(char *fstr, t_format *f)
{
	printf("fstr: %s\n", fstr);
	printf("f->minus: %d\n", f->minus);
	printf("f->plus: %d\n", f->plus);
	printf("f->space: %d\n", f->space);
	printf("f->zero: %d\n", f->zero);
	printf("f->hash: %d\n", f->hash);
	printf("f->dot: %d\n", f->dot);
	printf("f->width: %d\n", f->width);
	printf("f->pcs: %d\n", f->pcs);
	printf("f->type: %c\n", f->type);
}
