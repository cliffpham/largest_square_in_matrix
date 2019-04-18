/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:24:52 by scho              #+#    #+#             */
/*   Updated: 2019/04/17 16:29:02 by scho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "all.h"

int		solve(char *head, int *sz, int fd)
{
	char	**map;
	char	*b;

	b = malloc(sizeof(*b) * ((sz[0] + 1) * sz[1] + 16));
	b[read(fd, b, sizeof(*b) * ((sz[0] + 1) * sz[1] + 16))] = '\0';
	map = malloc(sizeof(char *) * (sz[0] + 1));
	map[0] = head;
	if (get_map(b, &map[1], map[0], sz[0]) < 0)
	{
		free(b);
		return (-1);
	}
	bsq(map, sz);
	print_map(&map[1], sz);
	free(b);
	free(map);
	return (0);
}

int		solve_stdin(char *buf, char *head, int *sz)
{
	char **map;

	map = malloc(sizeof(char *) * (sz[0] + 1));
	map[0] = head;
	if (get_map(buf, &map[1], map[0], sz[0]) < 0)
	{
		free(map);
		return (-1);
	}
	bsq(map, sz);
	print_map(&map[1], sz);
	free(map);
	return (0);
}

int		read_file(int fd, char *fname)
{
	char	*b;
	char	head[3];
	int		sz[2];

	b = malloc(sizeof(char) * 16);
	sz[0] = 0;
	while (sz[0] < 16 && read(fd, &b[sz[0]], 1) == 1 && b[sz[0]] != '\n')
		sz[0]++;
	sz[0] = get_header(b, head);
	free(b);
	if (sz[0] <= 0)
		return (write(2, "map error\n", 10));
	sz[1] = 0;
	b = malloc(sizeof(char));
	while (read(fd, b, 1) == 1 && *b != '\n')
		sz[1]++;
	free(b);
	if (sz[1] == 0)
		return (write(2, "map error\n", 10));
	close(fd);
	fd = open(fname, O_RDONLY);
	if (solve(head, sz, fd) < 0)
		write(2, "map error\n", 10);
	return (close(fd));
}

int		read_stdin(void)
{
	char	b[8192];
	char	head[3];
	int		sz[2];
	int		i;

	b[read(0, b, 8191)] = '\0';
	sz[0] = get_header(b, head);
	if (sz[0] <= 0)
		return (write(2, "map error\n", 10));
	sz[1] = 0;
	i = 0;
	while (b[i] != '\n')
		i++;
	i++;
	while (b[i + sz[1]] != '\n')
		sz[1]++;
	if (sz[1] == 0)
		return (write(2, "map error\n", 10));
	if (solve_stdin(b, head, sz) < 0)
		write(2, "map error\n", 10);
	return (0);
}

int		read_fd(int fd, char *fname)
{
	if (fd == 0)
		return (read_stdin());
	return (read_file(fd, fname));
}
