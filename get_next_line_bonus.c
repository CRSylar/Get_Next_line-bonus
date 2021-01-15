/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:08:53 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/13 19:09:20 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int		ft_readnstore(t_buff *find, char **line)
{
	size_t	i;
	size_t	j;
	int		retval;

	i = ft_strlen(*line);
	if (!ft_realloc(line, i))
		return (-1);
	retval = 0;
	j = 0;
	while (find->buffer[j])
	{
		(*line)[i++] = find->buffer[j];
		if (find->buffer[j++] == '\n')
		{
			--i;
			retval = 1;
			break ;
		}
	}
	(*line)[i] = 0;
	i = 0;
	while (find->buffer[j])
		find->buffer[i++] = find->buffer[j++];
	find->buffer[i] = 0;
	return (retval);
}

static	int		get_error_fd(char **line)
{
	if (*line)
		free(*line);
	*line = 0;
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	int				retval;
	int				nbyte;
	static t_buff	*head;
	t_buff			*find;

	if (BUFFER_SIZE <= 0 || (fd < 0) || !line
		|| (!head && !(head = ft_lstnew(fd)))
		|| !(find = ft_trovafd(fd, head)))
		return (-1);
	*line = 0;
	if ((retval = ft_readnstore(find, line)))
		return (retval);
	while ((nbyte = read(fd, find->buffer, BUFFER_SIZE)) > 0)
	{
		find->buffer[nbyte] = 0;
		if ((retval = ft_readnstore(find, line)))
			return (retval);
	}
	if (nbyte < 0)
		return (get_error_fd(line));
	ft_cleanbuf(&head, fd);
	return (nbyte);
}
