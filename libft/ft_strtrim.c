/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:42:43 by ksiziva           #+#    #+#             */
/*   Updated: 2018/06/17 17:13:17 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace2(int c)
{
	char			*space;

	space = "\t\n ";
	while (*space)
	{
		if (c == *space)
			return (1);
		space++;
	}
	return (0);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*res;

	i = 0;
	j = 0;
	k = -1;
	if (s == NULL)
		return (NULL);
	while (ft_isspace2(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while (ft_isspace2(s[j]))
		j--;
	if (!(res = ft_strnew(j - i + 1)))
		return (NULL);
	while (++k < j - i + 1)
		res[k] = s[i + k];
	return (res);
}
