/*
** tools.c for Allum1 in /home/costa_d/CPE_2015_Allum1
** 
** Made by arnaud costa
** Login   <costa_d@epitech.net>
** 
** Started on  Sun Feb 21 15:26:22 2016 arnaud costa
** Last update Sun Feb 21 15:26:24 2016 arnaud costa
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	type;

  type = 1;
  i = 0;
  res = 0;
  if (str[0] == '-')
    {
      i++;
      type = 0;
    }
  while (str[i] != '\0')
    {
      str[i] = str[i] - 48;
      res = res + str[i];
      if (str[i + 1] != '\0')
	res = res * 10;
      i++;
    }
  if (type == 0)
    res = res * -1;
  return (res);
}

void	my_put_nbr(int nb)
{
  int	temp;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 10)
    {
      temp = (nb % 10);
      nb = (nb - temp) / 10;
      my_put_nbr(nb);
      my_putchar(48 + temp);
    }
  else
    my_putchar(48 + nb  % 10);
}

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 58)
	return (0);
      i = i + 1;
    }
  return (1);
}
