/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 03:48:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/12 21:09:52 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n >= 0)
		n = -n;
	if (n <= -10)
		ft_putnbr(-(n / 10));
	ft_putchar('0' - (n % 10));
}
