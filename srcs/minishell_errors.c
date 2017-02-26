/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:56:46 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/25 15:56:48 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		minishell_errors(int error, char *str)
{
	if (error == NOTFOUND)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(str, 2);
	}
	else if (error == NOCWD)
	{
		ft_putstr_fd("pwd: no current working directory", 2);
	}
	ft_putstr_fd("\n", 2);
}
