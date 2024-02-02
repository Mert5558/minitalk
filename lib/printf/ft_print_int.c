/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:58:22 by merdal            #+#    #+#             */
/*   Updated: 2023/11/30 12:00:18 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		sign;

	sign = 1;
	if (n / 10)
	{
		ft_putnbr_fd(n / 10 * sign, fd);
	}
	c = '0' + n % 10 * sign;
	ft_putchar_fd(c, fd);
	return (0);
}

int	int_min(void)
{
	ft_putstr_fd("-2147483648", 1);
	return (11);
}

int	ft_print_int(int n)
{
	int	counter;
	int	x;

	counter = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (n == -2147483648)
		return (int_min());
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		counter++;
		n = -n;
	}
	x = n;
	while (x > 0)
	{
		x = x / 10;
		counter++;
	}
	ft_putnbr_fd(n, 1);
	return (counter);
}
