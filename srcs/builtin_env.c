/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:56:26 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/25 16:40:37 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_modified_env(char **argv, char **env)
{
	char	**modified_env;
	char	*cmd;
	int		i;

	i = 1;
	modified_env = ft_strtab_dup(env);
	while (argv[i] && ft_strchr(argv[i], '='))
		i++;
	cmd = argv[i];
	argv[i] = NULL;
	builtin_setenv(argv, &modified_env);
	argv[i] = cmd;
	if (argv[i])
		exec_cmds(argv + i, &modified_env);
	else
		ft_strtab_print(modified_env);
	ft_strtab_free(modified_env);
}

void		builtin_env(char **cmds, char **env)
{
	if (cmds[1] == NULL)
		ft_strtab_print(env);
	else
		exec_modified_env(cmds, env);
}
