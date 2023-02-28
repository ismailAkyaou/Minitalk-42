/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:49:55 by iakyaou           #+#    #+#             */
/*   Updated: 2023/02/28 20:12:26 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_send(int message)
{
	if (message == SIGUSR2)
	{
		write (1, "message valid\n", 13);
	}
	exit (0);
}

void	ft_end(int piid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill (piid, SIGUSR2);
		usleep(800);
		i++;
	}
}

void	send_byts(int piid, char *bayt)
{
	int	i;
	int	bayts;

	i = 0;
	while (bayt[i])
	{
		bayts = 7;
		while (bayts >= 0)
		{
			if ((bayt[i] >> bayts) & 1)
			{
				if (kill(piid, SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(piid, SIGUSR2) == -1)
					exit(1);
			}
			bayts--;
			usleep(900);
		}
		i++;
	}
	ft_end (piid);
}

int	main(int ac, char **av)
{
	int	piid;

	signal(SIGUSR2, message_send);
	if (ac != 3)
	{
		write (1, "error: not enough arguments\n", 28);
		return (1);
	}
	piid = ft_atoi(av[1]);
	if (piid <= 0)
	{
		write (1, "ERROR:7 ", 8);
		return (1);
	}
	send_byts(piid, av[2]);
	return (1);
}
