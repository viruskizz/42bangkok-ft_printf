/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:19:04 by araiva            #+#    #+#             */
/*   Updated: 2022/03/27 01:19:06 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

char	*conversion_format(va_list ap, t_format *f)
{
	char	*cstr;

	cstr = conversion_type(ap, f);
	return (cstr);
}

char	*conversion_type(va_list ap, t_format *f)
{
	char	*str;

	if (f->type == 'c')
		str = conversion_c(va_arg(ap, int));
	else if (f->type == 's')
		str = conversion_s(va_arg(ap, char *));
	else if (f->type == 'p')
		va_arg(ap, void *);
	else if (f->type == 'd')
		str = conversion_d(va_arg(ap, int));
	else if (f->type == 'i')
		str = conversion_d(va_arg(ap, int));
	else
	{
		str = malloc(sizeof(char) * 1);
		str[0] = 0;
	}
	return (str);
}
