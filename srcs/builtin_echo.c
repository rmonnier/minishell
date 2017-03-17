/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/03/17 12:11:13 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_echo(char **argv, char **env)
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
