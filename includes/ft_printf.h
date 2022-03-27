/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:12:26 by araiva            #+#    #+#             */
/*   Updated: 2022/03/24 00:12:27 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_format
{
	int		is_minus;
	int		is_plus;
	int		is_space;
	int		is_zero;
	int		is_hash;
	int		is_apost;
	int		is_dot;
	char	type;
}	t_format;

int		ft_printf(const char *str, ...);
int		is_type(char c);
int		set_format(char c, t_format *f);
void	reset_format(t_format *f);
char	*set_format_str(char *fstr, char c, int i);
char	*conversion_format(va_list ap, t_format *f);
char	*conversion_type(va_list ap, t_format *f);
char	*conversion_c(char c);
char	*conversion_d(int d);
char	*conversion_s(char *s);
char	*conversion_p(void *ptr);
char	*conversion_u(unsigned int d);

#endif
