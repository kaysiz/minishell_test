/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:09:04 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/22 21:09:06 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unsetenv(char **command)
{
    char **temp;
    int len;
    int i;
    int j;

    i = 0;
    j = 0;
    len = ft_envlen(g_env);
    if(ft_isenv(command[1], ft_strlen(command[1])))
    {
        temp = (char **)malloc(sizeof(char *) * (len + 1));
        while(g_env[i])
        {
            if(i == ft_isenv(command[1], ft_strlen(command[1])))
                i++;
            else
            {
                temp[j] = g_env[i];
                i++;
                j++;
            }
        }
        free(g_env);
        g_env = (char **)malloc(sizeof(char *) * (len + 1));
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