char *get_next_line(int fd)
{
  static char *str;
  char *join;
  int i;

  str = malloc(8);
  join = malloc(BUFFER_SIZE);
  i = read(fd, str, BUFFER_SIZE);
  while (*str)
        str++;
  while (*str != '\n' && *str != '\0')
    {
      i = read(fd, join, BUFFER_SIZE);
      str = malloc(BUFFER_SIZE + BUFFER_SIZE);
      while (*join)
        {
          str = join;
          str++;
          join++;
        }
      str++;
    }
  return str;
}
