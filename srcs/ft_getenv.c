/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:34:30 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/16 12:42:52 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** returns the value of the given env variable name
*/

char	*ft_getenv(char *name, char **env)
{
	int		len;
	int		i;

	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(name, env[i], len) == 0)
		{
			if (*(env[i] + len) == '=')
				return (env[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
