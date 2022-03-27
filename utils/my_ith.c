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

static int	baselen(long long int nb);
static char	*hexlmit(long long int nb);

// Convert int to hex
char	*my_ith(long long int nb)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	str = hexlmit(nb);
	if (str)
		return (str);
	str = ft_calloc(sizeof(char), baselen(nb) + 1);
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

static char	*hexlmit(long long int nb)
{
	char	*str;

	if (nb < -1)
	{
		// 8000000000000000
		str = ft_calloc(sizeof(char), 16 + 1);
		if (!str)
			return (NULL);
		str = ft_memcpy(str, "8000000000000000", 16);
		return (str);
	}
	if (nb == -1)
	{
		// ffffffffffffffff
		str = ft_calloc(sizeof(char), 16 + 1);
		if (!str)
			return (NULL);
		str = ft_memcpy(str, "ffffffffffffffff", 16);
		return (str);
	}
	return (NULL);
}

static int	baselen(long long int nb)
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
