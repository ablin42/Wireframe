#ifndef WIRE_H
#define WIRE_H
# define WIN_W 500
# define WIN_H 500

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

#endif
