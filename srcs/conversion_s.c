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

#include "my_utils.h"

char	*conversion_s(char *s)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	str = my_strcat(str, s);
	return (str);
}
