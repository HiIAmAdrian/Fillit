/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:56:17 by adstan            #+#    #+#             */
/*   Updated: 2018/01/29 19:45:36 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"

int		bk(unsigned short *m, t_piesa *piesa, int n, int k)
{
	if (!piesa[k].c)
		return (1);
	piesa[k].i_s = 0;
	if (piesa[k].last != -1)
		piesa[k].i_s = piesa[piesa[k].last].i_s;
	while (piesa[k].i_s <= n - piesa[k].inaltime)
	{
		piesa[k].j_s = 0;
		while (piesa[k].j_s <= n - piesa[k].latime)
		{
			if (!(*(unsigned long*)
				(m + piesa[k].i_s) & piesa[k].form >> piesa[k].j_s))
			{
				*(unsigned long*)
				(m + piesa[k].i_s) ^= piesa[k].form >> piesa[k].j_s;
				if (bk(m, piesa, n, k + 1))
					return (1);
				*(unsigned long*)
				(m + piesa[k].i_s) ^= piesa[k].form >> piesa[k].j_s;
			}
			piesa[k].j_s++;
		}
		piesa[k].i_s++;
	}
	return (0);
}

int		get_min_size(t_piesa *piesa, int casee)
{
	int		pp;

	casee = 1;
	pp = ft_sqrt1(piesa[0].pmax * 4);
	if (pp * pp == piesa[0].pmax * 4 && !casee)
		return (pp + 1);
	return (pp);
}

void	ft_solve(t_piesa *piesa, t_piesa *piesa2, int casee)
{
	unsigned short	*m;
	unsigned short	*temp;
	int				st;

	m = (unsigned short*)malloc(sizeof(unsigned short) * 17);
	temp = (unsigned short*)malloc(sizeof(unsigned short) * 17);
	st = 0;
	while (st < 17)
	{
		m[st] = 0;
		temp[st++] = 0;
	}
	st = get_min_size(piesa, casee);
	while (st <= 16)
	{
		if (!bk(temp, piesa, st++, 0))
			ft_bzero(temp, 17);
		else
		{
			print_sol(piesa, piesa2, st - 1);
			return ;
		}
	}
}

int		perfect(t_piesa *piesa2)
{
	int	k;
	int	i;
	int	casee;

	casee = 0;
	k = 0;
	while (k < piesa2[0].pmax)
	{
		i = 0;
		while (i < 4)
		{
			if (piesa2[k].di[i] != 0 && piesa2[k].di[i] != 1)
				return (0);
			if (piesa2[k].dj[i] != 0 && piesa2[k].dj[i] != 1)
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_piesa	*piesa;
	t_piesa	*piesa2;
	int		l;
	int		i;

	if (argc != 2)
		return (print_usage());
	if (!(lst = citire(argv[1])) || !check_errors(lst))
		return (print_error());
	l = 0;
	piesa2 = creare(lst, &l);
	rev_cnt(lst);
	l = 0;
	i = 0;
	piesa = creare(lst, &l);
	piesa2[0].pmax = l;
	while (i < l)
		piesa[i++].pmax = l;
	piesa[l].c = 0;
	i = perfect(piesa2);
	ft_solve(piesa, piesa2, i);
	return (0);
}
