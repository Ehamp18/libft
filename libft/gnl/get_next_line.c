/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:34:44 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/12 22:13:48 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*line_new(char *str, char c)
{
	int				i;

	i = -1;
	if (!str || !c)
		return (0);
	while (str[++i] != c && str[i] != '\0')
		if (str[i] == c)
			break ;
	str = ft_strsub(str, str[0], i);
	return (str);
}

char				*new_str(char *str, char *sss)
{
	if ((ft_strchr(str, '\n')))
	{
		sss = ft_strchr(str, '\n') + 1;
		sss = ft_strdup(sss);
		free(str);
		str = sss;
	}
	else if ((ft_strchr(str, '\0')))
	{
		sss = ft_strchr(str, '\0');
		sss = ft_strdup(sss);
		free(str);
		str = sss;
	}
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*str[MAX_FD];
	char			*tmp;
	int				i;

	i = 0;
	RETY(fd < 0 || line == NULL, -1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		buf[i] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		if ((ft_strchr(tmp, '\n')))
		{
			*line = line_new(tmp, '\n');
			str[fd] = new_str(str[fd], tmp);
		}
		else
			ft_strcpy(str[fd], tmp);
		free(tmp);
	}
	RETY(*str[fd] == '\0', i);
	return (1);
}
