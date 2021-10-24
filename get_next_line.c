#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	count_check(char const *s, unsigned int start, size_t len)
{
	size_t	count;

	count = 0;
	if (((int)ft_strlen(s) - (int)start) > (int)len)
		count = len;
	else if (start > ft_strlen(s))
		count = 0;
	else
		count = ft_strlen(s) - start;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	count;

	i = 0;
	if (!s)
		return (NULL);
	count = count_check(s, start, len);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{	
		while (s[start] != '\0' && i < count)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*s1;
	char	*s2;
	int		j;
	int		k;

	s1 = (char *)str;
	j = 0;
	k = 0;
	s2 = (char *)malloc((ft_strlen((char *)str)) * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[k] != '\0')
	{
		s2[j] = s1[k];
		j++;
		k++;
	}
	s2[k] = '\0';
	return (s2);
}


char *ft_strjoin(char *str, char *join)
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
  return ft_strdup(str);
}

int check_str(char *str)
{
  int j = 0;
  while(str[j])
  {
    if(str[j] == '\n')
      return j;
    j++;
  }
  return -1;
}

int no_nl(int fd)
{
  int i;
  char *str;

  str = malloc(BUFFER_SIZE);
  while (i > 0 && check_str(str) < 0)
    i = read(fd, str, BUFFER_SIZE);
  if (i == 0)
    return 0;
  return 1;
}

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
  if (no_nl(fd) == 0)
    return NULL;
  else if (check_str(str) > 0)
    final = ft_substr(str, 0 ,(check_str(str) + 1));
  else
  {
    final = ft_strdup(str);
    while (check_str(join) < 0 && i > 0)
      {
        i = read(fd, join, BUFFER_SIZE); 
        final = ft_strjoin(final, join);
      }
  }
    return final;
}

// #include <stdio.h>

// int main()
// {

//  int fd = open("test.txt",O_RDONLY);
//  char *str = get_next_line(fd);
//   printf("%s",str);
// }