/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:28:50 by araiva            #+#    #+#             */
/*   Updated: 2022/03/26 13:28:52 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "myutils.h"

char	*conversion_s(char *s)
{
	char	*str;

	if (s)
	{
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
		str = ft_memcpy(str, s, ft_strlen(s));
	}
	else
	{
		str = ft_calloc(sizeof(char), 7);
		str = ft_memcpy(str, "(null)", 6);
	}
	return (str);
}
