#include "../include/wire.h"
#include <stdio.h>

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

void		drawmap(t_wire *wire, t_map *map, t_point **p)
{
	int		i;
	int		j;
	(void)map;
	i = 0;
	while (p[i] != NULL)
	{
		j = 0;
		while (j < 19 && p[i + 1] != NULL)
		{
				drawline(wire, p[i][j], p[i][j + 1]);
				//drawline(wire, p[i][j], p[i + 1][j]);
			j++;
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	t_wire		wire;
	t_map		map;
	t_point		**p;

	if (ac != 2)
		return (0);
	p = readfile(av[1], &map);
	wire.mlx = mlx_init();
	wire.win = mlx_new_window(wire.mlx, 1000, 1000, "WireFrame");
	drawmap(&wire, &map, p);
	mlx_loop(wire.mlx);
	return (0);
}
