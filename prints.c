/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:54:12 by scho              #+#    #+#             */
/*   Updated: 2019/04/15 16:55:03 by scho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pchar(char c)
{
	write(1, &c, 1);
}

void	pstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		pchar(str[i]);
		i++;
	}
}

void	print_map(char **map, int *size)
{
	int i;

	i = 0;
	while (i < size[0])
	{
		write(1, map[i], size[1]);
		pchar('\n');
		i++;
	}
}
