/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:00 by araiva            #+#    #+#             */
/*   Updated: 2022/03/25 16:15:01 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	is_type(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == '%')
		return (1);
	else
		return (0);
}

int	set_flag(char c, t_flags *f)
{
	int		valid;

	valid = 1;
	if (is_type(c))
		f->type = c;
	else if (c == '-')
		f->is_minus = 1;
	else if (c == '+')
		f->is_plus = 1;
	else if (c == ' ')
		f->is_space = 1;
	else if (c == '0')
		f->is_zero = 1;
	else if (c == '#')
		f->is_hash = 1;
	else if (c == '\'')
		f->is_apost = 1;
	else if (c == '.')
		f->is_minus = 1;
	else
		valid = 0;
	return (valid);
}

void	reset_flag(t_flags *f)
{
	f->is_apost = 0;
	f->is_dot = 0;
	f->is_hash = 0;
	f->is_minus = 0;
	f->is_plus = 0;
	f->is_space = 0;
	f->is_zero = 0;
	f->type = 0;
}

char	*set_flag_str(char *fstr, char c, int i)
{
	int		n;

	n = i + 2;
	if (!fstr)
		fstr = malloc(sizeof(char) * n);
	else
		fstr = my_realloc(fstr, n);
	if (!fstr)
		return (NULL);
	fstr[i] = c;
	fstr[n - 1] = 0;
	return (fstr);
}
