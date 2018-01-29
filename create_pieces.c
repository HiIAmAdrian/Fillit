/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:54:37 by adstan            #+#    #+#             */
/*   Updated: 2018/01/29 19:45:26 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"

void	assign_coords(int coords[], int casee, int i, int j)
{
	if (casee == 1)
	{
		coords[0] = 100;
		coords[2] = 100;
		coords[1] = -1;
		coords[3] = -1;
		return ;
	}
	if (i < coords[0])
		coords[0] = i;
	if (i > coords[1])
		coords[1] = i;
	if (j < coords[2])
		coords[2] = j;
	if (j > coords[3])
		coords[3] = j;
}

void	set_coords_char(t_list *lst, t_piesa *piesa, int *l)
{
	int		coords[4];
	char	a;
	int		i;
	int		j;
	int		k;

	a = 'A';
	while (lst)
	{
		k = 0;
		piesa[*l].c = (a++);
		assign_coords(coords, 1, 0, 0);
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (lst->content[k++] == '#')
					assign_coords(coords, 2, i, j);
			k++;
		}
		piesa[*l].latime = ft_abs(coords[3] - coords[2]) + 1;
		piesa[(*l)++].inaltime = ft_abs(coords[1] - coords[0]) + 1;
		lst = lst->next;
	}
}

void	set_shifts_dir(int *p, int d[], int *l, t_piesa *piesa)
{
	if (!(*p))
	{
		d[2] = d[0];
		d[3] = d[1];
	}
	piesa[*l].form |= 1L << ((4 - d[0] + d[2]) * 16 - d[1] + d[3] - 1);
	piesa[*l].di[*p] = d[0] - d[2];
	piesa[*l].dj[(*p)++] = d[1] - d[3];
	if (d[1] - d[3] == -1 && d[4] != 2)
		d[4] = 1;
	if (d[1] - d[3] == -2)
		d[4] = 2;
}

void	set_form(t_list *lst, t_piesa *piesa, int *l)
{
	int		k;
	int		p;
	int		d[5];

	while (lst)
	{
		d[4] = 0;
		p = 0;
		k = 0;
		d[0] = -1;
		while (++(d[0]) < 4)
		{
			d[1] = -1;
			while (++(d[1]) < 4)
				if (lst->content[k++] == '#')
					set_shifts_dir(&p, d, l, piesa);
			k++;
		}
		piesa[*l].form >>= d[4];
		(*l)++;
		lst = lst->next;
	}
}

void	set_form2_last(t_list *lst, t_piesa *piesa, int *l)
{
	int	p;
	int	g;

	while (lst)
	{
		p = 0;
		g = 0;
		if (!((piesa[*l].form >> 63) & 1) && !((piesa[*l].form >> 62) & 1))
			g = 2;
		else if (!((piesa[*l].form >> 63) & 1))
			g = 1;
		p = 0;
		while (p < 4)
			piesa[*l].dj[p++] += g;
		piesa[*l].form = piesa[*l].form >> ((4 - piesa[*l].inaltime) * 16);
		p = *l - 1;
		piesa[*l].last = -1;
		while (p >= 0 && piesa[*l].last == -1)
			if (piesa[p--].form == piesa[*l].form)
				piesa[*l].last = p + 1;
		(*l)++;
		lst = lst->next;
	}
}
