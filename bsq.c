/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:47:09 by scho              #+#    #+#             */
/*   Updated: 2019/04/17 17:37:52 by scho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		can_fit(char **map, int *pos, int sq_size)
{
	int i;
	int j;

	i = 0;
	while (i < sq_size)
	{
		j = 0;
		while (j < sq_size)
		{
			if (map[1 + pos[0] + i][pos[1] + j] == map[0][1])
			{
				pos[1] += j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		occ(char **map, int *pos, int *max)
{
	int i;

	i = 0;
	while (i < max[0])
	{
		if (map[1 + pos[0] + i][pos[1] + max[0]] == map[0][1])
		{
			pos[1] += max[0];
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < max[0] - 1)
	{
		if (map[1 + pos[0] + max[0]][pos[1] + i] == map[0][1])
		{
			pos[1] += i;
			return (0);
		}
		i++;
	}
	return (1);
}

int		find_max(char **map, int *s, int *p, int *max)
{
	max[1] = p[0];
	max[2] = p[1];
	while (p[0] + max[0] < s[0] && p[1] + max[0] < s[1])
	{
		if (!occ(map, p, max))
			return (max[0]);
		max[0]++;
	}
	return (max[0]);
}

void	fill_map(char **map, int *max)
{
	int i;
	int j;

	i = 0;
	while (i < max[0])
	{
		j = 0;
		while (j < max[0])
		{
			map[1 + max[1] + i][max[2] + j] = map[0][2];
			j++;
		}
		i++;
	}
}

void	bsq(char **map, int *size)
{
	int i[2];
	int max[3];

	i[0] = 0;
	max[0] = 0;
	while (i[0] < size[0] - max[0])
	{
		i[1] = 0;
		while (i[1] < size[1] - max[0])
		{
			if (i[0] >= size[0] - max[0])
				break ;
			if (can_fit(map, i, max[0] + 1))
			{
				max[0]++;
				find_max(map, size, i, max);
			}
			i[1]++;
		}
		i[0]++;
	}
	fill_map(map, max);
}
