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

int		print(const char *str, va_list ap)
{
	int		size;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strlcpy(tmp, str, ft_strlen(str));
	va_arg(ap, int);
	tmp = my_strcat((char *) tmp, "xxx");
	size = ft_strlen(tmp);
	printf("%s\n", tmp);
	free(tmp);
	tmp = NULL;
	return (size);
}