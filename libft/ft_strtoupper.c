/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:04:15 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/24 10:04:20 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
