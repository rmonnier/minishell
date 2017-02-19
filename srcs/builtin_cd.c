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

static char	*new_env(char *name, char *content)
{
	char *new_env;

	new_env = ft_strjoin(name, content);
	free(content);
	return (new_env);
}

int			builtin_cd(char **argv, char ***env)
{
	char *oldpwd;
	char *pwd;

	oldpwd = getcwd(NULL, 0);
	if (!chdir(argv[1]))
	{
		pwd = getcwd(NULL, 0);
		oldpwd = new_env("OLDPWD=", oldpwd);
		pwd = new_env("PWD=", pwd);
		setenv_one("PWD", pwd, env);
		setenv_one("OLDPWD", oldpwd, env);
		free(pwd);
	}
	free(oldpwd);
	return (1);
}
