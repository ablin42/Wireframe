#include "../include/wire.h"
#include <stdio.h>

void		ft_getvalues(t_map *map, int k, int linesize)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = 0;
	while (map->line[i] != '\0')
	{
		while (ft_isdigit(map->line[i]) == 1)
		{
			map->z[k][j] += ft_atoi(&map->line[i]);
			i++;
			if (map->line[i] == '\0' || ft_isdigit(map->line[i]) == 0)
			{
				ft_putstr(ft_itoa(map->z[k][j]));
				j++;
				break;
			}
		}
		i++;
	}
	map->z[k][j] = 'x';
	ft_putchar('\n');
}

void		readfile(char *file, t_map *map)
{
	t_read	rd;

	rd.i = 0;
	rd.j = 0;
	rd.linesize = 0;
	rd.k = 0;
	map->fd = open(file, O_RDONLY);
	while (get_next_line(map->fd, &map->line) > 0)
	{
		if (rd.linesize == 0)
			rd.linesize = (ft_strlen(map->line) / 3) + 1;
		rd.i++;
	}
	close(map->fd);
	map->z = (int**)ft_memalloc(sizeof(map->x) * (rd.i + 1));
	while (rd.j < rd.i)
	{
		map->z[rd.j] = (int*)ft_memalloc(sizeof(int *) *  (rd.linesize + 1));
		rd.j++;
	}
	map->fd = open(file, O_RDONLY);
	while (get_next_line(map->fd, &map->line) > 0)
		ft_getvalues(map, rd.k++, rd.linesize);
}
