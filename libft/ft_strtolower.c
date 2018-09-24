/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:04:04 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/24 10:04:07 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
