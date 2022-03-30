/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:28:41 by araiva            #+#    #+#             */
/*   Updated: 2022/03/26 13:28:42 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "myutils.h"

char	*conversion_d(int d)
{
	char	*str;

	str = ft_itoa(d);
	if (!str)
		return (NULL);
	return (str);
}
