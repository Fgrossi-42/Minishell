/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:31:19 by fgrossi           #+#    #+#             */
/*   Updated: 2022/05/13 15:47:10 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_utils {
    const char	*prompt;
	char		*string;
	int a;
	int b;
	int result;
}	t_utils;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
int	ft_strnstr(const char *str, const char *to_find, size_t len);

#endif