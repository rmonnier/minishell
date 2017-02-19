/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:33:20 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_binfolders(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_strsplit(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

int		isinfolder(char *binfolder, char *name)
{
	DIR				*dir;
	struct dirent	*entry;

	if (!(dir = opendir(binfolder)))
	{
		return (0);
	}
	while ((entry = readdir(dir)))
	{
		if (ft_strcmp(name, entry->d_name) == 0)
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

/*
**get_path
**returns a malloced path of the command "name",
**or NULL if the command is not found
*/

char	*get_path(char *name, char **env)
{
	char	**begin;
	char	**binfolders;
	char	*path;
	char	*path_env;

	path = NULL;
	binfolders = NULL;
	if ((path_env = ft_getenv("PATH", env)))
		binfolders = ft_strsplit(path_env, ':');
	begin = binfolders;
	while (*binfolders)
	{
		if (isinfolder(*binfolders, name))
		{
			path = ft_strjoindelimiter(*binfolders, '/', name);
			break ;
		}
		binfolders++;
	}
	ft_strtabfree(begin);
	return (path);
}
