/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:48:11 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/16 12:39:46 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>

#include <sys/types.h>
#include <sys/uio.h>

char	*ft_strjoindelimiter(char const *s1, char delimiter, char const *s2);
void	ft_strtabfree(char **tab);
char	**ft_strtabdup(char **tab);
void	ft_strtabprint(char **tab);
char		**parse_prompt(char *str);
int		exec_cmd(char *path, char **argv, char **envp);
char	*get_path(char *name, char **env);

#endif
