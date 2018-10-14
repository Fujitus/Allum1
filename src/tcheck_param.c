/*
** tcheck_param.c for Allum1 in /home/costa_d/CPE_2015_Allum1
** 
** Made by arnaud costa
** Login   <costa_d@epitech.net>
** 
** Started on  Sun Feb 21 15:26:46 2016 arnaud costa
** Last update Sun Feb 21 15:29:42 2016 arnaud costa
*/

#include <stdlib.h>
#include "my_alum.h"
#include "get_next_line.h"

int	param_ligne(char *ligne, t_plat *plat)
{
  int	update_ligne;

  if (verif_alpha(ligne) == 1)
    return (1);
  update_ligne = my_getnbr(ligne);
  if (update_ligne == 0 || update_ligne > 4)
    {
      my_putstr("Error: this line is out of range\n");
      return (1);
    }
  if (update_ligne < 0)
    {
      my_putstr("Error: invalid input (poitive number expected)\n");
      return (1);
    }
  if (plat->tab_pipe[update_ligne - 1] <= 0)
    {
      my_putstr("Error: this line is empty\n");
      return (1);
    }
  else
    plat->nb_ligne = update_ligne;
  return (0);
}

int	param_nb_pipe(char *nb_pipe, t_plat *plat)
{
  int	update_nb_pipe;

  if (verif_alpha(nb_pipe) == 1)
    return (1);
  update_nb_pipe = my_getnbr(nb_pipe);
  if (update_nb_pipe > plat->tab_pipe[plat->nb_ligne - 1])
    {
      my_putstr("Error: not enough matches on this line\n");
      return (1);
    }
  if (update_nb_pipe < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (update_nb_pipe == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (1);
    }
  else
    update_input(plat, update_nb_pipe);
  return (0);
}

int	getligne(t_plat *plat)
{
  int	ligne;
  char	*input_line;

  ligne = 1;
  while (ligne > 0)
    {
      my_putstr("Line: ");
      input_line = get_next_line(0);
      if (input_line == NULL)
	return (-1);
      ligne = param_ligne(input_line, plat);
      free(input_line);
    }
  return (ligne);
}

int	getparam(t_plat *plat)
{
  int	matches;
  int	end;
  char	*input_matches;

  matches = 1;
  while (matches > 0)
    {
      end = getligne(plat);
      if (end == -1)
	return (-1);
      my_putstr("Matches: ");
      input_matches = get_next_line(0);
      if (input_matches == NULL)
	return (-1);
      matches = param_nb_pipe(input_matches, plat);
      free(input_matches);
    }
  display_player(plat);
  return (0);
}

void	display_player(t_plat *plat)
{
  my_putstr("Player removed ");
  my_put_nbr(plat->nb_pipe);
  my_putstr(" match(es) from line ");
  my_put_nbr(plat->nb_ligne);
  my_putchar('\n');
}
