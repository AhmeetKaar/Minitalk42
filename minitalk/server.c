/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:34:13 by akar              #+#    #+#             */
/*   Updated: 2024/06/08 14:21:26 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	bit = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c = ((1 << bit) | c);
	if (signal == SIGUSR2)
		c = ((0 << bit) | c);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	pid = getpid();
	if (ac != 1)
	{
		ft_printf("Error: wrong format. Try this : ./server\n");
		return (0);
	}
	ft_printf("Procces ID : %d\n", pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (0);
}
