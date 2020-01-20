/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:24:35 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:29:52 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define BUFF_SIZE 4
#define MAX_FD 10240

/*
**	When passed the address of a string and a file descriptor, the function
**	populates the string with the next line as read from the file descriptor.
**	It returns 1 if a new line is read, 0 if the end of the file is reached,
**	and -1 if an error occurs. The function can be called in a loop to read
**	an entire file.
*/

int	ft_gnl(char **str, char **line, int fd)
{
	char *next;
	char *tmp;

	if (!(next = ft_strchr(str[fd], '\n')))
	{
		if (!*str[fd])
			return (0);
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (1);
	}
	next++;
	*line = ft_strsub(str[fd], 0, next - str[fd] - 1);
	tmp = ft_strdup(str[fd] + (next - str[fd]));
	free(str[fd]);
	str[fd] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*str[MAX_FD];

	tmp = NULL;
	if (!line || fd < 0 || fd > MAX_FD || read(fd, 0, 0) == -1)
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = ft_strnew(0);
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		if (ret == -1 || (ret == 0 && ft_strchr(buff, '\0') == buff))
			return (ret == -1 ? -1 : 0);
	}
	return (ft_gnl(str, line, fd));
}
