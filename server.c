/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:54:52 by merdal            #+#    #+#             */
/*   Updated: 2024/02/01 14:17:03 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "./lib/libft/libft.h"
#include "./lib/printf/ft_printf.h"

void	handle_message(int signal)
{
	static char	current_char = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		current_char = (current_char) << 1 | 1;
	else if (signal == SIGUSR2)
		current_char = (current_char) << 1 | 0;
	i++;
	if (i == 8)
	{
		write(1, &current_char, 1);
		i = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handle_message);
	signal(SIGUSR2, handle_message);
	while (1)
		usleep(100);
}
