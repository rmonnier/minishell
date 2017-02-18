/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/16 17:10:58 by rmonnier         ###   ########.fr       */
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
		execve(path, argv, envp);
	}
	else
	{
		pid_son = wait(&stat_loc);
		//ft_printf("argv %p pour %s et envp %p pour %s\n", *argv, *argv, *envp, *envp);
		//ft_printf("%d et %d\n", stat_loc, pid_son);
	}
	return (1);
}
