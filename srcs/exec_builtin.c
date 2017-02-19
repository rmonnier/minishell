/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:30:43 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtin(char *name, char **argv, char ***env)
{
	if (ft_strcmp(name, "cd") == 0)
		builtin_cd(argv, env);
	else if (ft_strcmp(name, "env") == 0)
		builtin_env(argv, *env);
	else if (ft_strcmp(name, "exit") == 0)
		builtin_exit(argv, *env);
	else if (ft_strcmp(name, "echo") == 0)
		builtin_echo(argv);
	else if (ft_strcmp(name, "pwd") == 0)
		builtin_pwd();
	else if (ft_strcmp(name, "setenv") == 0)
		builtin_setenv(argv, env);
	else if (ft_strcmp(name, "unsetenv") == 0)
		builtin_unsetenv(argv, env);
	return (1);
}
