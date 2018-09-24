/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:08:30 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/22 21:08:33 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env()
{
    size_t  i;

    i = 0;
    while(g_env[i])
        ft_putendl(g_env[i++]);
}

void    ft_print_env_value(int index, int n)
{
    n++;
    while(g_env[index][n])
    {
        ft_putchar(g_env[index][n]);
        n++;
    }
}