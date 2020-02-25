/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:13 by toberon           #+#    #+#             */
/*   Updated: 2020/01/23 17:18:14 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_field(char **field, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, field[i], size);
		write(1, "\n", 1);
		i++;
	}
}

int		field_size_test(char **field)
{
	int size;

	size = 0;
	while (field[0][size] == '.')
		size++;
	return (size);
}

int		square(int n)
{
	int m;

	m = 1;
	while (m * m < n)
		m++;
	if (m * m != n)
		m--;
	return (m);
}

int		count_tetriminos(t_figure *start)
{
	int			count;

	count = 0;
	while (start->next != NULL)
	{
		start = start->next;
		count++;
	}
	count++;
	return (count);
}

void	alpha_to_list(t_figure *start_tetri)
{
	int	i;

	i = 0;
	while (start_tetri)
	{
		start_tetri->figure_alpha = 'A' + i;
		start_tetri = start_tetri->next;
		i++;
	}
}
