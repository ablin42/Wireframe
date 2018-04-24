#include "../include/wire.h"
#include <stdio.h>

/*
 * this is the algorithm that draws a line between two points
*/

void		drawline(t_wire *wire, t_point p1, t_point p2)
{
	int		iter;
	t_point	delta;

	iter = fmax(fabs(p1.x - p2.x), fabs(p1.y - p2.y));
	delta.x = (double)(p1.x - p2.x) / iter;
	delta.y = (double)(p1.y - p2.y) / iter;
	while (iter > 0)
	{
		mlx_pixel_put(wire->mlx, wire->win, 50 + p1.x + delta.x * iter, 50 + p1.y + delta.y * iter, 0x009900);
		iter--;
	}
}

/*
 * this function calls to drawline for each value in the board
 * it also has a loop to draw the top left corners
*/

void		drawmap(t_wire *wire, t_point **p)
{
	int		i;
	int		j;
	i = 0;

	//this while place the top and left corners
	while (i < ((p[0]->len - 1)* 50) + 1)
	{
		mlx_pixel_put(wire->mlx, wire->win, 50 + i , 50, 0x990000);
		if (i + 50 < p[0]->nbline + 1)
			mlx_pixel_put(wire->mlx, wire->win, 50 , 50 + i, 0x990000);
		i++;
	}
	i = 0;
	while (p[i] != NULL)
	{
		j = 0;
		while (j + 1 < p[i]->len && p[i + 1] != NULL)
		{
			drawline(wire, p[i][j], p[i][j + 1]);
			drawline(wire, p[i][j], p[i + 1][j]);
			j++;
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	t_wire		wire;
	t_point		**p;

	if (ac != 2)
		return (0);
	p = readfile(av[1]);
	wire.mlx = mlx_init();
	wire.win = mlx_new_window(wire.mlx, WIN_W, WIN_H, "WireFrame");
	drawmap(&wire, p);
	mlx_loop(wire.mlx);
	return (0);
}
