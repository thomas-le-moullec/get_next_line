/*
** get_next_line.h for get_next_line.h in /home/le-mou_t/rendu/CPE_2015_getnextline
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Jan  7 20:35:15 2016 Thomas LE MOULLEC
** Last update Sun Jan 17 20:16:19 2016 Thomas LE MOULLEC
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

typedef struct		s_data
{
  int			j;
  int			i;
  int			a;
  char			*stock;
  int			cmpt;
}			t_data;

int             do_it(t_data *, char *, int *);
char		*my_strcar(char *, char);
int             check_static(char *, int *, t_data *);
char            *get_next_line(const int);

#endif
