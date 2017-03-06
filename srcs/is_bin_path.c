/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:29:56 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_bin_path(char *path)
{
	struct stat	st;

	if (access(path, F_OK))
	{
		ft_putstr_fd("minishell: no such file or directory: ", 2);
		ft_putstr_fd(path, 2);
	}
	else if (stat(path, &st) || S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("minishell: is a directory: ", 2);
		ft_putstr_fd(path, 2);
	}
	else if (access(path, X_OK))
	{
		ft_putstr_fd("minishell: permission denied: ", 2);
		ft_putstr_fd(path, 2);
	}
	else
		return (1);
	ft_putstr_fd("\n", 2);
	return (0);
}
