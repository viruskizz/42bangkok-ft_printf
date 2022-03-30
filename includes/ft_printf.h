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
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		pcs;
	char	type;
}	t_format;

# ifdef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
#  define S_EMPTY "(null)"
#  define S_EMPTY_L 6
#  define P_EMPTY "(nil)"
#  define P_EMPTY_L 5
# else
#  define IS_LINUX 0
#  define OS "MAC"
#  define S_EMPTY "(null)"
#  define S_EMPTY_L 6
#  define P_EMPTY "0x0"
#  define P_EMPTY_L 3
# endif

# define F_TYPE "cspdiuxX%"

void	inspect_f(char *fstr, t_format *f);
int		ft_printf(const char *str, ...);
int		is_type(char c);
int		set_format(char c, va_list ap, t_format *f);
void	reset_format(t_format *f);
char	*set_format_str(char *fstr, char c, int i);
int		print_char(char *cstr, int w);
int		print_str(char *cstr, t_format *f);
int		printf_empty(char *cstr, t_format *f);
char	*conversion_format(va_list ap, t_format *f);
char	*conversion_type(va_list ap, t_format *f);
char	*conversion_flag(char	*cstr, t_format *f);
char	*conversion_pcs(char *cstr, t_format *f);
char	*conversion_width(char	*cstr, t_format *f);
char	*conversion_c(char c);
char	*conversion_d(int d);
char	*conversion_s(char *s);
char	*conversion_p(size_t ptr);
char	*conversion_u(unsigned int d);
char	*conversion_x(unsigned int nb, int is_upper);

#endif
