/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ith.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:41:02 by araiva            #+#    #+#             */
/*   Updated: 2022/03/27 09:41:03 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my_utils.h"
#include "libft.h"

static int	baselen(long nb);

// Convert int to hex
char	*my_ith(long nb)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	str = malloc(sizeof(char) * baselen(nb) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	str[i] = 0;
	my_strrev(str);
	return (str);
}

static int	baselen(long nb)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}
