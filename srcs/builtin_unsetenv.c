/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:31:23 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unsetenv_one(char *env_entryname, char **env)
{
	char	**envptr;

	if ((envptr = ft_getenv_ptr(env_entryname, env)))
	{
		ft_strtab_delone(env, *envptr);
	}
	return (1);
}

int			builtin_unsetenv(char **argv, char **env)
{
	int		i;
	int		len;
	char	*env_entryname;

	i = 1;
	while (argv[i])
	{
		len = ft_strchr(argv[i], '=') - argv[i];
		env_entryname = strndup(argv[i], len);
		unsetenv_one(env_entryname, env);
		ft_strdel(&env_entryname);
		i++;
	}
	return (1);
}
