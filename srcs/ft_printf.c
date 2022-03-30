/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:42:52 by araiva            #+#    #+#             */
/*   Updated: 2022/03/23 23:42:54 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

static int	runner(const char *str, va_list ap);
static char	*get_format_str(const char *str, va_list ap, t_format *f);
static int	print_format(va_list ap, t_format *f);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	if (str == NULL)
		return (0);
	va_start(ap, str);
	len = runner(str, ap);
	va_end(ap);
	return (len);
}

static int	runner(const char *str, va_list ap)
{
	char		*fstr;
	int			len;
	t_format	f;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			fstr = get_format_str(str, ap, &f);
			if (fstr)
			{
				len += print_format(ap, &f);
				str += ft_strlen(fstr);
				free(fstr);
			}
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
			str++;
		}
	}
	return (len);
}

static char	*get_format_str(const char *str, va_list ap, t_format *f)
{
	int		i;
	char	*fstr;

	fstr = set_format_str(NULL, '%', 0);
	if (!fstr)
		return (NULL);
	i = 1;
	reset_format(f);
	while (str[i])
	{
		if (!set_format(str[i], ap, f))
		{	
			free(fstr);
			return (NULL);
		}
		fstr = set_format_str(fstr, str[i], i);
		if (!str)
			return (NULL);
		if (f->type)
			return (fstr);
		i++;
	}
	free(fstr);
	return (NULL);
}

static int	print_format(va_list ap, t_format *f)
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
