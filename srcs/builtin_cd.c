/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/25 16:39:51 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		cd_errors(char *path)
{
	struct stat	st;

	if (access(path, F_OK))
	{
		ft_putstr_fd("minishell: cd: no such file or directory: ", 2);
		ft_putstr_fd(path, 2);
	}
	else if (stat(path, &st) || !S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("minishell: cd: not a directory: ", 2);
		ft_putstr_fd(path, 2);
	}
	else if (access(path, X_OK))
	{
		ft_putstr_fd("minishell: cd: permission denied: ", 2);
		ft_putstr_fd(path, 2);
	}
	ft_putstr_fd("\n", 2);
}

static char		*get_path_tilda(char **argv, char **env)
{
	char *home;
	char *path;

	home = ft_getenv("HOME", env);
	path = ft_strjoindelimiter(home, '/', argv[1] + 1);
	return (path);
}

static char		*get_path(char **argv, char **env)
{
	char *path;

	if (!argv[1])
		path = ft_strdup(ft_getenv("HOME", env));
	else if (argv[1][0] == '-')
	{
		path = ft_getenv("OLDPWD", env);
		if (path)
		{
			path = ft_strdup(path);
			ft_printf("%s\n", path);
		}
		else
			minishell_errors(NOCWD, NULL);
	}
	else if (argv[1][0] == '~')
	{
		path = get_path_tilda(argv, env);
	}
	else
		path = ft_strdup(argv[1]);
	return (path);
}

int				builtin_cd(char **argv, char ***env)
{
	char *oldpwd;
	char *pwd;
	char *path;

	if (!(path = get_path(argv, *env)))
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		pwd = getcwd(NULL, 0);
		ft_setenv("PWD", pwd, env);
		if (oldpwd)
		{
			ft_setenv("OLDPWD", oldpwd, env);
			free(oldpwd);
		}
		free(pwd);
	}
	else
	{
		cd_errors(path);
		free(oldpwd);
	}
	free(path);
	return (0);
}
