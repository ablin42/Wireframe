#include "../minilibx_macos/mlx.h"
#include "../include/wire.h"
#include "../include/get_next_line.h"
#include <stdio.h>

t_map		ft_getvalues(t_map map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map.line[i] != '\0')
	{
		//map.x[0][j] = map.line[i];
		//j++;
		if (ft_isdigit(map.line[i]) == 1)
		{
			ft_putchar(map.line[i]);
		}
		i++;
	}
		ft_putchar(map.line[i]);
	return (map);
}

int			main(int ac, char **av)
{
//	t_wire	wire;
	t_map	map;
	int		i;
	int		j;

	if (ac != 2)
		return (0);
	i = 0;
	map.fd = open(av[1], O_RDONLY);
	while (get_next_line(map.fd, &map.line) > 0)
		i++;
	close(map.fd);
	j = i;
	map.x = (int**)malloc(sizeof(map.x) * (i + 1));
	while (j < i)
	{
		map.x[j] = (int*)malloc(sizeof(int *) * ((ft_strlen(map.line) / 3) + 1));
	}
	map.fd = open(av[1], O_RDONLY);
	while (get_next_line(map.fd, &map.line) > 0)
	{
		map = ft_getvalues(map);
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
