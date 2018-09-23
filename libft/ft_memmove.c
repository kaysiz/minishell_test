/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:00:40 by ksiziva           #+#    #+#             */
/*   Updated: 2018/06/15 14:17:33 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (s == d)
		return (dest);
	if (d > s)
	{
		s = s + n - 1;
		d = d + n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}
