/*
** bob.c for Allum1 in /home/costa_d/CPE_2015_Allum1
** 
** Made by arnaud costa
** Login   <costa_d@epitech.net>
** 
** Started on  Sun Feb 21 15:22:26 2016 arnaud costa
** Last update Mon Feb 22 16:09:04 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "my_alum.h"

void	bob(t_plat *plat)
{
  brain_xor(plat);
  my_putstr("AI removed ");
  my_put_nbr(plat->nb_pipe);
  my_putstr(" match(es) from line ");
  my_put_nbr(plat->nb_ligne);
  my_putchar('\n');
}

int	tchek_end(t_plat *plat)
{
  if (plat->tab_pipe[0] == 0 && plat->tab_pipe[2] == 0 &&
      plat->tab_pipe[1] == 0 && plat->tab_pipe[3] == 0)
    return (-1);
  else
    return (1);
  return (1);
}

int	verif_alpha(char *str)
{
  if (my_str_isalpha(str) == 0 || str[0] == '\0')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  return (0);
}
