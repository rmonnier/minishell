/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:28:35 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:29:12 by rmonnier         ###   ########.fr       */
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

char		**ft_strtabdup(char **tab)
{
	int		i;
	int		len;
	char	**output;

	len = tabsize(tab);
	output = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	i = 0;
	while (tab[i])
	{
		output[i] = ft_strdup(tab[i]);
		i++;
	}
	return (output);
}
