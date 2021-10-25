/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ver1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:22:55 by fasad             #+#    #+#             */
/*   Updated: 2021/10/25 17:25:42 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gnl_strjoin(char *str, char *join)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (*join)
	{
		str[i] = *join;
		i++;
		join++;
	}
	return str;
}

int check_str(char *str)
{
	int j = 0;
	while(str[j])
	{
		if(str[j] == '\n' || str[j] == '\0')
	  		return j;
		j++;
	}
	return -1;
}

#include <stdio.h>

char *get_next_line(int fd)
{
	int i;
	char *str;
	char *join;
	static char *final;

	if (fd < 0)
		return NULL;
	str = malloc(BUFFER_SIZE);
	join = malloc(BUFFER_SIZE);
	i = read(fd, str, BUFFER_SIZE);
	if (check_str(str) > 0)
		final = ft_substr(str, 0 ,(check_str(str) + 1));
	else
	{
		final = ft_strdup(str);
		while (check_str(join) < 0 && i > 0)
  		{
			i = read(fd, join, BUFFER_SIZE); 
			final = gnl_strjoin(final, join);
		}
	}
	free(str);
	free(join);
	return final;
}

int main()
{
	int fd = open("test.txt",O_RDONLY);
	char *str = get_next_line(fd);
	printf("str1 - %s",str);
	str = get_next_line(fd);
	printf("str2 - %s",str);
	// str = get_next_line(fd);
	// printf("str2 - %s",str);
}
