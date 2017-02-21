/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabappend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:29:21 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:29:40 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	tabsize(char **tab)
{
	int		n;

	n = 0;
	while (*tab)
	{
		n++;
		tab++;
	}
	return (n);
}

/*
** returns a new malloced tab.
** the given string is added.
** the old tab is freed.
*/

char		**ft_strtab_add(char **tab, char *str)
{
	int		i;
	int		len;
	char	**output;

	len = tabsize(tab) + 1;
	output = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	i = 0;
	while (i < len - 1)
	{
		output[i] = tab[i];
		i++;
	}
	output[i] = str;
	free(tab);
	return (output);
}
