/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:18:02 by araiva            #+#    #+#             */
/*   Updated: 2022/03/27 21:18:05 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "myutils.h"

char	*conversion_x(unsigned int nb, int is_upper)
{
	char	*hex;

	hex = my_ith(nb);
	if (!hex)
		return (NULL);
	if (is_upper)
		hex = my_strtoupper(hex);
	return (hex);
}
