/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:17:51 by toberon           #+#    #+#             */
/*   Updated: 2020/01/23 17:17:52 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_prev_tetri(char **field, t_figure *tetri, int size)
{
	int i;
	int j;
	int n;

	n = 0;
	i = 0;
	j = 0;
	while (i < size && n < 4)
	{
		while (j < size && n < 4)
		{
			if (field[i][j] == tetri->figure_alpha)
			{
				field[i][j] = '.';
				n++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		tetri_to_field(t_figure *tetri, char **field, t_position pos, int size)
{
	int n;

	n = 0;
	while (n < 4)
	{
		if (tetri->f_pos[n][1] + pos.y < size
			&& tetri->f_pos[n][0] + pos.x < size)
		{
			if (field[tetri->f_pos[n][1] + pos.y][tetri->f_pos[n][0] + pos.x]
				== '.')
				field[tetri->f_pos[n][1] + pos.y][tetri->f_pos[n][0] + pos.x] =
					tetri->figure_alpha;
			else
				return (0);
		}
		else
			return (0);
		n++;
	}
	tetri->shift_x = pos.x;
	tetri->shift_y = pos.y;
	return (1);
}

int		shift_tetri(t_position *pos, t_figure **tetri, int size)
{
	if (pos->x >= size)
	{
		pos->x = 0;
		pos->y++;
	}
	else
		pos->x++;
	if (pos->y >= size)
	{
		if ((*tetri)->prev != NULL)
		{
			(*tetri)->shift_x = 0;
			(*tetri)->shift_y = 0;
			(*tetri) = (*tetri)->prev;
			pos->x = (*tetri)->shift_x;
			pos->y = (*tetri)->shift_y;
		}
		else if ((*tetri)->prev == NULL)
		{
			(*tetri)->shift_x = 0;
			(*tetri)->shift_y = 0;
			return (0);
		}
	}
	return (1);
}

int		filling_field(char **field, t_figure *tetri, int size)
{
	t_position	pos;
	int			check;

	pos.x = 0;
	pos.y = 0;
	while (tetri)
	{
		check = tetri_to_field(tetri, field, pos, size);
		if (check == 1)
		{
			tetri = tetri->next;
			pos.x = 0;
			pos.y = 0;
		}
		else if (check == 0)
		{
			clear_prev_tetri(field, tetri, size);
			if (shift_tetri(&pos, &tetri, size) == 0)
				return (0);
		}
	}
	return (1);
}
