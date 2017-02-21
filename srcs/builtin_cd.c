/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:33:58 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		cd_errors(char *path)
{
	struct stat	st;

	if (access(path, F_OK))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(path, 2);
	}
	else if (stat(path, &st) || !S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putstr_fd(path, 2);
	}
	else if (access(path, X_OK))
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putstr_fd(path, 2);
	}
	ft_putstr_fd("\n", 2);
}

int			builtin_cd(char **argv, char ***env)
{
	char *oldpwd;
	char *pwd;

	oldpwd = getcwd(NULL, 0);
	if (!chdir(argv[1]))
	{
		pwd = getcwd(NULL, 0);
		ft_setenv("PWD", pwd, env);
		ft_setenv("OLDPWD", oldpwd, env);
		free(pwd);
		free(oldpwd);
		return (1);
	}
	else
	{
		cd_errors(argv[1]);
		free(oldpwd);
		return (0);
	}
}
