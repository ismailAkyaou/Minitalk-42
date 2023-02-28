/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:05:23 by iakyaou           #+#    #+#             */
/*   Updated: 2023/02/28 20:34:16 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check(int *save, char *byte, int *ch, int *i)
{
	if (*save != *ch)
	{
		*save = *ch;
		*byte = 0;
		*i = 0;
	}
}

void	sighandel(int sig, siginfo_t *info, void *noting)
{
	static int	i;
	static char	byte;
	int			bit;
	static int	save;
	static int	ch;

	(void) noting;
	if (!save)
		save = info->si_pid;
	ch = info->si_pid;
	ft_check(&save, &byte, &ch, &i);
	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	byte = (byte << 1) | bit;
	i++;
	if (i == 8)
	{
		if (byte == 0)
			kill(info->si_pid, SIGUSR2);
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
