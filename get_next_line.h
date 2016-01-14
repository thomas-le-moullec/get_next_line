/*
** get_next_line.h for get_next_line.h in /home/le-mou_t/rendu/CPE_2015_getnextline
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Jan  7 20:35:15 2016 Thomas LE MOULLEC
** Last update Thu Jan 14 01:51:13 2016 Thomas LE MOULLEC
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef READ_SIZE
# define READ_SIZE (2000000)

typedef struct		s_data
{
  int			j;
  int			i;
  int			a;
  char			*stock;
  int			cmpt;
}			t_data;

#endif
