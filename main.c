/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:04:05 by shazan            #+#    #+#             */
/*   Updated: 2015/01/21 16:27:29 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_all	all;

	if (ac == 1)
		ft_putstr("No file/n");
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_count_line(fd, &all);
		fd = open(av[1], O_RDONLY);
		init(&all);
		stock_fd(fd, &all);
		close(fd);
		all.mlx = mlx_init();
		all.win = mlx_new_window(all.mlx, 1700, 1700, "FDF");
		mlx_expose_hook(all.win, xpose_hook, &all);
		mlx_key_hook(all.win, key_hook, &all);
		mlx_loop(all.mlx);
	}
	return (0);
}

void	init(t_all *all)
{
	all->scalx = 19;
	all->scaly = 20;
	all->startx = 700;
	all->starty = 100;
}

void	stock_fd(int fd, t_all *all)
{
	all->j = 0;
	all->k = 0;
	if (!(all->nbr = (int **)malloc(sizeof(int *) * all->nbr_line)))
		error(1);
	if (!(all->nbr_split = (int *)malloc(sizeof(int) * all->nbr_line)))
		error(1);
	while (get_next_line(fd, &(all->line)) == 1)
	{
		all->i = 0;
		all->line = all_to_space(all->line);
		all->split = ft_strsplit(all->line, ' ');
		all->nbr_split[all->k] = ft_count_split(all->split);
		if (!(all->nbr[all->j] = (int *)malloc(sizeof(int) * \
					all->nbr_split[all->k])))
			error(1);
		while (all->split[all->i])
		{
			all->nbr[all->j][all->i] = ft_getnbr(all->split[all->i]);
			(all->i)++;
		}
		free(all->split);
		(all->j)++;
		(all->k)++;
	}
}

void	ft_count_line(int fd, t_all *all)
{
	char	*line;

	all->nbr_line = 0;
	while (get_next_line(fd, &line) == 1)
		(all->nbr_line)++;
	close(fd);
}

int		ft_count_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
