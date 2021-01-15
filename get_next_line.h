/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:10:14 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/13 19:12:35 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_buff
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_buff	*next;
}				t_buff;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
t_buff			*ft_lstnew(int fd);
t_buff			*ft_trovafd(int fd, t_buff *buffer);
int				ft_realloc(char **line, size_t len);
void			ft_freebuffer(t_buff *head, int fd);
void			ft_cleanbuf(t_buff **toclean, int fd);

#endif
