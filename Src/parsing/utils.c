/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:01:24 by pcatapan          #+#    #+#             */
/*   Updated: 2022/09/28 23:41:56 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*ft_return_head(t_token *list)
{
	while (list)
	{
		if (!list->prev)
			break ;
		list = list->prev;
	}
	return (list);
}
