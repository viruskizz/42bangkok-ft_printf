/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:41:11 by araiva            #+#    #+#             */
/*   Updated: 2022/03/25 20:41:13 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_UTILS_H
# define MY_UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*my_strcat(char *s1, char *s2);
void	*my_realloc(void *ptr, size_t nsize);
size_t	my_memsize(void *ptr);

#endif
