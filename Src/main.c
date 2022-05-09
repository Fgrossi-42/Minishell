/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:29:44 by fgrossi           #+#    #+#             */
/*   Updated: 2022/05/09 12:34:27 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/minishell.h"

int	main(void)
{
	const char	*prompt;
	char		*string;

	string = readline(prompt);
	printf("%s", string);
}
