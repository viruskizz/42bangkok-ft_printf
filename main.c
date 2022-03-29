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

	// printf("D:%d\n", s[0]);
	n = ft_printf("%1s-", "");
	printf("\n[%d]\n", n);
	m = printf("%1s-", "");
	printf("\n[%d]\n", m);
	n = ft_printf("%-1s-", "");
	printf("\n[%d]\n", n);
	m = printf("%-1s-", "");
	printf("\n[%d]\n", m);
	return (0);
}

