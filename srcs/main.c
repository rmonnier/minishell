/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/25 15:54:45 by rmonnier         ###   ########.fr       */
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

/*
** if first word is :
** - a path, execute the file pointed to
** - a builtin command, execute builtin
** - a binary name, look into PATH for that binary
*/

int				exec_cmds(char **cmds, char ***env)
{
	char *cmd;

	cmd = cmds[0];
	if (!cmd)
		return (0);
	if (is_path(cmd))
	{
		if (is_valid_path(cmd))
			exec_cmd(cmd, cmds, *env);
	}
	else if (is_builtin(cmd))
	{
		exec_builtin(cmd, cmds, env);
	}
	else if ((cmd = get_cmd_path(cmd, *env)))
	{
		exec_cmd(cmd, cmds, *env);
		ft_strdel(&cmd);
	}
	else
	{
		minishell_errors(NOTFOUND, cmds[0]);
		return (-1);
	}
	return (1);
}

/*
** - ignore ctrl-c command (prevent exiting shell)
** - allocate a double tab for env variables and copy given ones
** - infinite loop which iterate on every string terminated by \n
**    - parse string into a tab
**    - execute commands
*/

int				main(int ac, char **av, char **env_ini)
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
