/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:25:52 by ksiziva           #+#    #+#             */
/*   Updated: 2018/06/13 16:59:08 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * n + 1);
	if (s == NULL)
		return (NULL);
	s = ft_strncpy(s, str, n);
	s[n] = '\0';
	return (s);
}
