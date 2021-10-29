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
	char *temp;
	i = 0;
	
	temp = malloc(ft_strlen(str)-str_scan(str));
	while(str[i] != '\n')
		i++;
	i++;
	while(str[i])
		{
			*temp = str[i];
			temp++;
			i++;
		}
	return temp;
}

char *gnl_substr(char *str, int i)
{
	int j;
	int k;
	char *trim;

	j = 0;
	k = 0;
	trim = malloc(i + 1);
	while (j < i)
	{
		trim[k] = str[j];
		j++;
		k++;
	}
	//trim[k] = '\0';
	return trim;
}

char *get_next_line(int fd)
{
	int i;
	char *str;
	char *buf;
	static char *final;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return "1";
	buf = malloc(BUFFER_SIZE);
	str = malloc(BUFFER_SIZE);
	final = ft_strdup("");
	if (!str || !buf)
		return "2";
	i = read(fd, buf, BUFFER_SIZE);
	if (str_scan(buf) >= 0)
	{	
		if ((int)ft_strlen(buf) > str_scan(buf))
			final = ft_strdup(gnlchr(buf));
		return gnl_substr(buf, str_scan(buf) + 1);
	}
	else
	{
		str = ft_strjoin(final, str);
		str = ft_strjoin(str, buf);
		while (i > 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if	(str_scan(buf) < 0)
			{
				str = ft_strjoin(str, buf);	
				break;
			}
		}
			//if (str_scan(buf) >= 0)
				 if ((int)ft_strlen(buf) > str_scan(buf))
					{
						buf = gnl_substr(buf, str_scan(buf));
						final = malloc(ft_strlen(buf));
						final = ft_strjoin(final, buf);
					}	
				//break;	
	}
	return str;
}

int main()
{
	int fd = open("test.txt",O_RDONLY);
	char *str = get_next_line(fd);
	printf("str1 - %s",str);
	str = get_next_line(fd);
	printf("str2 - %s",str);
	str = get_next_line(fd);
	printf("str2 - %s",str);
	// str = get_next_line(fd);
	
}