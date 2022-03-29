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
	// char	*s = "";

	n = ft_printf("%.*s", -4, "ddddddd");
	printf("\nn[%d]\n", n);
	m = printf("%.*s", -4, "ddddddd");
	printf("\nm[%d]\n", m);

	n = ft_printf("%.*s", -2, NULL);
	printf("\nn[%d]\n", n);
	m = printf("%.*s", -2, NULL);
	printf("\nm[%d]\n", m);
	n = ft_printf("%.s", NULL);
	printf("\nn[%d]\n", n);
	m = printf("%.s", NULL);
	printf("\nm[%d]\n", m);
	return (0);
}