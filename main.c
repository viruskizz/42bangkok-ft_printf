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

	n = ft_printf(" %c %c %c ", '0', 0, '1');
	ft_printf("\nn = %d\n", n);
	m = printf(" %c %c %c ", '0', 0, '1');
	printf("\nm = %d", m);
	return (0);
}
