/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_unsetenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:17:43 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/13 22:51:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static int	push_new_env_without_name(char **new_env,
	size_t len_env, const char *name)
{
	size_t	i;
	size_t	j;
	size_t	len_name;

	i = 0;
	j = 0;
	len_name = ft_strnlen(name, '=');
	while (i < (len_env - 1) && (g_sh_environ[j]))
	{
		if (!ft_memcmp(g_sh_environ[j], name, len_name) &&
			g_sh_environ[j][len_name] == '=')
		{
			j++;
		}
		else
		{
			new_env[i] = ft_strdup(g_sh_environ[j]);
			if (!new_env[i])
				return (FAILURE);
			++i;
			++j;
		}
	}
	new_env[len_env - 1] = NULL;
	return (SUCCESS);
}

static int	delete_var_env(const char *name)
{
	size_t			len_env;
	char			**new_env;
	enum e_err		err;

	len_env = ft_lineslen(g_sh_environ);
	new_env = (char **)ft_memalloc(sizeof(char *) * (len_env));
	if (!new_env)
		err = FAILURE;
	err = push_new_env_without_name(new_env, len_env, name);
	ft_strdel_split(g_sh_environ);
	free(g_sh_environ);
	if (err != FAILURE)
		g_sh_environ = new_env;
	return (err);
}

int			sh21_unsetenv(const char *name)
{
	int				index;
	enum e_err		err;

	err = FAILURE;
	if (name && *name)
	{
		index = find_var_env(name);
		if (index != -1)
			err = delete_var_env(name);
	}
	return (err);
}
