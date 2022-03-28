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
	char	*null_str = NULL;

	// n = ft_printf("%s", "");
	// printf("\n[%d]\n", n);
	// m = printf("%s", "");
	// printf("\n[%d]\n", m);
	// n = ft_printf("%s-", null_str);
	// printf("\n[%d]\n", n);
	// m = printf("%s-", null_str);
	// printf("\n[%d]\n", m);
	// n = ft_printf("%2s-", null_str);
	// printf("\n[%d]\n", n);
	// m = printf("%2s-", null_str);
	// printf("\n[%d]\n", m);
	n = ft_printf("%.2s", null_str);
	printf("\n[%d]\n", n);
	m = printf("%.2s", null_str);
	printf("\n[%d]\n", m);
	return (0);
}
