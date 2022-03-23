/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:54:10 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/24 20:54:13 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		i;

	ns = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ns)
		return (NULL);
	i = 0;
	while (*s)
	{
		ns[i] = f(i, *s++);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
