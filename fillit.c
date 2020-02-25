/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:10:06 by toberon           #+#    #+#             */
/*   Updated: 2020/01/25 18:10:07 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_figure	*tetri;

	if (argc < 2)
		return (0);
	tetri = malloc(sizeof(t_figure));
	tetri->prev = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!(lets_go_fillit(fd, tetri)))
		write(1, "error\n", 6);
	return (0);
}
