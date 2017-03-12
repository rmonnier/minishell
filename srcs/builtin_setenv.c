/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/03/11 17:59:04 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_setenv(char **argv, char ***env)
{
	int		i;
	int		len;
	char	*env_name;
	char	*env_value;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '='))
		{
			len = ft_strchr(argv[i], '=') - argv[i];
			env_name = ft_strndup(argv[i], len);
			env_value = ft_strdup(argv[i] + len + 1);
			ft_setenv(env_name, env_value, env);
			ft_strdel(&env_name);
			ft_strdel(&env_value);
		}
		i++;
	}
	return (1);
}
