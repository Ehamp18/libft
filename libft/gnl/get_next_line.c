/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:34:44 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/24 05:30:33 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*line_print(char *str)
{
	int				j;
	char			*tmp;

	j = 0;
	while (str && str[j] != '\0' && str[j] != '\n')
		j++;
	tmp = ft_strsub(str, 0, j);
	return (tmp);
}

char				*new_str(char *str, char *sss)
{
	if (str && (ft_strchr(str, '\n')))
	{
		sss = ft_strchr(str, '\n') + 1;
		sss = ft_strdup(sss);
		free(str);
		str = sss;
	}
	else if (str && (ft_strchr(str, '\0')))
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
	char			buffer[BUFF_SIZE + 1];
	static char		*str[MAX_FD];
	char			*tmp;
	int				j;

	j = 0;
	ft_bzero(buffer, BUFF_SIZE);
	RETY(fd < 0 || line == NULL || fd >= MAX_FD || read(fd, buffer, 0) < 0, -1);
	while ((j = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!str[fd])
			str[fd] = ft_strnew(BUFF_SIZE);
		buffer[j] = '\0';
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		ft_bzero(buffer, BUFF_SIZE);
	}
	RETY(str[fd] && *str[fd] == '\0', j);
	*line = line_print(str[fd]);
	str[fd] = new_str(str[fd], tmp);
	return (1);
}

