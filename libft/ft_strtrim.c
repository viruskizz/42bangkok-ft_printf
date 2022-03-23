/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:15:25 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/23 22:15:26 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_set(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s1);
	while (check_set(*(s1 + len - 1), set) && len > 0)
		len--;
	while (check_set(*s1++, set) && len > 0)
		len--;
	s1--;
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (str);
	while (i < len)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}

static	int	check_set(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}
