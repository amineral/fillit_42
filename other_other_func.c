/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_other_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:29 by toberon           #+#    #+#             */
/*   Updated: 2020/01/23 17:18:30 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*correction_func(t_figure *tetri)
{
	tetri = tetri->next;
	tetri->prev = NULL;
	return (tetri);
}

void		clear_full_field(char **field_to_clear, int field_size)
{
	int i;

	i = 0;
	while (i + 1 < (field_size))
	{
		free(field_to_clear[i]);
		i++;
	}
	free(field_to_clear);
}

int			minimum_field(int count)
{
	int min_field;

	min_field = 2 * square(count);
	return (min_field);
}
