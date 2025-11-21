/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:36:32 by bclairot          #+#    #+#             */
/*   Updated: 2025/11/21 13:52:38 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

void	get_new_line(int fd, char *buffer, int *trigger);
char	*get_next_line(int fd);
void	strdup_from(char *dest, char *src, int offset);
int		get_return(char *str);
char	*fuse_two_str(char *str, char *buffer);
void	init_zero(char *array, int length);
int		ft_strlen(const char *s);
char	*free_and_return(char *rslt);

#endif
