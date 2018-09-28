/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 08:55:05 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/28 08:55:07 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"


static char	*exec_path(char *command)
{
	char	**path_env;
	char	*path;
	size_t	i;
    int j;

    j = ft_isenv("PATH",4);
	if (!access(command, F_OK))
		return (ft_strdup(command));
	path_env = ft_strsplit(ft_strsub(g_env[j],5,ft_strlen(g_env[j])), ':');
	if (!path_env)
		return (NULL);
	i = 0;
	while (path_env[i])
	{
        
        path = ft_strjoin(ft_strjoin(path_env[i], "/"), command);
        ft_putendl(path);
		if (!access(path, F_OK))
			break ;
		free(path);
		path = NULL;
		i++;
	}
	free(path_env);
	return (path);
}

void    ft_exec(char **command)
{
	int status;
    pid_t child_pid;
    char *path;

    path = exec_path(command[0]);
    if (!path)
	{
		ft_putendl("File not found!");
		return ;
	}
    child_pid = fork();
    if (child_pid == 0)
    {
        execve(path, command, g_env);
        ft_putstr("minishell: command not found: ");
        ft_putendl(command[0]);
    }
    else if(child_pid < 0)
        ft_putendl("Error forking");
    else {
        wait(&status);
    }
}