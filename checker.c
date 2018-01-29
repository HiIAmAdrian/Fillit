/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:28:32 by adstan            #+#    #+#             */
/*   Updated: 2017/12/30 15:13:09 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		nr_vecini(char a[4][4], int i, int j)
{
	int	nr;

	nr = 0;
	if (a[i][j - 1] == '#' && j - 1 >= 0)
		nr++;
	if (a[i][j + 1] == '#' && j + 1 <= 3)
		nr++;
	if (a[i + 1][j] == '#' && i + 1 <= 3)
		nr++;
	if (a[i - 1][j] == '#' && i - 1 >= 0)
		nr++;
	return (nr);
}

int		ajut_verificare_forma(char a[4][4], int i, int j, int suma)
{
	suma = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a[i][j] == '#')
				suma += nr_vecini(a, i, j);
			j++;
		}
		i++;
	}
	return (suma);
}

int		verificare_forma(t_list *lst)
{
	char	a[4][4];
	int		i;
	int		j;
	int		k;
	int		suma;

	while (lst)
	{
		k = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
				a[i][j++] = lst->content[k++];
			k++;
			i++;
		}
		i = 0;
		suma = ajut_verificare_forma(a, i, j, suma);
		if (suma != 6 && suma != 8)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		verificare_caractere(t_list *lst)
{
	int	i;
	int	nrhash;

	i = 0;
	while (lst)
	{
		i = 0;
		nrhash = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '#')
				nrhash++;
			if (lst->content[i] != '.' && lst->content[i] != '#'
					&& lst->content[i] != '\n')
				return (0);
			i++;
		}
		if (nrhash != 4)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		verificare_matrici(t_list *lst)
{
	int	bloq;
	int	i;

	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			bloq = 0;
			while (lst->content[i] != '\n')
			{
				bloq++;
				i++;
			}
			if (bloq != 4)
				return (0);
			if (++i == 20 && lst->content[i] == '\n')
				i++;
		}
		if ((lst->next != NULL && i != 21) || (lst->next == NULL && i != 20))
			return (0);
		lst = lst->next;
	}
	return (1);
}
