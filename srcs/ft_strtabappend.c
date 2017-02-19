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

char		**ft_strtabappend(char **tab, char *str)
{
	int		i;
	int		len;
	char	**output;

	len = tabsize(tab) + 1;
	output = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	output[0] = ft_strdup(str);
	i = 1;
	while (i < len)
	{
		output[i] = ft_strdup(tab[i - 1]);
		free(tab[i - 1]);
		i++;
	}
	free(tab);
	return (output);
}
