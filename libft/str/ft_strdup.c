/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:33:10 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/12 21:15:53 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	char *dup;

	if (!src || !(dup = (char*)malloc(sizeof(*dup) * (ft_strlen(src) + 1))))
		return (NULL);
	dup = ft_strcpy(dup, src);
	return (dup);
}
