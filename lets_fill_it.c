/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:17:40 by toberon           #+#    #+#             */
/*   Updated: 2020/01/23 17:17:42 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*figures_to_zero_pos(t_figure *tetri)
{
	t_position	pos;
	int			n;

	n = 0;
	pos.x = tetri->f_pos[0][0];
	pos.y = tetri->f_pos[0][1];
	while (n < 4)
	{
		if (tetri->f_pos[n][0] - pos.x == -1)
			pos.x--;
		n++;
	}
	n = 0;
	while (n < 4)
	{
		tetri->f_pos[n][0] = tetri->f_pos[n][0] - pos.x;
		tetri->f_pos[n][1] = tetri->f_pos[n][1] - pos.y;
		n++;
	}
	tetri->shift_x = 0;
	tetri->shift_y = 0;
	return (tetri);
}

t_figure	*add_block(t_position block, t_figure *add_to_figure, int n_block)
{
	add_to_figure->f_pos[n_block][0] = block.x;
	add_to_figure->f_pos[n_block][1] = block.y;
	add_to_figure->next = NULL;
	return (add_to_figure);
}

t_figure	*add_tetrimino(char *figure)
{
	t_figure		*current_tetrimino;
	t_position		tetriminos_position;
	int				n;

	n = 0;
	tetriminos_position.x = 0;
	tetriminos_position.y = 0;
	current_tetrimino = malloc(sizeof(t_figure));
	while (figure && n != 4)
	{
		if (*figure == '\n')
		{
			tetriminos_position.y++;
			tetriminos_position.x = -1;
		}
		if (*figure == '#')
		{
			add_block(tetriminos_position, current_tetrimino, n);
			n++;
		}
		tetriminos_position.x++;
		figure++;
	}
	return (current_tetrimino);
}

int			read_and_write(int fd, t_figure **tetri)
{
	char		*buf;
	int			readed;
	t_figure	*temp;
	int			last_buf;

	buf = (char *)(malloc(sizeof(char) * 22));
	while ((readed = read(fd, buf, 21)))
	{
		last_buf = readed;
		buf[readed] = '\0';
		if (validation(buf))
		{
			temp = *tetri;
			(*tetri)->next = add_tetrimino(buf);
			(*tetri) = (*tetri)->next;
			figures_to_zero_pos(*tetri);
			(*tetri)->prev = temp;
		}
		else
			return (0);
	}
	(*tetri)->next = NULL;
	return (last_buf == 20 ? 1 : 0);
}

int			lets_go_fillit(int fd, t_figure *tetri)
{
	t_figure	*start;
	char		**field_new;
	int			size;
	int			check;
	int			count;

	start = tetri;
	check = read_and_write(fd, &tetri);
	if (check == 0)
		return (0);
	start = correction_func(start);
	count = count_tetriminos(start);
	field_new = field(count);
	if (count > 26 || count < 1 || field_new == NULL)
		return (0);
	alpha_to_list(start);
	size = minimum_field(count);
	while (!(filling_field(field_new, start, size)))
		field_new = increase_field(field_new, ++size);
	print_field(field_new, size);
	return (1);
}
