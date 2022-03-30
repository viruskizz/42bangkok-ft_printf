/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:42:32 by araiva            #+#    #+#             */
/*   Updated: 2022/03/25 20:42:34 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "myutils.h"

char	*my_strcat(char *s1, char *s2)
{
	int		i;
	int		n1;
	int		n2;

	i = 0;
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	s1 = my_realloc((void *) s1, n1 + n2 + 1);
	if (!s1)
		return (NULL);
	while (i < n1)
		i++;
	while (i < n2 + n1)
	{
		s1[i] = s2[i - n1];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
