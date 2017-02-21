/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:48:11 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:34:35 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

#include <sys/uio.h>

int		builtin_cd(char **argv, char ***env);
void	builtin_echo(char **argv);
void	builtin_env(char **argv, char **env);
void	builtin_exit(char **argv, char **env);
int		builtin_pwd(void);
int		builtin_setenv(char **argv, char ***env);
int		builtin_unsetenv(char **argv, char **env);
int		exec_builtin(char *name, char **argv, char ***env);
int		exec_cmd(char *path, char **argv, char **envp);
char	*ft_getenv(char *name, char **env);
char	**ft_getenv_ptr(char *name, char **env);
int	ft_setenv(char *name, char *value, char ***env);
char	*ft_strjoindelimiter(char const *s1, char delimiter, char const *s2);
char	**ft_strtab_add(char **tab, char *str);
void ft_strtab_delone(char **tab, char *str);
char	**ft_strtab_dup(char **tab);
void	ft_strtab_free(char **tab);
void	ft_strtab_print(char **tab);
char	*get_bin_path(char *name, char **env);
int		is_builtin(char *str);
int		minishell_errors(int error, char *str);
char	**parse_prompt(char *str);

int		setenv_one(char *env_entryname, char *env_newentry, char ***env);

enum
{
	NOTFOUND,
	USAGE,
	MALL_ERR
};

#endif
