/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:57:10 by adstan            #+#    #+#             */
/*   Updated: 2017/12/30 15:13:46 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	print_sol(t_piesa *piesa, t_piesa *piesa2, int n)
{
	char	**m;
	int		i;
	int		j;

	m = (char**)malloc(sizeof(char*) * (17));
	i = 0;
	while (i < n)
		m[i++] = (char*)malloc(sizeof(char) * (17));
	create_matrix(m, n, piesa, piesa2);
	i = -1;
	while (++i < n)
	{
		j = 0;
		while (j < n)
			ft_putchar(m[i][j++]);
		ft_putchar('\n');
	}
}

void	create_matrix(char **m, int n, t_piesa *piesa, t_piesa *piesa2)
{
	int	i;
	int	j;
	int	t;
	int	k;

	i = -1;
	while (++i < n)
	{
		j = 0;
		while (j < n)
			m[i][j++] = '.';
	}
	k = -1;
	while (++k < piesa2[0].pmax)
	{
		i = piesa[k].i_s;
		j = piesa[k].j_s;
		t = -1;
		while (++t < 4)
			m[i + piesa2[k].di[t]][j + piesa2[k].dj[t]] = piesa2[k].c;
	}
}

int		print_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		print_usage(void)
{
	ft_putstr("usage: ./fillit [input_file]\n");
	return (0);
}

int		check_errors(t_list *lst)
{
	if (verificare_matrici(lst) &&
			verificare_caractere(lst) && verificare_forma(lst))
		return (1);
	return (0);
}
