/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:08:10 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/22 21:08:12 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isenv(char *str, int n)
{
    int i;

    i = 0;
    while(g_env[i])
    {
        if(ft_strequ(ft_strsub(g_env[i], (unsigned int)0, (size_t)n), ft_strtoupper(str)))
            return (i);
        i++;
    }
    return(0);
}

void    ft_echo_env(char *str)
{
    int i;
    int j;
    char *res;

    res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    i = 1;
    j = 0;
    while(str[i])
    {
        if(ft_isalpha(str[i]))
            res[j++] = str[i];
        i++;
    }
    if(!ft_isenv(res, ft_strlen(str) - 1))
        ft_putstr("\n");
    else
        ft_print_env_value(ft_isenv(res, ft_strlen(str) - 1),ft_strlen(str) - 1);
        
}

void    ft_putstrq(char *str)
{
    int i;

    i = 0;
    if(str[i] == '$')
        ft_echo_env(str);
    else
    {
        while(str[i])
        {
            if(str[i] == '"' || str[i] == '\'')
                i++;
            else
                ft_putchar(str[i++]);
        }
        ft_putchar(' ');
    }
    
}

void    ft_echo(char **command)
{
    size_t  i;

    i = 1;
    while(command[i])
        ft_putstrq(command[i++]);
    ft_putchar('\n');
}
