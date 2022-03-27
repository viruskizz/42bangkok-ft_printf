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
#include "my_utils.h"

int		runner(const char *str, va_list ap);
char	*get_format_str(const char *str, t_format *f);
int		print_format(va_list ap, t_format *f);

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

int	runner(const char *str, va_list ap)
{
	char		*fstr;
	int			len;
	t_format	f;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			fstr = get_format_str(str, &f);
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

char	*get_format_str(const char *str, t_format *f)
{
	int		i;
	char	*fstr;

	fstr = set_format_str(NULL, '%', 0);
	if (!fstr)
		return (NULL);
	i = 1;
	while (str[i])
	{
		reset_format(f);
		if (!set_format(str[i], f))
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

int	print_format(va_list ap, t_format *f)
{
	char	*cstr;
	int		n;

	cstr = conversion_format(ap, f);
	if (f->type == 'c')
	{
		ft_putchar_fd(*cstr, 1);
		n = 1;
	}
	else
	{
		ft_putstr_fd(cstr, 1);
		n = ft_strlen(cstr);
	}
	free(cstr);
	return (n);
}
