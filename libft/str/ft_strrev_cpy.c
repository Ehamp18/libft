/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:54:24 by ehamp             #+#    #+#             */
/*   Updated: 2019/08/12 21:11:39 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev_cpy(char *dst, const char *src)
{
	int			i;

	i = ft_strlen(src);
	while (i >= 0)
	{
		dst[i] = src[i];
		i--;
	}
	return (dst);
}
