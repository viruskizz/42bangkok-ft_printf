/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:38:06 by araiva            #+#    #+#             */
/*   Updated: 2022/03/27 20:38:07 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "myutils.h"

static char	*uits(unsigned int d);
static int	uilen(unsigned int d);

char	*conversion_u(unsigned int d)
{
	char	*str;

	str = uits(d);
	if (!str)
		return (NULL);
	my_strrev(str);
	return (str);
}

static char	*uits(unsigned int d)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), uilen(d) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	while (d > 0)
	{
		str[i] = (d % 10) + '0';
		d = d / 10;
		i++;
	}
	return (str);
}

static int	uilen(unsigned int d)
{
	int		i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}
