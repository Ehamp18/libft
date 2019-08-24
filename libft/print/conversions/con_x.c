/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/24 05:05:48 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*precision_x(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc <= i)
		return (ft_strdup(point));
	if (!perc)
		perc = 0;
	while (i >= 0 && perc)
	{
		res[perc] = point[i--];
		perc--;
	}
	while (perc >= 0)
	{
		res[perc] = '0';
		perc--;
	}
	return (res);
}

static char			*hash_x(char *s)
{
	if ((ft_atoi(s) > 0 || ft_isalpha(*s)))
		s = ft_ccstrjoini('0', 'x', s);
	return (s);
}

static void			wzm_help(int wid, char *ans, t_flags *fl)
{
	int				h;
	int				k;

	k = wid;
	while (wid > 0 && !fl->minus)
	{
		--wid;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && fl->minus)
	{
		--wid;
		ans[h++] = ' ';
	}
	while (ft_isdigit(ans[k]) && fl->zero && !fl->precis)
		k--;
	while (ans[k] && fl->zero && !fl->precis)
	{
		ans[k] = '0';
		k--;
	}
}

static char			*wid_zer_min_x(int wid, char *s, t_flags *fl)
{
	int				i;
	char			*ans;
	char			*tmp;

	if (wid < (int)ft_strlen(s))
	{
		ans = fl->hash ? ft_strdup(hash_x(s)) : 0;
		return (fl->hash ? ans : ft_strdup(s));
	}
	i = fl->minus ? -1 : ft_strlen(s);
	ans = ft_strnew(wid);
	if (fl->minus)
		while (s[++i] && wid--)
			ans[i] = s[i];
	else
		while (i-- > 0)
			ans[--wid] = s[i];
	wzm_help(wid, ans, fl);
	if (fl->hash)
	{
		tmp = ft_strnew(sizeof(char));
		tmp = free_copy(ans, tmp);
		FREE(((ans = hash_x(tmp))), tmp);
	}
	return (ans);
}

void				con_x(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_x((fl->length == 108 || fl->length == 216) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t));
	if (fl->precis || fl->precis == -1)
	{
		tmp = free_copy(com, tmp);
		com = precision_x(fl->precis, tmp);
	}
	if (fl->width)
	{
		tmp = free_copy(com, tmp);
		com = wid_zer_min_x(fl->width, tmp, fl);
	}
	if (fl->hash && !fl->width)
	{
		tmp = free_copy(com, tmp);
		com = hash_x(tmp);
	}
	val->k += ft_intputstr(com);
	just_free(com, tmp);
}
