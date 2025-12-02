/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:06:49 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/02 13:11:57 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_zero(char *array, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		array[i] = '\0';
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	get_return(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*free_and_return(char *rslt, char *buffer)
{
	free(rslt);
	buffer[0] = '\0';
	return (NULL);
}
