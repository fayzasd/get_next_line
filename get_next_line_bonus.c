#include "get_next_line.h"

char *get_nl(int fd, char *save)
{
	char	*buf;
	int	i;

	buf = malloc((BUFFER_SIZE + 1)*(sizeof(char)));
	i = 1;
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char *get_str(char *save)
{
	char	*str;
	int	i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;	
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return(NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *get_save(char *save)
{
	char *str;
	int i;
	int j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while(save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free (save);
	return (str);
}

char *get_next_line(int fd)
{
	char		*str;
	static char	*save[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = get_nl(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	str = get_str(save[fd]);
	save[fd] = get_save(save[fd]);
	return (str);
}

#include <stdio.h>

// int main()
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	char *str = get_next_line(fd);
// 	printf("%s",str);
// 	// str = get_next_line(fd);
// 	// printf("str2 - %s",str);
// 	// str = get_next_line(fd);
// 	// printf("str2 - %s",str);
// 	// str = get_next_line(fd);
	
// }