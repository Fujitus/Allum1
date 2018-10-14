/*
** my_alum.h for alum1 in /home/costa_d/Documents/alum1
** 
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
** 
** Started on  Mon Feb  8 14:03:02 2016 Arnaud Costa
** Last update Sun Feb 21 12:51:39 2016 Arnaud Costa
*/

#ifndef MY_ALUM_H_
# define MY_ALUM_H_
#include "get_next_line.h"

typedef struct	s_plat
{
  int	tab_pipe[4];
  int	nb_pipe;
  int	nb_ligne;
  int	id_play;
}		t_plat;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_getnbr(char *str);
void	update_struct(t_plat *plat);
int	param_ligne(char *ligne, t_plat *plat);
int	param_nb_pipe(char *nb_pipe, t_plat *plat);
int	getparam(t_plat *plat);
int	getligne(t_plat *plat);
void	bob(t_plat *plat);
void	my_put_nbr(int nb);
void	creat_plateau(t_plat *plat);
t_plat	init_struct();
int	brain_xor(t_plat *palt);
int	brain(t_plat *palt);
int	tchek_end(t_plat *plat);
void	display_player(t_plat *plat);
int	my_str_isalpha(char *str);
void	update_input(t_plat *plat, int nb);
int	verif_alpha(char *str);
void	brain_posibility(int e, t_plat *plat);

#endif /* !MY_ALUM_H_*/
