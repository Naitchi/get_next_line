/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:36:32 by bclairot          #+#    #+#             */
/*   Updated: 2025/11/21 13:55:01 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_new_line(int fd, char *buffer, int *trigger)
{
	int	bytes;

	bytes = 0;
	init_zero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < BUFFER_SIZE)
		*trigger = 1;
}

char	*fuse_two_str(char *str, char *buffer)
{
	char	*rslt;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rslt = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 2));
	if (!rslt)
		return (NULL);
	while (i < ft_strlen(str))
	{
		rslt[i] = str[i];
		i++;
	}
	free(str);
	while (buffer[j] && buffer[j] != '\n')
	{
		rslt[i + j] = buffer[j];
		j++;
	}
	rslt[i + j] = buffer[j];
	j++;
	rslt[i + j] = '\0';
	return (rslt);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	trigger;
	char		*rslt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rslt = NULL;
	while (get_return(buffer) == -1)
	{
		rslt = fuse_two_str(rslt, buffer);
		get_new_line(fd, buffer, &trigger);
		if (trigger == 1 && buffer[0])
			break ;
		if (!buffer[0] && rslt[0])
			break ;
		if (trigger == 1)
			return (free_and_return(rslt));
	}
	rslt = fuse_two_str(rslt, buffer);
	if (get_return(buffer) != -1)
		strdup_from(buffer, buffer, get_return(buffer) + 1);
	else
		init_zero(buffer, BUFFER_SIZE + 1);
	return (rslt);
}

void	strdup_from(char *dest, char *src, int offset)
{
	int	i;

	i = 0;
	while (src[offset + i])
	{
		dest[i] = src[offset + i];
		i++;
	}
	dest[i] = '\0';
}

// int	main(void)
// {
// 	char *file_name;
// 	char *str;
// 	int fd;

// 	file_name = "hello.txt";
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	str = "";
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }