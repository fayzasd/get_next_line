/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ver2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:34:43 by fasad             #+#    #+#             */
/*   Updated: 2021/10/27 15:42:15 by fasad            ###   ########.fr       */
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

char *gnlchr(char *str)
{
	int i;
	
	while(*str)
	{
		if(*str == '\n')
			break;
		str++;
	}
	return str;
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
	if (*final)
		temp = ft_strjoin(temp, final);
	if (str_scan(buf) >= 0)
		{
			final = ft_strdup(gnlchr(buf));
			return ft_substr(buf, 0, str_scan(buf) + 1);
		}
	else
	{
		temp = ft_strdup(buf);
		while (str_scan(buf) == -1 )
		{
			i = read(fd, buf, BUFFER_SIZE);
			temp = ft_strjoin(temp, buf);
		}
		if(str_scan(temp) >= 0)
			{
				final = ft_strdup(gnlchr(temp));
				temp = ft_substr(temp, 0, str_scan(temp) + 1);
			}
		//buf = ft_strdup(temp);
		return temp;
	}
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
