/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:19:01 by fasad             #+#    #+#             */
/*   Updated: 2021/10/27 18:51:05 by fasad            ###   ########.fr       */
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

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			break;
		i++;
	}
	i++;
	return &str[i];
}

char *gnl_substr(char *str, int i)
{
	int j;
	char *trim;

	j = 0;
	trim = malloc(i + 1);
	while (j < i)
	{
		trim[j] = *str;
		j++;
		str++;
	}
	trim[j] = '\0';
	return trim;
}

char *get_next_line(int fd)
{
	int i;
	char *str;
	char *buf;
	static char *final;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buf = malloc(BUFFER_SIZE);
	str = malloc(BUFFER_SIZE);
	if (!str || !buf)
		return NULL;
	i = read(fd, buf, BUFFER_SIZE);
	if (*buf == '\0')
		return NULL;
	str = ft_strjoin(final, str);
	if (str_scan(buf) >= 0)
	{	
		 if ((int)ft_strlen(buf) > str_scan(buf))
			final = ft_strdup(gnlchr(buf));
		return gnl_substr(buf, str_scan(buf) + 1);
	}
	else
	{
		str = ft_strjoin(str, buf);
		while (i > 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if	(i != 0)
			 	str = ft_strjoin(str, buf);	
			if (str_scan(buf) >= 0)
			{
				 if ((int)ft_strlen(buf) > str_scan(buf))
					final = ft_strdup(gnlchr(buf));	
				break;
			}
			
		}
	}
	return str;
}

// int main()
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	close(fd);
// 	char *str = get_next_line(fd);
// 	printf("str1 - %s",str);
// 	// str = get_next_line(fd);
// 	// printf("str2 - %s",str);
// 	// str = get_next_line(fd);
// 	// printf("str2 - %s",str);
// 	// str = get_next_line(fd);
	
// }