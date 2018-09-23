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

void    ft_echo_env(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(ft_isalpha(str[i]))
            ft_putchar(ft_toupper(str[i]));
        else
            ft_putchar(str[i]);
        i++;
    }
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
