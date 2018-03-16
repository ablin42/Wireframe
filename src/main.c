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
		mlx_pixel_put(wire->mlx, wire->win, p1.x + delta.x * iter, p1.y + delta.y * iter, 0xFFFFFF);
		iter--;
	}
}

void		drawmap(t_wire *wire, t_map *map)
{
	
}

int			main(int ac, char **av)
{
	t_wire	wire;
	t_map	map;

	if (ac != 2)
		return (0);
	readfile(av[1], &map);
	ft_putstr("test\n");
	wire.mlx = mlx_init();
	ft_putstr("test2\n");
	wire.win = mlx_new_window(wire.mlx, 500, 500, "WireFrame");
	drawmap(&wire, &map);
	mlx_loop(wire.mlx);
	return (0);
}
