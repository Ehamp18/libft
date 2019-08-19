/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:37:02 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/12 21:07:55 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_unsigned(uint64_t n)
{
	const char	index[10] = "0123456789";
	int			len;
	uint64_t	a;
	char		*asc;

	ZERO(!(asc = ft_strnew(ft_unumlen(n))));
	asc[0] = '0';
	if (n == 0)
		return (asc);
	a = n;
	len = 0;
	while (a)
	{
		len++;
		a /= 10;
	}
	a = n;
	while (len--)
	{
		asc[len] = index[a % 10];
		a /= 10;
	}
	return (asc);
}
