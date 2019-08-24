/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/24 05:01:08 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <wctype.h>

# define NEG_CHECK(x) if (x < 0) x *= -1
# define NEG_SI_PRNT(x, y) if (x < 0) y = '-'
# define FREE(x, y) if x free(y)
# define FREE2(x, y, z) if x free(y); free(z)
# define FE(x, y) x = y; free(y)
# define CPY(x, y) y = ft_strcat(y, x); free(x)
# define CHECK(x, y) if (x) y *= -1

# define BREAK(x) if (x) break ;
# define ZERO(x) if (x) return (0)
# define ERROR(x) if (x) return (-1)
# define RETZE(x) if (x) return ("0")
# define RETY(x, y) if (x) return (y)

# define REZE(x, y) if (x) y = "0"
# define INC(x, y) if (x) y++
# define DEC(x, y) if (x) y--
# define ONE(x, y) if (x) y = 1

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			hash;
	int			check;
	int			width;
	int			precis;
	int			sign;
	char		si;
	int			length;
}				t_flags;

typedef struct	s_count
{
	int			k;
	int			in;
	int			count;
	int			zero;
	int			wid;
}				t_val;

typedef	void	(*t_charat)(va_list conversions, t_flags *flags, t_val *val);

typedef struct	s_conv_check
{
	char		op;
	t_charat	kl;
}				t_check;

extern t_check	g_conver_check[];

/*
** Converstions
*/

int				ft_printf(const char *format, ...);
void			con_d(va_list options, t_flags *flags, t_val *val);
void			con_c(va_list options, t_flags *flags, t_val *val);
void			con_s(va_list options, t_flags *flags, t_val *val);
void			con_x(va_list options, t_flags *flags, t_val *val);
void			con_xa(va_list options, t_flags *flags, t_val *val);
void			con_p(va_list options, t_flags *flags, t_val *val);
void			con_o(va_list options, t_flags *flags, t_val *val);
void			con_u(va_list options, t_flags *flags, t_val *val);
void			con_b(va_list options, t_flags *flags, t_val *val);
void			con_per(t_flags *flags, t_val *val);
int				checks(va_list options, const char *format, t_val *val);
char			*plus_help(t_flags *flag, char *a, t_val *val);
char			*per_help(char *point, int perc, t_val *val);
char			*min_help(char *s, char *ans, t_flags *flag, t_val *val);
char			*min_help2(char *s, char *ans, t_flags *flag, t_val *val);
void			just_free(char *com, char *tmp);

#endif
