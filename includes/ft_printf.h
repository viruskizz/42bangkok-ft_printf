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

typedef struct s_flags
{
    int     is_minus;
	int	    is_plus;
    int	    is_space;
	int 	is_zero;
	int 	is_hash;
	int 	is_apost;
	int 	is_dot;
	char	type;
}	t_flags;

int     ft_printf(const char *str, ...);
int     is_type(char c);
int     set_flag(char c, t_flags *f);
void    reset_flag(t_flags *f);
char	*set_flag_str(char *fstr, char c, int i);

#endif

