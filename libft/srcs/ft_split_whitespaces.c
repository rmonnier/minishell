/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/09 12:56:05 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	number_of_words(char *str)
{
	int		n;

	n = 0;
	while (*str)
	{
		if (ft_iswhite(*str))
			str++;
		else
		{
			n += 1;
			while (!ft_iswhite(*str) && *str)
				str++;
		}
	}
	return (n);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		n;
	char	**output;

	i = 0;
	n = number_of_words(str);
	output = (char **)malloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		j = 0;
		while (ft_iswhite(*str))
			str++;
		while (!ft_iswhite(str[j]) && str[j])
			j++;
		output[i] = ft_strndup(str, j);
		i++;
		str += j;
	}
	output[i] = 0;
	return (output);
}
