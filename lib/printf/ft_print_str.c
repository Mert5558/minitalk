/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:52:36 by merdal            #+#    #+#             */
/*   Updated: 2023/11/30 12:27:33 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		counter = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		counter = ft_strlen(s);
	}
	return (counter);
}
