/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 17:50:05 by shazan            #+#    #+#             */
/*   Updated: 2015/01/21 16:27:35 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			xpose_hook(t_all *all)
{
	draw_y(all);
	draw_x(all);
	return (0);
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == 65453)
		change_scale(all, 1);
	if (keycode == 65451)
		change_scale(all, 2);
	if (keycode == 65364)
		change_scale(all, 3);
	if (keycode == 65362)
		change_scale(all, 4);
	if (keycode == 65363)
		change_scale(all, 5);
	if (keycode == 65361)
		change_scale(all, 6);
	if (keycode == 65307)
		exit (0);
	return (0);
}

void		change_scale(t_all *all, int i)
{
	mlx_clear_window(all->mlx, all->win);
	if (i == 1)
	{
		all->scalx -= 5;
		all->scaly -= 5;
	}
	if (i == 2)
	{
		all->scalx += 5;
		all->scaly += 5;
	}
	if (i == 3)
		all->starty += 15;
	if (i == 4)
		all->starty -= 15;
	if (i == 5)
		all->startx += 15;
	if (i == 6)
		all->startx -= 15;
	xpose_hook(all);
}

void		error(int c)
{
	if (c == 1)
	{
		ft_putstr("Memory Allocation Failed");
		exit (0);
	}
	if (c == 2)
	{
		ft_putstr("Error");
		exit (0);
	}
}

char		*all_to_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		if (str[i] && ft_isdigit(str[i]) == 0)
			str[i] = ' ';
		i++;
	}
	return (str);
}
