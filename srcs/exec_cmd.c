/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:28:14 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_cmd(char *path, char **argv, char **envp)
{
	pid_t	id_fils;
	int		stat_loc;
	int		pid_son;

	id_fils = fork();
	if (id_fils == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, argv, envp);
	}
	else
	{
		pid_son = wait(&stat_loc);
	}
	return (1);
}
