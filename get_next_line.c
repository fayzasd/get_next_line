#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
*malloc string with buffer
*read file
*check for new line
  *if yes return string
  *if no repeat
*/

int check_str(char *str)
{
  int j = 0;
  while(str[j])
  {
    if(str[j] == '\n')
      return 0;
    j++;
  }
  return 1;
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
  return str;
}

char *get_next_line(int fd)
{
  int i;
  int flag;
  static char *str;
  char *join;

  flag = 0;
  str = malloc(BUFFER_SIZE);
  join = malloc(BUFFER_SIZE);
  i = read(fd, str, BUFFER_SIZE);
  while (check_str(str) == 1 && i >= 0)
    {
      i = read(fd, join, BUFFER_SIZE); 
      str = ft_strjoin(str, join);
    }
  return str;
}

int main()
{
  int i = 0;
 int fd = open("test.txt",O_RDONLY);
 char *str = get_next_line(fd);
  printf("%s",str);
}