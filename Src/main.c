/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:29:44 by fgrossi           #+#    #+#             */
/*   Updated: 2022/05/12 16:26:59 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/minishell.h"

char	*type(t_utils *var)
{	
	var->string = NULL;
	while(1)
	{	
		printf("bash-4.2$ ");
		var->string = readline(var->prompt);
		if(var->string != NULL)
			break;
	}
	return(var->string);
}

void	ft_echo(char	*line, t_utils *var)
{
	int i;

	i = 5;
	while(line[i] != '\0')
	{
		write(1, &line[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void check_command(t_utils *var)
{
	char	*command;
	
	command = "temp";
	while(1)
	{
		command = type(var);
		if(!ft_strncmp(command, "ls", ft_strlen(command)))
			printf("ls detected\n");
		else if(!ft_strncmp(command, "pwd", ft_strlen(command)))
			printf("pwd detected\n");
		else if(!ft_strncmp(command, "cd", ft_strlen(command)))
			printf("cd detected\n");
		else if(!ft_strncmp(command, "pollo", ft_strlen(command)))
			printf("pollo detected\n");
		else if(!ft_strncmp(command, "git clone", ft_strlen(command)))
			printf("git clone detected\n");
		else if(!ft_strncmp(command, "echo", ft_strlen("echo")))
			ft_echo(command, var);
		else if(!ft_strncmp(command, "exit", ft_strlen("echo")))
			exit(0);
		else
		printf("bash: %s: command not found\n", command);
		free(command);
	}
}

int	main(void)
{
	t_utils		var;

	check_command(&var);
	return (0);
}
