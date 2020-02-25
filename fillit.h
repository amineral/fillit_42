/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:35:48 by toberon           #+#    #+#             */
/*   Updated: 2019/10/21 15:35:49 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef	struct		s_figure
{
	int				f_pos[4][2];
	char			figure_alpha;
	struct s_figure	*next;
	struct s_figure	*prev;
	int				shift_x;
	int				shift_y;
}					t_figure;

typedef	struct		s_position
{
	int				x;
	int				y;
}					t_position;

int					validation(char *figure);
int					check_nearly_blocks(char *t, int i);
int					ft_count_char(char *s, char n);
int					read_and_write(int fd, t_figure **tetri);
t_figure			*add_tetrimino(char *figure);
t_figure			*add_block(t_position block, t_figure *add_to_figure,
						int n_block);
t_figure			*correction_func(t_figure *tetri);
int					count_tetriminos(t_figure *start);
char				**init_field(int count);
int					square(int n);
int					minimum_field(int count);
char				**increase_field(char **old_field, int new_size);
char				**field(int count);
int					tetri_to_field(t_figure *tetri, char **field,
						t_position pos, int size);
int					field_size_test(char **field);
int					filling_field(char **field, t_figure *tetri, int size);
void				print_field(char **field, int size);
void				alpha_to_list(t_figure *start_tetri);
void				clear_full_field(char **field_to_clear, int field_size);
void				rewrite_field(char **field, int size);
int					lets_go_fillit(int fd, t_figure *tetri);
void				shift_prev_tetri(t_figure *tetrimino, t_position position);

#endif
