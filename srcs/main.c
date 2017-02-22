/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:31:10 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_path(char *str)
{
	while (*str)
	{
		if (*str == '/')
			return (1);
		str++;
	}
	return (0);
}

int		exec_cmds(char **cmds, char ***env)
{
	char *path;

	path = cmds[0];
	if (!path)
		return (0);
	if (is_path(path))
	{
		exec_cmd(path, cmds, *env);
	}
	else if (is_builtin(path))
	{
		exec_builtin(path, cmds, env);
	}
	else if ((path = get_bin_path(path, *env)))
	{
		exec_cmd(path, cmds, *env);
		ft_strdel(&path);
	}
	else
	{
		minishell_errors(NOTFOUND, cmds[0]);
		return (-1);
	}
	return (1);
}

int		main(int ac, char **av, char **env_ini)
{
	char	*line;
	char	**env;
	char	**cmds;

	(void)ac;
	(void)av;
	signal(SIGINT, SIG_IGN);
	env = ft_strtab_dup(env_ini);
	ft_printf("Welcome to minishell - version 0.1\n");
	while (ft_printf("$> ") && get_next_line(0, &line) == 1)
	{
		cmds = parse_prompt(line);
		ft_strdel(&line);
		exec_cmds(cmds, &env);
		ft_strtab_free(cmds);
	}
	ft_strtab_free(env);
	return (0);
}
