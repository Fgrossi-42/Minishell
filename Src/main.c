/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:29:44 by fgrossi           #+#    #+#             */
/*   Updated: 2022/05/13 15:46:51 by fgrossi          ###   ########.fr       */
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

	if(!(i = ft_strnstr(line, "-n", ft_strlen(line))))
		i = 5;
	while(line[i] == ' ')
		i++;
	while(line[i] != '\0')
	{
		if(line[i] == 34)
		{
			i++;
			while(line[i] != '\0')
			{
				if(line[i] == 34)
				{
					i++;
					break;
				}
				else
				{
					write(1, &line[i], 1);
					i++;
				}
			}
		}
		if(line[i] == ' ' && line[i + 1] == ' ')
			i++;
		else
		{
			write(1, &line[i], 1);
			i++;
		}
	}
	if(!(ft_strnstr(line, "-n", ft_strlen(line))))
		write(1, "\n", 1);
}

void check_command(t_utils *var)
{
	char	*command;
	
	command = "temp";
	while(1)
	{
		command = type(var);
		if(!ft_strncmp(command, "ls", ft_strlen("ls")))
			printf("ls detected\n");
		else if(!ft_strncmp(command, "pwd", ft_strlen("pwd")))
			printf("pwd detected\n");
		else if(!ft_strncmp(command, "cd", ft_strlen("cd")))
			printf("cd detected\n");
		else if(!ft_strncmp(command, "pollo", ft_strlen("pollo")))
			printf("pollo detected\n");
		else if(!ft_strncmp(command, "git clone", ft_strlen("git clone")))
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

int	main(int argc, char **argv, char **envp)
{
	t_utils		var;
	
	check_command(&var);
	return (0);
}
