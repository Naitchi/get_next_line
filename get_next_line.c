/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:36:32 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/02 14:18:45 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_new_line(int fd, char *buffer, int *bytes)
{
	init_zero(buffer, BUFFER_SIZE + 1);
	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes < 0)
		buffer[0] = 0;
}

char	*fuse_two_str(char *str, char *buffer)
{
	char	*rslt;
	int		i;
	int		j;
	int		len_str;

	len_str = ft_strlen(str);
	i = -1;
	j = 0;
	rslt = malloc(sizeof(char) * (len_str + ft_strlen(buffer) + 2));
	if (!rslt)
		return (NULL);
	while (++i < len_str)
		rslt[i] = str[i];
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
	static int	bytes;
	char		*rslt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rslt = NULL;
	bytes = 1;
	while (get_return(buffer) == -1 && bytes)
	{
		rslt = fuse_two_str(rslt, buffer);
		get_new_line(fd, buffer, &bytes);
		if (bytes < 0)
			return (free_and_return(rslt, buffer));
	}
	rslt = fuse_two_str(rslt, buffer);
	if (bytes == 0 && (!rslt || (rslt && !rslt[0])) && !buffer[0])
		return (free_and_return(rslt, buffer));
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

// 	file_name = "empty.txt";
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	str = "";
// 	while (str)
// 	{
// 		// printf("test\n");
// 		str = get_next_line(1000);
// 		printf("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }