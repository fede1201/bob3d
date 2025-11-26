#include "../include/cub3d.h"

static int flood_fill(t_game *g, int x, int y)
{
	if (y < 0 || y >= g->map.height)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(g->map.grid_copy[y]))
		return (0);

	if (g->map.grid_copy[y][x] == '1')
		return (1);

	if (g->map.grid_copy[y][x] == ' ')
		return (0);

	if (g->map.grid_copy[y][x] == 'F')
		return (1);

	g->map.grid_copy[y][x] = 'F';
	if (!flood_fill(g, x + 1, y)) return (0);
	if (!flood_fill(g, x - 1, y)) return (0);
	if (!flood_fill(g, x, y + 1)) return (0);
	if (!flood_fill(g, x, y - 1)) return (0);

	return (1);
}

static void copy_map_grid(t_game *g)
{
	int i;

	g->map.grid_copy = malloc(sizeof(char *) * (g->map.height + 1));
	if (!g->map.grid_copy)
		PRINT_ERR(ERR_MALLOC);

	i = 0;
	while (i < g->map.height)
	{
		g->map.grid_copy[i] = ft_strdup(g->map.grid[i]);
		if (!g->map.grid_copy[i])
			PRINT_ERR(ERR_MALLOC);
		i++;
	}
	g->map.grid_copy[i] = NULL;
}

int fill_check_start(t_game *g)
{
	int ok;

	copy_map_grid(g);
	ok = flood_fill(g, g->map.spawn_x, g->map.spawn_y);
	//ft_free_strarr(g->map.grid_copy);
	return (ok);
}
