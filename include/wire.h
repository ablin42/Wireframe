#ifndef WIRE_H
#define WIRE_H
# define WIN_W 500
# define WIN_H 500
#include <mlx.h>
#include "get_next_line.h"
#include <math.h>

typedef	struct	s_map
{
	char	*line;
	int		fd;
	int		**x;
	int		**y;
	int		**z;
}				t_map;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef	struct	s_read
{
	int		i;
	int		j;
	int		k;
	int		linesize;
}				t_read;

typedef struct	s_wire
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}				t_wire;

typedef struct	s_img
{
	void	*img;
	int		color;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

void		ft_getvalues(t_map *map, int k, int linesize);
void		readfile(char **arg, t_map *map);

#endif
