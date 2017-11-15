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
** set a new env variable
*/

int	ft_setenv(char *name, char *value, char ***env)
{
	char	**envptr;
	char	*env_new;

	env_new = ft_strjoindelimiter(name, '=', value);
	if ((envptr = ft_getenv_ptr(name, *env)))
	{
		free(*envptr);
		*envptr = env_new;
	}
	else
		*env = ft_strtab_add(*env, env_new);
	return (1);
}
