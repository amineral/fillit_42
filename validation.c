/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:49 by toberon           #+#    #+#             */
/*   Updated: 2020/01/23 17:59:09 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_char(char *s, char n)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == n)
				count++;
			i++;
		}
	}
	return (count);
}

int		check_blocks(char *t, int i)
{
	int sides;

	sides = 0;
	if (i > 0 && i < 18)
	{
		if (t[i + 1] == '#')
			sides++;
		if (t[i - 1] == '#')
			sides++;
	}
	if (i > 4)
		if (t[i - 5] == '#')
			sides++;
	if (i < 15)
		if (t[i + 5] == '#')
			sides++;
	if (i == 18 && t[i - 1] == '#')
		sides++;
	if (i == 0 && t[i + 1] == '#')
		sides++;
	return (sides);
}

int		validation(char *figure)
{
	int check;
	int i;
	int connections;

	connections = 0;
	i = 0;
	if (*figure != '.' && *figure != '#')
		return (0);
	if (ft_count_char(figure, '#') != 4)
		return (0);
	if (ft_count_char(figure, '.') != 12)
		return (0);
	while (figure[i] != '\0')
	{
		if (figure[i] == '#')
		{
			check = check_blocks(figure, i);
			connections = connections + check;
		}
		i++;
	}
	if (connections < 6)
		return (0);
	return (1);
}
