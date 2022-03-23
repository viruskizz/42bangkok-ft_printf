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
# include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;

	if (str == NULL)
		return (0);
	va_start(ap, str);
	ft_putstr_fd((char *) str, 0);
	va_end(ap);
	return (0);
}