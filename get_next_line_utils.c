/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:12 by fasad             #+#    #+#             */
/*   Updated: 2021/10/27 16:21:04 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (str == NULL)
		return (0);
	while (s1[i] != '\0')
		str[k++] = s1[i++];
	while (s2[j] != '\0')
		str[k++] = s2[j++];
	str[k] = '\0';
	return (str);
}

// char	*ft_strrchr(const char *str, int c)
// {
// 	int	i;

// 	i = ft_strlen((char *)str);
// 	while (i >= 0)
// 	{
// 		if (str[i] == (char)c)
// 			return ((char *)&str[i]);
// 		i--;
// 	}
// 	if (str[ft_strlen(str)] == (char)c)
// 		return ((char *)&str[ft_strlen(str)]);
// 	return (0);
// }

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
