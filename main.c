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

	// n = ft_printf("%2s", "ABCDE");
	// printf("\n[%d]\n", n);
	// m = printf("%2s", "ABCDE");
	// printf("\n[%d]\n", m);

	n = ft_printf("%-20s<", "ABCDE");
	printf("\n[%d]\n", n);
	m = printf("%-20s<", "ABCDE");
	printf("\n[%d]\n", m);

	n = ft_printf("%-2s", "ABCDE");
	printf("\n[%d]\n", n);
	m = printf("%-2s", "ABCDE");
	printf("\n[%d]\n", m);

	n = ft_printf("%-2.4s", "ABCDE");
	printf("\n[%d]\n", n);
	m = printf("%-2.4s", "ABCDE");
	printf("\n[%d]\n", m);

	n = ft_printf("%-2.s<", "ABCDE");
	printf("\n[%d]\n", n);
	m = printf("%-2.s<", "ABCDE");
	printf("\n[%d]\n", m);

	// n = ft_printf("%s", "ABC");
	// printf("\n[%d]\n", n);
	// m = printf("%s", "ABC");
	// printf("\n[%d]\n", m);

	// n = ft_printf("%1.s", "ABC");
	// printf("\n[%d]\n", n);
	// m = printf("%1.s", "ABC");
	// printf("\n[%d]\n", m);

	// n = ft_printf("%*.*s", 4, 0, "ABCDEF");
	// printf("\n[%d]\n", n);
	// m = printf("%*.*s", 4, 0, "ABCDEF");
	// printf("\n[%d]\n", m);

	return (0);
}