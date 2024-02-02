/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:58:25 by merdal            #+#    #+#             */
/*   Updated: 2023/11/27 13:50:57 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_print_char(char c);
int		ft_print_int(int n);
int		ft_print_str(char *s);
int		ft_print_unsigned(unsigned int n);
int		ft_print_x_hex(unsigned int value);
int		ft_print_xx_hex(unsigned int num);
int		ft_print_ptr(uintptr_t ptr);

#endif