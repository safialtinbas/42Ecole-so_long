/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:30:38 by saltinba          #+#    #+#             */
/*   Updated: 2023/01/07 16:30:40 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *c);
int		ft_find(char *finder);
char	*ft_line(char *handle_string);
char	*ft_clean(char *handle_string);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *lft_str, char *buff);

#endif
