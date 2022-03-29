/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:41:28 by araiva            #+#    #+#             */
/*   Updated: 2022/03/23 23:41:30 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "srcs/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	n;
	int	m;
	// char	*null_str = NULL;
	// char	*s = "";

	n = ft_printf("%0*i", 2, 8);
	printf("\n[%d]\n", n);
	m = printf("%0*i", 2, 8);
	printf("\n[%d]\n", m);

	n = ft_printf("%*.*i", 2, -2, 8);
	printf("\n[%d]\n", n);
	m = printf("%*.*i", 2, -2, 8);
	printf("\n[%d]\n", m);

	return (0);
}