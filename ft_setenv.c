/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:08:45 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/22 21:08:47 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_setenv(char **command)
{
    char **temp;
    int len;
    int i;

    i = 0;
    len = ft_envlen(g_env);
    if(ft_isenv(command[1], ft_strlen(command[1])))
    {
        g_env[ft_isenv(command[1], ft_strlen(command[1]))] = \
        ft_strdup(ft_strjoin(ft_strjoin(command[1], "="), command[2]));
    }
    else
    {
        temp = (char **)malloc(sizeof(char *) * (len + 1));
        while(g_env[i])
        {
            temp[i] = g_env[i];
            i++;
        }
        temp[i] = ft_strdup(ft_strjoin(ft_strjoin(command[1], "="), command[2]));
        free(g_env);
        g_env = (char **)malloc(sizeof(char *) * (len + 2));
        i = 0;
        while(temp[i])
        {
            g_env[i] = temp[i];
            i++;
        }
        g_env[i] = NULL;
        free(temp);
    }
}
