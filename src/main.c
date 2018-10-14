/*
** main.c for Allum1 in /home/costa_d/CPE_2015_Allum1
** 
** Made by arnaud costa
** Login   <costa_d@epitech.net>
** 
** Started on  Sun Feb 21 15:23:07 2016 arnaud costa
** Last update Wed Feb 24 23:07:09 2016 Arnaud Costa
*/

#include "my_alum.h"
#include "get_next_line.h"

int	play(t_plat *plat)
{
  int	end;

  end = 1;
  while (42)
    {
      my_putstr("Your turn:\n");
      end = getparam(plat);
      if (end == -1)
	return (-1);
      update_struct(plat);
      creat_plateau(plat);
      end = tchek_end(plat);
      if (end == -1)
	return (0);
      my_putchar('\n');
      my_putstr("AI's turn...\n");
      bob(plat);
      update_struct(plat);
      creat_plateau(plat);
      end = tchek_end(plat);
      if (end == -1)
	return (0);
      my_putchar('\n');
    }
}

int	main()
{
  t_plat	plat;
  int		end;

  plat = init_struct();
  creat_plateau(&plat);
  my_putchar('\n');
  end = play(&plat);
  if (end == -1)
    return (-1);
  if (plat.id_play == 2)
    my_putstr("I lost.. snif.. but I’ll get you next time!!\n");
  if (plat.id_play == 1)
    my_putstr("You lost, too bad..\n");
  return (0);
}
