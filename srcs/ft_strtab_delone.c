/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:25:57 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/16 12:34:07 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** deletes the first string of the given tab with the same given string adress.
*/

void	ft_strtab_delone(char **tab, char *str)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i] != str)
		i++;
	if (tab[i] && tab[i] == str)
	{
		free(tab[i]);
		tab[i] = tab[i + 1];
	}
	while (tab[i])
	{
		tab[i] = tab[i + 1];
		i++;
	}
}
