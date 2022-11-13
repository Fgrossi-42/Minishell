/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:28:58 by aanghel           #+#    #+#             */
/*   Updated: 2022/10/16 21:45:15 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_get_next_line(t_main *main)
{
	int		rd;
	int		i;
	char	c;
	char	**rtr;
	char	*buffer;

	i = 0;
	buffer = malloc (9999);
	main->fd_matrix = open(FILE_MATRIX, O_CREAT | O_RDONLY, 0644);
	while ((rd = read(main->fd_matrix, &c, 1) > 0 ))
	{
		buffer[i] = c;
		i++;
		if (c == '\0')
			break ;
	}
	// if ((!buffer[i - 1] && !rd ) || rd == -1)
	// {
	// 	free(buffer);
	// 	return (NULL);
	// }
	buffer[i] = '\0';
	rtr = ft_split_original(buffer, '\n');
	return (rtr);
}
