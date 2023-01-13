/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:01:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/12/05 17:01:48 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (dst);
}
