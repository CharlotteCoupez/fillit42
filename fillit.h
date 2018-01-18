/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:42:27 by ccoupez           #+#    #+#             */
/*   Updated: 2017/12/15 15:35:23 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "Libft/libft.h"
# define BUF_SIZE 546
# define SUCCESS 0
# define FAIL -1

typedef	struct		s_point
{
	int				pt1;
	int				pt2;
	int				pt3;
	int				pt4;
}					t_point;

typedef	struct		s_tetri
{
	char			*tetri;
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

char				*ft_get_file(char *file, char *buf);
int					check_char_tetri(char *buf);
t_tetri				*ft_split_in_list(char const *buf);
char				*ft_remake(char letter, t_point *point, char *str);
t_point				*ft_new_point(char *str, t_point *point);
char				*ft_get_point(t_tetri *list);
char				*algorithm(t_tetri *list);
t_tetri				*ft_put_left(t_tetri *list);
void				print_list(t_tetri *list);
char				*create_map(int size);
int					can_fit(t_tetri *list, char *map, int size);
void				fill(t_tetri *list, char *map, int size, int pos);
int					size_map(t_tetri *list);
void				delete(t_tetri *list, char *map);
int					fit(t_tetri *list, char *map, int size, int i);

#endif
