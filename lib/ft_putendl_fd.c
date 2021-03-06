/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:08:53 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 17:57:59 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	c = '\n';
	if (s)
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	write(fd, &c, 1);
}
