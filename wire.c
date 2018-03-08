#include "minilibx_macos/mlx.h"
#include "wire.h"

int		main()
{
	t_wire wire;

	wire.mlx = mlx_init();
	wire.wdw = mlx_new_window(wire.mlx, 750, 750, "WireFrame");
	mlx_loop(wire.mlx);
	return (0);
}
