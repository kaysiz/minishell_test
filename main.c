/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:14:04 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/17 09:33:59 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void welcomeScreen()
{
        ft_putstr("\n-------------------------------------------------\n");
        ft_putstr("\tWelcome to 42 Minishell  \n");
        ft_putstr("\tAuthor : ksiziva\n");
        ft_putstr("-------------------------------------------------\n");
        ft_putstr("\n\n");
		sleep(2);
}

int	ft_envlen(char **envp)
{
	int	i;

	i = 0;
	while(envp[i])
		i++;
	return (i);
}

void	ft_envcpy(char **envp)
{
	int len;
	int	i;

	i = 0;
	len = ft_envlen(envp);
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		g_env[i] = envp[i];
		i++;
	}
	g_env[i] = NULL;	
}
void	ft_clear()
{
	ft_putstr("\033[1;1H\033[2J");
}

int	main(int ac, char **av, char **envp)
{
	ac = 0;
	av = 0;
	ft_envcpy(envp);
	char **command;
    char *input;
	welcomeScreen();
    while (1) {

		ft_putstr("$> ");
        input = NULL;
        get_next_line(0, &input);
		command = ft_strsplit(input, ' ');
        if (!command[0]) 
		{  
            free(input);
            free(command);
            continue;
        }
		else if(ft_strcmp(command[0], "env") == 0)
			ft_env();
		else if(ft_strcmp(command[0], "echo") == 0)
			ft_echo(command);
		else if(ft_strcmp(command[0], "cd") == 0)
			ft_putendl(command[0]);
		else if(ft_strcmp(command[0], "setenv") == 0)
			ft_setenv(command);
		else if(ft_strcmp(command[0], "unsetenv") == 0)
			ft_unsetenv(command);
		else if(ft_strcmp(command[0], "clear") == 0)
			ft_clear();
		else if(ft_strcmp(command[0], "exit") == 0)
		{
			ft_putendl("\nGoodbye\n");
			exit(0);
		}
		else
			ft_exec(command);
        free(input);
        free(command);
    }
	sleep(50);
	return(0);
}
