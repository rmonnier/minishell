/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:16:12 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 14:16:15 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoindelimiter(char const *s1, char delimiter, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*output;

	len = ft_strlen(s1) + 1 + ft_strlen(s2);
	if (!(output = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		output[j++] = s1[i++];
	output[j++] = delimiter;
	i = 0;
	while (s2[i])
		output[j++] = s2[i++];
	output[j] = '\0';
	return (output);
}
