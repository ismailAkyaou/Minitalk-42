/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:27:23 by iakyaou           #+#    #+#             */
/*   Updated: 2023/02/28 20:30:44 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check(int *save, char *byte, int *new_pid, int *i)
{
	if (*save != *new_pid)
	{
		*save = *new_pid;
		*byte = 0;
		*i = 0;
	}
}

void	sighandel(int signal, siginfo_t *info, void *noting)
{
	static int	i;
	static char	byte;
	int			bit;
	static int	save;
	static int	new_pid;

	(void) noting;
	if (!save)
		save = info->si_pid;
	new_pid = info->si_pid;
	ft_check(&save, &byte, &new_pid, &i);
	if (signal == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	byte = (byte << 1) | bit;
	i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	ss;

	ss.sa_sigaction = &sighandel;
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &ss, NULL);
		sigaction(SIGUSR2, &ss, NULL);
		pause();
	}
}
