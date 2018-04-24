#ifndef WIRE_H
#define WIRE_H
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <string.h>

#define OFFSET_X 50
#define OFFSET_Y 50
# define WIN_W 1000
# define WIN_H 600

typedef	struct	s_map
{
	char	*line;
	int		fd;
	int		**x;
	int		**y;
	int		**z;
}				t_map;

typedef	struct	s_read
{
	char				*line;
	int					nbline;
	size_t				len;
	struct	s_read		*next;
}				t_read;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			len;
	int			nbline;
}				t_point;

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
t_point		**readfile(char *file);

#endif
