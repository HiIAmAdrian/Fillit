/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:39:05 by adstan            #+#    #+#             */
/*   Updated: 2017/12/30 15:37:35 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_list	*citire(char *argv)
{
	int		v[2];
	char	buff[22];
	t_list	*lst;
	t_list	*inceput;
	int		ok;

	ok = 0;
	if ((v[0] = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((v[1] = read(v[0], buff, 21)))
		if (!(ok++))
		{
			buff[v[1]] = 0;
			lst = ft_lstnew(buff, 22);
			inceput = lst;
		}
		else
		{
			buff[v[1]] = 0;
			lst->next = ft_lstnew(buff, 22);
			lst = lst->next;
		}
	if (!ok)
		return (NULL);
	return (inceput);
}

void	assign_litera(t_list *lst)
{
	char	c;
	int		i;

	c = 'A';
	while (lst)
	{
		i = 0;
		while (i < 21)
		{
			if (lst->content[i] == '#')
				lst->content[i] = c;
			i++;
		}
		c++;
		lst = lst->next;
	}
}

void	rev_cnt(t_list *lst)
{
	t_list	*start;
	int		i;
	char	aux;

	start = lst;
	while (lst)
	{
		i = 0;
		while (i < 4)
		{
			aux = lst->content[i];
			lst->content[i] = lst->content[i + 15];
			lst->content[(i++) + 15] = aux;
		}
		i = 5;
		while (i < 9)
		{
			aux = lst->content[i];
			lst->content[i] = lst->content[i + 5];
			lst->content[(i++) + 5] = aux;
		}
		lst = lst->next;
	}
	lst = start;
}

t_piesa	*creare(t_list *lst, int *l)
{
	t_piesa	*piesa;

	piesa = (t_piesa*)malloc(sizeof(t_piesa) * 28);
	set_coords_char(lst, piesa, l);
	*l = 0;
	set_form(lst, piesa, l);
	*l = 0;
	set_form2_last(lst, piesa, l);
	return (piesa);
}
