/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:17:06 by toberon           #+#    #+#             */
/*   Updated: 2020/01/23 17:17:18 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rewrite_field(char **field, int size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < size)
	{
		while (j < size)
		{
			field[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

char	**init_field(int count)
{
	char	**field;
	int		min_size;
	int		i;
	int		j;

	j = 0;
	i = 0;
	min_size = minimum_field(count);
	field = (char **)malloc(sizeof(char *) * min_size);
	while (i != min_size)
	{
		field[i] = (char *)malloc(sizeof(char) * min_size + 1);
		while (j != min_size)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][min_size] = '\0';
		i++;
		j = 0;
	}
	return (field);
}

char	**increase_field(char **old_field, int new_size)
{
	int		i;
	int		j;
	char	**new_field;

	i = 0;
	j = 0;
	clear_full_field(old_field, new_size);
	new_field = (char **)malloc(sizeof(char *) * new_size);
	while (i < new_size)
	{
		new_field[i] = (char *)malloc(sizeof(char) * new_size);
		i++;
	}
	rewrite_field(new_field, new_size);
	return (new_field);
}

char	**field(int count)
{
	char	**field;

	field = init_field(count);
	return (field);
}
