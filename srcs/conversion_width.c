/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:08:59 by araiva            #+#    #+#             */
/*   Updated: 2022/03/28 15:09:00 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include "myutils.h"

char	*conversion_width(char	*cstr, t_format *f)
{
	char	*cfstr;

	if (f->width <= ft_strlen(cstr))
		return (cstr);
	if (f->minus)
		cfstr = align_left(cstr, f);
	else
		cfstr = align_right(cstr, f);
	return (cfstr);
}
