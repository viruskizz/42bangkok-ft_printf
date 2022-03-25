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
#include "ft_printf.h"
#include "libft.h"
#include "my_utils.h"
#include <stdarg.h>

int		print(const char *str, va_list ap);
char	*get_flag(const char *str, t_flags *f);
char	*map(char *str, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	if (str == NULL)
		return (0);
	va_start(ap, str);
	len = print(str, ap);
	va_end(ap);
	return (len);
}

int	print(const char *str, va_list ap)
{
	char	*buf;
	char	*flag;
	int		len;
	t_flags	f;

	buf = malloc(sizeof(char) * 1);
	buf[0] = 0;
	len = 0;
	while (*str)
	{
		printf("%c", *str);
		if (*str == '%')
		{
			flag = get_flag(str, &f);
			if (flag)
			{
				printf("\nFF >> %s\n", flag);
				map(flag, ap);
				str += ft_strlen(flag) - 1;
				free(flag);
			}
		}
		str++;
	}
	len = ft_strlen(buf);
	free(buf);
	return (len);
}

char	*get_flag(const char *str, t_flags *f)
{
	int		i;
	char	*fstr;

	fstr = set_flag_str(NULL, '%', 0);
	if (!fstr)
		return (NULL);
	i = 1;
	while (str[i])
	{
		reset_flag(f);
		if (!set_flag(str[i], f))
		{	
			free(fstr);
			return (NULL);
		}
		fstr = set_flag_str(fstr, str[i], i);
		if (!str)
			return (NULL);
		if (f->type)
			return (fstr);
		i++;
	}
	free(fstr);
	return (NULL);
}

char	*map(char *str, va_list ap)
{
	va_arg(ap, int);
	return (str);
}
