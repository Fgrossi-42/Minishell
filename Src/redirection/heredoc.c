/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:52 by pcatapan          #+#    #+#             */
/*   Updated: 2022/12/05 16:59:56 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//main->expand == false -> no expand dollar
//main->expand == true -> expand dollar

int	ft_write_fd(int fd, char *limiter, t_main *main)
{
	char	*str;

	main->expand = ft_strchr(limiter, '"');
	limiter = ft_strtrim2(limiter, '"');
	while (1)
	{
		str = readline("> ");
		if (ft_strcmp(limiter, str) == 1)
			break ;
		if (main->expand == 0)
		{
			if (ft_strchr(str, '$') == 1)
				str = ft_expand_heredoc(str, main);
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
	free(str);
	return (0);
}

void	ft_change_name_file(t_main *main, t_token *token, char redir)
{
	int		start;
	char	*tmp;
	int		end;

	start = ft_strlen(main->copy_line);
	end = 1;
	while (main->copy_line[start] != redir)
		start--;
	start++;
	while (main->copy_line[start] == 32 \
			&& main->copy_line[start])
		start++;
	while (main->copy_line[start + end] != 32 \
			&& main->copy_line[start + end])
		end++;
	tmp = ft_substr(main->copy_line, start, end);
	free(token->name_file);
	token->name_file = ft_strdup(tmp);
	free(tmp);
}

void	ft_heredoc(t_token *token, t_main *main)
{
	int		fd;
	char	*n_file;

	token->dup = dup(STDIN_FILENO);
	n_file = ".heredoc";
	free(token->name_file);
	token->name_file = NULL;
	ft_search_redir(token, "<<");
	fd = open (n_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	ft_write_fd(fd, token->name_file, main);
	fd = open (n_file, O_RDWR);
	dup2(fd, STDIN_FILENO);
	if (ft_set_bool_redir(token, ">"))
		ft_change_name_file(main, token, '>');
	if (fd == -1)
	{
		perror(RED ERROR_FILE COLOR_RES);
		write(fd, "1", 1);
		g_exit = 1;
		exit(1);
	}
}

char	*ft_find_name_file(char *str)
{
	int		start;
	int		end;
	int		delete;
	char	*rtr;

	start = 0;
	end = 0;
	while (str[start] == 32)
		start++;
	while (str[start + end] != 32 && str[start + end])
		end++;
	rtr = ft_substr(str, start, end);
	delete = start + end;
	while (delete != -1)
		str[delete--] = 127;
	return (rtr);
}
