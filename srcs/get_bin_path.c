/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/25 16:41:33 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		in_folder(char *binfolder, char *name)
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
** returns a malloced path of the command "name",
** or NULL if the command is not found
*/

char			*get_bin_path(char *name, char **env)
{
	int		i;
	char	**bin_folders;
	char	*path;
	char	*path_env;

	if (!(path_env = ft_getenv("PATH", env)))
		return (NULL);
	bin_folders = ft_strsplit(path_env, ':');
	path = NULL;
	i = 0;
	while (bin_folders[i])
	{
		if (in_folder(bin_folders[i], name))
		{
			path = ft_strjoindelimiter(bin_folders[i], '/', name);
			break ;
		}
		i++;
	}
	ft_strtab_free(bin_folders);
	return (path);
}
