#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>


# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char    *get_nl(int fd, char *save);
char    *get_str(char *save);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char    *get_save(char *save);
char    *ft_strjoin(char *s1, char *s2);

#endif
