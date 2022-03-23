/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:51:42 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/23 22:51:44 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	setlen(char const *s, char c);
static char	*setstr(char *dest, char const *src, int len);
static int	detlen(char const *s, char c);
static int	fitlen(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		len;
	int		slen;

	slen = ft_strlen(s);
	arr = malloc(sizeof(char *) * (fitlen(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = detlen(&s[0], c);
	while (s[j] && j <= slen)
	{
		len = setlen(&s[j], c);
		arr[i] = malloc(sizeof(char) * len + 1);
		if (!arr[i])
			return (NULL);
		*arr[i] = 0;
		arr[i] = setstr(arr[i], &s[j], len);
		i++;
		j += len + detlen(&s[j + len], c);
	}
	arr[i] = NULL;
	return (arr);
}

static int	fitlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s)
				s++;
			s--;
		}
		s++;
	}
	return (i);
}

static int	setlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	detlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static char	*setstr(char *dest, char const *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
