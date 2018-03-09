#include "../minilibx_macos/mlx.h"
#include "../include/wire.h"

int		main()
{
	t_wire	wire;
	t_img	img;
	int x;
	int y;

	x = 100;
	y = 100;
	img.bpp = 8;
	img.size_l = 100;
	img.endian = 1;

	wire.mlx = mlx_init();
	wire.win = mlx_new_window(wire.mlx, 500, 500, "WireFrame");
	wire.img = mlx_new_image(wire.mlx, 100, 100);
	wire.addr = mlx_get_data_addr(wire.img, &img.bpp, &img.size_l, &img.endian);
	mlx_pixel_put(wire.mlx, wire.win, 20, 20, 0x009900);
	mlx_pixel_put(wire.mlx, wire.win, 20, 480, 0x009900);
	mlx_pixel_put(wire.mlx, wire.win, 480, 20, 0x009900);
	mlx_pixel_put(wire.mlx, wire.win, 480, 480, 0x009900);
	while (x <= 401 && y < 401)
	{
		mlx_pixel_put(wire.mlx, wire.win, x, y, 0x990000);
		x++;
		if (x == 400)
		{
			x = 100;
			y++;
			while (y % 100 != 0 && y < 401)
			{
				mlx_pixel_put(wire.mlx, wire.win, x, y, 0x990000);
				mlx_pixel_put(wire.mlx, wire.win, x+100, y, 0x990000);
				mlx_pixel_put(wire.mlx, wire.win, x+200, y, 0x990000);
				mlx_pixel_put(wire.mlx, wire.win, x+300, y, 0x990000);
				y++;
			}
		}
	}
	mlx_loop(wire.mlx);
	return (0);
}
