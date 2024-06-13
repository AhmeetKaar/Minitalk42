/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:33:56 by akar              #+#    #+#             */
/*   Updated: 2024/06/08 14:15:10 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str);
static void	sendchar_to_server(int pid_id, char msj);

int	main(int ac, char **av)
{
	int	pid_name;
	int	i;

	i = 0;
	pid_name = 0;
	if (ac != 3)
	{
		ft_printf("Wrong format, try this : ./client <PID> <MESSAGE>\n");
		exit(1);
	}
	pid_name = ft_atoi(av[1]);
	if (pid_name <= 0)
	{
		ft_printf("Please don't send negative value and zero\n");
		exit(1);
	}
	if (ac == 3)
	{
		while (av[2][i])
			sendchar_to_server(pid_name, av[2][i++]);
		sendchar_to_server(pid_name, '\n');
		sendchar_to_server(pid_name, '\0');
	}
	return (0);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	x;

	i = 0;
	number = 0;
	x = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			x = -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * x);
}

static void	sendchar_to_server(int pid_id, char msj)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((msj >> bit) & 1)
			kill(pid_id, SIGUSR1);
		else
			kill(pid_id, SIGUSR2);
		usleep(100);
		bit++;
	}
}
