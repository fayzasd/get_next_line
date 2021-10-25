/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:34:43 by fasad             #+#    #+#             */
/*   Updated: 2021/10/25 18:49:04 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int str_scan(char *str)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '\n')
			return j;
		j++;
	}
	return -1;
}

char *get_next_line(int fd)
{
	int i;
	int j;
	char *buf;
	char *temp;
	static char *final;

	i = 0;
	buf = malloc(BUFFER_SIZE);
	temp = malloc(BUFFER_SIZE);
	if (fd < 0)
		return NULL;
	i = read(fd, buf, BUFFER_SIZE);
	while (final)
		buf = ft_strjoin(buf, final);
	if (str_scan(buf) >= 0)
		return ft_substr(buf, 0, str_scan(buf) + 1);
	final = ft_strdup(buf);
	while (str_scan(buf) == -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		temp = ft_strjoin(temp, buf);
	}
	if(str_scan(buf) >= 0)
		final = ft_strrchr(buf, '\n');
	buf = ft_strdup(temp);
	return buf;
}

int main()
{
	int fd = open("test.txt",O_RDONLY);
	char *str = get_next_line(fd);
	printf("str1 - %s",str);
	//	str = get_next_line(fd);
	//	printf("str2 - %s",str);
	// str = get_next_line(fd);
	// printf("str2 - %s",str);
}
