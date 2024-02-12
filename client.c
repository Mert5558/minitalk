/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:13:04 by merdal           #+#    #+#             */
/*   Updated: 2024/02/05 12:09:56 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "./lib/libft/libft.h"
#include "./lib/printf/ft_printf.h"

void	send_signal(int pid, char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	transmit_message(const char *message, int pid)
{
	size_t	i;

	if (!message || pid <= 0)
		return ;
	i = 0;
	while (message[i])
	{
		send_signal(pid, message[i]);
		usleep(100);
		i++;
	}
	ft_printf("Message sent!\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid arguments\n");
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID or failed to set signal handler\n");
		return (1);
	}
	transmit_message(argv[2], pid);
	return (0);
}
