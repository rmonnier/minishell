/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:52:02 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/15 19:42:52 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		main(void)
{
	char *str;

	ft_printf("Welcome to minishell - version 0.1\n");
	ft_printf("Enter your command: > ");
	while (get_next_line(0, &str))
	{
		ft_printf("%s\n", str);
		ft_printf("Enter your command: > ");
	}
	return (1);
}
