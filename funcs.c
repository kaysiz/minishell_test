/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:51:49 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/24 09:51:51 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_strtoupper(char *str)
{
    int i;
    char *res;

    i = 0;
    res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    while(str[i])
    {
        res[i] = ft_toupper(str[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}

char    *ft_strtolower(char *str)
{
    int i;
    char *res;

    i = 0;
    res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    while(str[i])
    {
        res[i] = ft_tolower(str[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}
