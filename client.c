/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:15:10 by iakyaou           #+#    #+#             */
/*   Updated: 2023/02/27 22:13:01 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int ac, char **av)
{
	int	piid;

	if (ac != 3)
	{
		write (1, "error: not enough arguments\n", 28);
		return (1);
	}
	piid = ft_atoi(av[1]);
	if (piid <= 0)
	{
		write (1, "ERROR : ", 7);
		return (1);
	}
	send_byts(piid, av[2]);
	return (1);
}
