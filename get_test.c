/*
** get_next_line.c for get_next_line.c in /home/le-mou_t/rendu/CPE_2015_getnextline
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Fri Jan  8 15:53:42 2016 Thomas LE MOULLEC
** Last update Wed Jan 13 18:15:52 2016 Thomas LE MOULLEC
*/

#include "get_next_line.h"

char    *my_strcar(char *str, char c)
{
  int   i;
  char  *stock;

  i = 0;
  while (str[i] != '\0')
    i++;
  if ((stock = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      stock[i] = str[i];
      i++;
    }
  stock[i] = c;
  i++;
  stock[i] = '\0';
  return (stock);
}

int		do_it(t_data *data, char *buffer, int *ptr)
{
  int		j;

  j = 0;
  while (buffer[j] != '\0' && data->a == 0)
    {
      if (buffer[j] == '\n')
	{
	  data->a = 1;
	  *ptr = j;
	}
      j++;
    }
  j = 0;
  if (data->a == 0)
    while (j != READ_SIZE)
      data->stock = my_strcar(data->stock, buffer[j++]);
  if (data->a == 1)
    {
      while (j != *ptr)
	data->stock = my_strcar(data->stock, buffer[j++]);
      *ptr = j + 1;
      return (-1);
    }
  return (0);
}

int		check_static(char *buffer, int *ptr, t_data *data)
{
  data->i = 0;
  data->a = 0;
  if ((data->stock = malloc(sizeof(char *))) == NULL)
    return (1);
  data->stock = "\0";
  while (buffer[*ptr] != '\0')
    {
      if (buffer[*ptr] == '\n')
	{
	  *ptr = *ptr + 1;
	  return (1);
	}
      data->stock = my_strcar(data->stock, buffer[*ptr]);
      *ptr = *ptr + 1;
    }
  return (0);
}

char		*get_next_line(int fd)
{
  t_data	data;
  static char	buffer[READ_SIZE];
  static int	ptr = 0;

  if ((check_static(buffer, &ptr, &data)) == 1)
    return (data.stock);
  while (data.a == 0)
    {
      if ((data.cmpt = read(fd, buffer, READ_SIZE)) <= 0)
	return (NULL);
      buffer[data.cmpt] = '\0';
      ptr = 0;
      if ((do_it(&data, buffer, &ptr)) == -1)
	return (data.stock);
    }
  return (NULL);
}

int		main(int ac, char **av)
{
  int		fd;
  char		*s;

  (void)ac;
  fd = open(av[1], O_RDONLY);
  while ((s = get_next_line(fd)))
    {
      printf("%s\n", s);
      free(s);
    }
  return (0);
}
