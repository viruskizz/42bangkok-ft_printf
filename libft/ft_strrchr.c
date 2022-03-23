/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:42:31 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 20:42:34 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*buf;

	buf = NULL;
	while (*str != '\0')
	{
		if (*str == (char) c)
			buf = (char *) str;
		str++;
	}
	if ((char) c == *str)
		return ((char *) str);
	return (buf);
}
