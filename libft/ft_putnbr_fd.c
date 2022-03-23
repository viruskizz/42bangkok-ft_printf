/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:06:54 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/24 22:06:56 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		my_write_nbr(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		my_write_nbr(n * -1, fd);
	}
	else
		my_write_nbr(n, fd);
}

static	int	my_write_nbr(int n, int fd)
{
	char	c;

	if (n == 0)
		return (0);
	else
	{
		my_write_nbr(n / 10, fd);
		c = (n % 10) + '0';
		ft_putchar_fd(c, fd);
	}
	return (0);
}
