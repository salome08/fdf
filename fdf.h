/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 19:04:02 by shazan            #+#    #+#             */
/*   Updated: 2015/01/21 15:21:13 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/X.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define ABS(x) ((x) < 0 ? (-x) : (x));

typedef struct		s_all
{
	void	*mlx;
	void	*win;
	int		**nbr;
	int		nbr_line;
	int		*nbr_split;
	int		a;
	int		scalx;
	int		scaly;
	int		startx;
	int		x1;
	int		starty;
	char	**split;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		i;
	int		j;
	int		k;
	char	*line;
	int		incx;
	int		incy;
}					t_all;
int					get_next_line(int const fd, char **line);
void				init(t_all *all);
char				*all_to_space(char *str);
void				stock_fd(int fd, t_all *all);
void				error(int c);
void				ft_count_line(int fd, t_all *all);
int					ft_count_split(char **split);
int					creat_win(t_all *all);
void				change_scale(t_all *all, int i);
int					key_hook(int keycode, t_all *all);
void				draw(t_all *all);
void				draw_y(t_all *all);
void				draw_x(t_all *all);
int					get_color(int z1, int z2);
int					coord_y(t_all *all, int x, int y, int z);
int					coord_x(t_all *all, int x, int y);
void				m_pos(t_all *all, int color);
void				m_neg(t_all *all, int color);
void				bh_dispatch(t_all *all, int color);
int					xpose_hook(t_all *all);

#endif
