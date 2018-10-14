/*
** plateau.c for Allum1 in /home/costa_d/CPE_2015_Allum1
**
** Made by arnaud costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Feb 21 15:26:04 2016 arnaud costa
** Last update Thu Mar 10 23:02:16 2016 Arnaud Costa
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_alum.h"

void	print_ligne(int	nb_pipe, int nb_space)
{
  int	i;
  int	e;

  i = 0;
  e = 0;
  /* my_putchar('*'); */
  my_putstr("\033[32;1m*\033[0m");
  while (i != nb_space)
    {
      my_putchar(' ');
      i++;
    }
  while (e != nb_pipe)
    {
      my_putstr("\033[31m|\033[0m");
      /* my_putchar('|'); */
      i++;
      e++;
    }
  while (i != 7)
    {
      my_putchar(' ');
      i++;
    }
  /* my_putchar('*'); */
  my_putstr("\033[32;1m*\033[0m");
}

void	creat_plateau(t_plat *plat)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      my_putstr("\033[32;1m*\033[0m");
      /* my_putchar('*'); */
      i++;
    }
  my_putchar('\n');
  print_ligne(plat->tab_pipe[0], 3);
  my_putchar('\n');
  print_ligne(plat->tab_pipe[1], 2);
  my_putchar('\n');
  print_ligne(plat->tab_pipe[2], 1);
  my_putchar('\n');
  print_ligne(plat->tab_pipe[3], 0);
  my_putchar('\n');
  while (i > 0)
    {
      my_putstr("\033[32;1m*\033[0m");
      /* my_putchar('*'); */
      i--;
    }
  my_putchar('\n');
}

t_plat	init_struct()
{
   t_plat	plat;
   int		i;
   int		nb;

   i = 0;
   nb = 1;
   while (plat.tab_pipe[i] != 4 && nb <= 7)
     {
       plat.tab_pipe[i] = nb;
       i++;
       nb += 2;
     }
   plat.id_play = 0;
   return (plat);
}

void	update_struct(t_plat *plat)
{
  if (plat->nb_ligne == 1)
    if ((plat->tab_pipe[0] -= 1) < 0)
      plat->tab_pipe[0] = 0;
  if (plat->nb_ligne == 2)
    if ((plat->tab_pipe[1] -= plat->nb_pipe) < 0)
      plat->tab_pipe[1] = 0;
  if (plat->nb_ligne == 3)
    if ((plat->tab_pipe[2] -= plat->nb_pipe) < 0)
      plat->tab_pipe[2] = 0;
  if (plat->nb_ligne == 4)
    if ((plat->tab_pipe[3]-= plat->nb_pipe) < 0)
      plat->tab_pipe[3] = 0;
}

void	update_input(t_plat *plat, int nb)
{
  plat->nb_pipe = nb;
  plat->id_play = 1;
}
