#include "../include/cub3d.h"

static void set_dir_plane(t_player *p, char c)
{
    if (c == 'N')
    {
        p->dir.x = 0;
        p->dir.y = -1;
        p->plane.x = 0.66;
        p->plane.y = 0;
    }
    else if (c == 'S')
    {
        p->dir.x = 0;
        p->dir.y = 1;
        p->plane.x = -0.66;
        p->plane.y = 0;
    }
    else if (c == 'E')
    {
        p->dir.x = 1;
        p->dir.y = 0;
        p->plane.x = 0;
        p->plane.y = 0.66;
    }
    else if (c == 'W')
    {
        p->dir.x = -1;
        p->dir.y = 0;
        p->plane.x = 0;
        p->plane.y = -0.66;
    }
}

int init_player(t_game *g)
{
    int y;
    int x;
    char c;

    y = 0;
    while (y < g->map.height)
    {
        x = 0;
        while (x < g->map.width)
        {
            c = g->map.grid[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                g->player.pos.x = x + 0.5;
                g->player.pos.y = y + 0.5;
                set_dir_plane(&g->player, c);
                g->map.spawn_x = x;
                g->map.spawn_y = y;
                g->map.spawn_dir = c;
                g->map.grid[y][x] = '0'; /* diventa pavimento */
                return  (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}
