/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:44:10 by pcatapan          #+#    #+#             */
/*   Updated: 2022/07/10 20:22:00 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Free the matrix
 * 
 * @param matrix is the matrix to free
 */
void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
