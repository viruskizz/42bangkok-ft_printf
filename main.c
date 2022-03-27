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
#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	n;
	int	m;

	// Char Test
	// n = ft_printf(" %c %c %c ", '0', 0, '1');
	// ft_printf("\nn = %d\n", n);
	// m = printf(" %c %c %c ", '0', 0, '1');
	// printf("\nm = %d", m);

	// String Test
	// n = ft_printf(" %s NULL", NULL);
	// ft_printf("\nn = %d\n", n);
	// m = printf(" %s NULL", NULL);
	// printf("\nm = %d", m);

	// Pointer
	// char	*s;
	int		x;

	// s = "Araiva";
	x = -1;
	n = ft_printf(" %p ", &x);
	ft_printf("\nn = %d\n", n);
	m = printf(" %p ", &x);
	printf("\nm = %d", m);
	return (0);
}
