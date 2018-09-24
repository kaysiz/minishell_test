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
        ft_putstr("\tAuthor :ksiziva\n");
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
void	ft_exit()
{}
int	main(int ac, char **av, char **envp)
{
	ac = 0;
	av = 0;
	ft_envcpy(envp);

	// char	*input;
	// char	**arg;
	// int		i;
	// pid_t child_pid;
    // int stat_loc;

	// i = 0;
	// while (env[j] != '\0')
	// {
	// 	ft_printf("%s\n", env[j]);
	// 	j++;
	// }
	// ac = 0; av = 0; envp = 0;
	// while (1)
	// {
	// 	printf("input> ");
	// 	input = NULL;
	// 	get_next_line(0, &input);
	// 	arg = ft_strsplit(input, ' ');
	// 	free(input);
	// 	if (!arg[0]) {      /* Handle empty commands */
    //         free(input);
    //         free(arg);
    //         continue;
    //     }

    //     child_pid = fork();
    //     if (child_pid == 0) {
    //         /* Never returns if the call is successful */
    //         printf("This won't be printed if execvp is successul\n");
    //     } else {
    //         waitpid(child_pid, &stat_loc, WUNTRACED);
    //     }

    //     free(input);
    //     free(arg);
	// 	i = 0;
	// }
	char **command;
    char *input;
    pid_t child_pid;
	welcomeScreen();
    while (1) {
		ft_putstr("$> ");
        input = NULL;
        get_next_line(0, &input);
		command = ft_strsplit(input, ' ');
        if (!command[0]) {      /* Handle empty commands */
            free(input);
            free(command);
            continue;
        }

        child_pid = fork();
        if (child_pid == 0) {
			if(ft_strcmp(command[0], "env") == 0)
				ft_env();
			else if(ft_strcmp(command[0], "echo") == 0)
				ft_echo(command);
			else if(ft_strcmp(command[0], "cd") == 0)
				ft_putendl(command[0]);
			else if(ft_strcmp(command[0], "setenv") == 0)
				ft_putendl(command[0]);
			else if(ft_strcmp(command[0], "unsetenv") == 0)
				ft_putendl(command[0]);
			else if(ft_strcmp(command[0], "exit") == 0)
			{
				free(g_env);
				exit(0);
			}
			else
				execve(command[0], command, g_env);
        } else {
            wait(NULL);
        }

        free(input);
        free(command);
    }
	return(0);
}
