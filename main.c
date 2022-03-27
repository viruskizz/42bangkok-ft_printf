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
#include <limits.h>

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
	// char	*s = NULL;

	// n = ft_printf("%s", s);
	// ft_printf("\nn = %d\n", n);
	// m = printf("%s", s);
	// printf("\nm = %d", m);

	// Pointer
	void	*s = "Araiva";
	void	*x = (void *) LONG_MIN;
	void	*y = (void *) ULONG_MAX;
	void	*z = (void *) -ULONG_MAX;

	n = ft_printf(" %p %p %p %p", s, x, y, z);
	ft_printf("\nn = %d\n", n);
	m = printf(" %p %p %p %p", s, x, y, z);
	printf("\nm = %d", m);
	return (0);
}
