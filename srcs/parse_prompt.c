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

static int		iswhite(char c)
{
	return ((c == ' ') || (c == '\n') || (c == '\t'));
}

static	int		number_of_words(char *str)
{
	int		n;

	n = 0;
	while (*str)
	{
		if (iswhite(*str))
			str++;
		else
		{
			n += 1;
			while (!iswhite(*str) && *str)
				str++;
		}
	}
	return (n);
}

char			**parse_prompt(char *str)
{
	int		i;
	int		j;
	int		n;
	char	**output;

	i = 0;
	n = number_of_words(str);
	output = (char **)ft_memalloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		j = 0;
		while (iswhite(*str))
			str++;
		while (!iswhite(str[j]) && str[j])
			j++;
		output[i] = ft_strndup(str, j);
		i++;
		str += j;
	}
	return (output);
}
