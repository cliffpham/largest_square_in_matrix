/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:57:58 by scho              #+#    #+#             */
/*   Updated: 2019/04/17 16:23:27 by scho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		stoil(char *str, int l)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (i < l)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	return (r);
}

int		get_header(char *str, char *h)
{
	int		i;

	i = 0;
	while (str[i + 3] != '\n')
		i++;
	h[0] = str[i];
	h[1] = str[i + 1];
	h[2] = str[i + 2];
	return (stoil(str, i));
}

int		check_tail(char *cut_input)
{
	if (cut_input[0] != '\0')
		return (-1);
	return (1);
}

int		get_map(char *input, char **map, char *head, int h)
{
	int i[4];

	i[0] = 3;
	while (input[i[0] - 1] != '\n')
		i[0]++;
	i[3] = 0;
	i[2] = -1;
	while (i[3] < h)
	{
		i[1] = 0;
		map[i[3]] = &input[i[0]];
		while (input[i[0] + i[1]] != '\n' && input[i[0] + i[1]] != '\0')
		{
			if (input[i[0] + i[1]] != head[0] && input[i[0] + i[1]] != head[1])
				return (-1);
			i[1]++;
		}
		if (i[2] >= 0 && i[2] != i[1])
			return (-1);
		i[2] = i[1];
		i[0] += i[1] + 1;
		i[3]++;
	}
	return (i[2] * check_tail(&input[i[0]]));
}
