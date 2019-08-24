/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:55:15 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/24 05:00:54 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <wctype.h>
# include "ft_printf.h"

/*
** Structs list
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Macros
*/

# define BUFF_SIZE 32
# define MAX_FD 4865
# define BREAK(x) if (x) break ;
# define ZERO(x) if (x) return (0)
# define NEG_CHECK(x) if (x < 0) x *= -1
# define NEG_SI_PRNT(x, y) if (x < 0) y = '-'
# define FREE(x, y) if x free(y)
# define FREE2(x, y, z) if x free(y); free(z)
# define FE(x, y) x = y; free(y)
# define CPY(x, y) y = ft_strcat(y, x); free(x)
# define ERROR(x) if (x) return (-1)
# define CHECK(x, y) if (x) y *= -1
# define RETZE(x) if (x) return ("0")
# define REZE(x, y) if (x) y = "0"
# define RETY(x, y) if (x) return (y)
# define INC(x, y) if (x) y++
# define DEC(x, y) if (x) y--
# define ONE(x, y) if (x) y = 1

/*
** Functions
*/
int					ft_atoi(const char *str);
char				ft_atoc(unsigned int asc);

void				ft_bzero(void *s, size_t n);

char				*ft_ccstrjoin(char s1, char s2, char *s3);
char				*ft_ccstrjoini(char s1, char s2, char *s3);
char				*ft_cstrjoin(char s1, char *s2);
char				*ft_cstrjoini(char s1, char *s2, t_flags *flag);

int					ft_intputstr(char const *s);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isint(int c);
int					ft_isprint(int c);
char				ft_is_lower(char c);
int					ft_is_space(char c);
char				ft_is_upper(char c);
char				*ft_itoa(int64_t n);
char				*ft_itoa_b(uint64_t n);
char				*ft_itoa_base(int n, int base);
char				*ft_itoa_base_unsigned(uint64_t n, int base);
char				*ft_itoa_cx(uint64_t n);
char				*ft_itoa_long(long n);
char				*ft_itoa_o_unsigned(uint64_t n);
char				*ft_itoa_u_p(intptr_t n);
char				*ft_itoa_unsigned(uint64_t n);
char				*ft_itoa_x(uint64_t n);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *tr, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev_cpy(char *dst, const char *src);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *hay, const char *need);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

int					ft_numlen(uint64_t num);
int					ft_tabs(char c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_unumlen(uint64_t num);
size_t				ft_wordcount(char const *s, char c);

char				*free_copy(char *com, char *tmp);

int					get_next_line(const int fd, char **line);

#endif
