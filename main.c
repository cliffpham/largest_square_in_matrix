/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:34:56 by scho              #+#    #+#             */
/*   Updated: 2019/04/17 16:29:10 by scho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "all.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	if (argc < 2)
	{
		i = 0;
		fd = 0;
	}
	while (i < argc)
	{
		if (i > 0)
			fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			pstr(argv[i]);
			pstr(": error opening file\n");
		}
		else
			read_fd(fd, argv[i]);
		i++;
	}
	return (0);
}
