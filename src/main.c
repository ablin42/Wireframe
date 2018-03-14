#include "../minilibx_macos/mlx.h"
#include "../include/wire.h"
#include "../include/get_next_line.h"
#include <stdio.h>

t_map		ft_getvalues(t_map map)
{
	if (map.x == NULL)
	{
		ft_strlen(map.line);
	}
	return (map);
}

int			main(int ac, char **av)
{
//	t_wire	wire;
	t_map	map;

	if (ac != 2)
		return (0);
	map.fd = open(av[1], O_RDONLY);
	while (get_next_line(map.fd, &map.line) > 0)
	{
		printf("[%s]\n", map.line);
	}
	//printf("%lu", ((ft_strlen(map.line) / 3) + ft_strlen(map.line) % 3));
//	img.bpp = 8;
//	img.size_l = 100;
//	img.endian = 1;

	//wire.mlx = mlx_init();
	//wire.win = mlx_new_window(wire.mlx, 500, 500, "WireFrame");
	//mlx_loop(wire.mlx);
	return (0);
}
