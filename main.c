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

	// n = ft_printf("%+d", 42000);
	// ft_printf(" [%d]\n", n);
	// m = printf("%+d", 42000);
	// printf(" [%d]\n", m);

	// n = ft_printf("%+d", -42000);
	// ft_printf(" [%d]\n", n);
	// m = printf("%+d", -42000);
	// printf(" [%d]\n", m);

	// n = ft_printf("%#x", 42000);
	// ft_printf(" [%d]\n", n);
	// m = printf("%#x", 42000);
	// printf(" [%d]\n", m);

	// n = ft_printf("%.4s", "hi there");
	// ft_printf(" [%d]\n", n);
	// m = printf("%.4s", "hi there");
	// printf(" [%d]\n", m);

	// n = ft_printf("%020.19X is how many tests are going to be made", 8000);
	// ft_printf(" [%d]\n", n);
	// m = printf("%020.19X is how many tests are going to be made", 8000);
	// printf(" [%d]\n", m);

	n = ft_printf("%c", 'a');
	printf("\n[%d]\n", n);
	m = printf("%c", 'a');
	printf("\n[%d]\n", m);
	n = ft_printf("%10c", 'a');
	printf("\n[%d]\n", n);
	m = printf("%10c", 'a');
	printf("\n[%d]\n", m);
	n = ft_printf("%1c", '\0');
	printf("\n[%d]\n", n);
	m = printf("%1c", '\0');
	printf("\n[%d]\n", m);
	n = ft_printf("%10c-", '\0');
	printf("\n[%d]\n", n);
	m = printf("%10c-", '\0');
	printf("\n[%d]\n", m);
	// n = ft_printf("%-c%-c%-4c%-11c", 'a', 'b', 'c', 'd');
	// printf("\n[%d]\n", n);
	// m = printf("%-c%-c%-4c%-11c", 'a', 'b', 'c', 'd');
	// printf("\n[%d]\n", m);
	return (0);
}
