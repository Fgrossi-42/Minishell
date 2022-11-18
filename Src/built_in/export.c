/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:42:40 by pcatapan          #+#    #+#             */
/*   Updated: 2022/10/26 19:04:08 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_export_naked(t_token *token, t_main *main)
{
	int	i;

	i = 0;
	while (main->copy_env[i])
	{
		printf("declare -x %s\n", main->copy_env[i]);
		i++;
	}
	i = 0;
	while (main->export_env[i])
	{
		printf("declare -x %s\n", main->export_env[i]);
		i++;
	}
}

void	ft_add_to_env(t_token *token, char *var_add, t_main *main)
{
	int	j;

	if (ft_find_in_env(main->copy_env, var_add) != 0)
				j = ft_find_in_env(main->copy_env, var_add);
	else
	{
		j = ft_matrixlen(main->copy_env);
		main->copy_env[j + 1] = NULL;
	}
	free(main->copy_env[j]);
	main->copy_env[j] = ft_strdup(var_add);
}

void	ft_add_to_exp(char *var_add, t_main *main)
{
	int	j;


	// if (ft_find_in_exp(main->export_env, var_add) != 0)
	// 			j = ft_find_in_exp(main->export_env, var_add);
	// else
	// {
	j = ft_matrixlen(main->export_env);
	// }
	main->export_env[j] = ft_strdup(var_add);
	main->export_env[++j] = NULL;
}

void	ft_export(t_token *token, t_main *main)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (token->value[1] == NULL)
		return (ft_export_naked(token, main));
	while (token->value[i])
	{
		if (ft_strchr(token->value[i], '=') == 0
			|| ft_check_envi(token->value[i]) == 0)
		{
			if (ft_check_envi(token->value[i]) == 0)
				printf(RED"minishell: export: '%s': not a valid identifier\n"
					COLOR_RES, token->value[i]);
			else
				ft_add_to_exp(token->value[i], main);
			i++;
			continue ;
		}
		ft_add_to_env(token, token->value[i], main);
		i++;
	}
	// i = 0;
	// while (main->export_env[i])
	// 	printf("%s\n", main->export_env[i++]);
}
