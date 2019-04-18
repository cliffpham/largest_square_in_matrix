/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:55:08 by scho              #+#    #+#             */
/*   Updated: 2019/04/17 16:27:24 by scho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ALL_H
# define __ALL_H

void	pchar(char c);
void	pstr(char *str);
void	print_map(char **map, int *size);
int		stoi(char *str);
int		get_header(char *str, char *h);
int		get_map(char *input, char **map, char *head, int h);
int		read_fd(int fd, char *fname);
void	bsq(char **map, int *size);

#endif
