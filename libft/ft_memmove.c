/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:55:47 by agigi             #+#    #+#             */
/*   Updated: 2020/11/03 00:27:54 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char *str;

	dst = dest;
	str = src;
	if (dst > str)
	{
		while (n--)
			dst[n] = str[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
