/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:07:30 by iakyaou           #+#    #+#             */
/*   Updated: 2023/02/28 20:32:36 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINITALK_H
# define    MINITALK_H

# include    <unistd.h>
# include    <stdio.h>
# include    <signal.h>
# include    <stdlib.h>

int		ft_atoi(const char *str);
void	sighandel(int signalnum, siginfo_t *info, void *noting);
void	send_byts(int piid, char *bayt);
void	ft_putnbr(int n);
void	ft_check(int *save, char *byte, int *ch, int *i);
void	message_send(int message);

#endif