/*
** ia_xor.c for Allum1 in /home/costa_d/CPE_2015_Allum1
** 
** Made by arnaud costa
** Login   <costa_d@epitech.net>
** 
** Started on  Sun Feb 21 15:22:47 2016 arnaud costa
** Last update Sun Feb 21 15:32:29 2016 arnaud costa
*/

#include "my_alum.h"

int	brain_xor(t_plat *plat)
{
  int	e;

  e = plat->tab_pipe[0]^plat->tab_pipe[1]^ \
  plat->tab_pipe[2]^plat->tab_pipe[3]^1;
  brain_posibility(e, plat);
  return (0);
}

void	brain_posibility(int e, t_plat *plat)
{
  int	i;
  int	f;

  i = 0;
  while (i < 4)
    {
      f = plat->tab_pipe[i]^e;
      if (f < plat->tab_pipe[i])
        {
          plat->nb_pipe = plat->tab_pipe[i] - f;
          plat->nb_ligne = i + 1;
          plat->id_play = 2;
          return ;
	}
      else if (plat->tab_pipe[i] > 0)
	{
          plat->nb_pipe = plat->tab_pipe[i];
          plat->nb_ligne = i + 1;
          plat->id_play = 2;
          return ;
	}
      i++;
    }
}
