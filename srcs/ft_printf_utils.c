/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:48:54 by araiva            #+#    #+#             */
/*   Updated: 2022/03/28 13:48:55 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

static int	print_char(char *cstr, int w);
static int	print_str(char *cstr, t_format *f);

int	print_format(va_list ap, t_format *f)
{
	char	*cstr;
	int		n;

	cstr = conversion_type(ap, f);
	cstr = conversion_flag(cstr, f);
	cstr = conversion_pcs(cstr, f);
	cstr = conversion_width(cstr, f);
	if (f->type == 'c')
		n = print_char(cstr, f->width);
	else
		n = print_str(cstr, f);
	free(cstr);
	return (n);
}

static int	print_char(char *cstr, int w)
{
	int		i;

	i = 0;
	if (w == 0)
		w = 1;
	while (i < w)
	{
		write(1, &cstr[i], 1);
		i++;
	}
	return (i);
}

static int	print_str(char *cstr, t_format *f)
{
	int		n;

	if (f->type == 's' && (f->dot && f->pcs == 0))
		return (0);
	n = ft_strlen(cstr);
	if (f->width > 0 && n == 0)
		n = print_char(cstr, f->width);
	else
		ft_putstr_fd(cstr, 1);
	return (n);
}
