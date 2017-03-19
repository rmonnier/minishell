/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:43:50 by rmonnier          #+#    #+#             */
/*   Updated: 2017/03/18 15:43:54 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_echo(char **argv)
{
	int	i;
	int	first;

	i = 1;
	first = 1;
	while (argv[i])
	{
		if (first == 1)
			ft_printf("%s", argv[i]);
		else
			ft_printf(" %s", argv[i]);
		i++;
	}
	ft_printf("\n");
}
