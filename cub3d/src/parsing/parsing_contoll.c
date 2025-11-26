#include "../include/cub3d.h"

int start_parsing(t_game *g)
{
    if (!parse_floor_color(g, g->file))
        return (0);
    if (!parse_ceiling_color(g, g->file))
        return (0);
    if (!texture_start(g, g->file))
        return (0);
    if( !trim_map(g))
       return (0);
    if(!init_player(g))
        return (0);
    if(!fill_check_start(g))
        return (0);
        g->render.screen_w = 1024;
    g->render.screen_h = 768;
        g->player.move_speed = 0.06;
    g->player.rot_speed  = 0.04;
    printf("Floor color: R=%d G=%d B=%d\n", g->colors.floor_rgb.r, g->colors.floor_rgb.g, g->colors.floor_rgb.b);
    printf("Ceiling color: R=%d G=%d B=%d\n", g->colors.ceil_rgb.r, g->colors.ceil_rgb.g, g->colors.ceil_rgb.b);
    printf("Texture NO: %s\n", g->textures.no);
    printf("Texture SO: %s\n", g->textures.so);
    printf("Texture WE: %s\n", g->textures.we);
    printf("Texture EA: %s\n", g->textures.ea);
    printf("Map width: %d, height: %d\n", g->map.width, g->map.height);
    print_matrix(g->map.grid);
    printf("Player spawn: x=%d y=%d dir=%c\n", g->map.spawn_x, g->map.spawn_y, g->map.spawn_dir);
    printf("Player position: x=%.2f y=%.2f\n", g->player.pos.x, g->player.pos.y);
    printf("Player direction: x=%.2f y=%.2f\n", g->player.dir.x, g->player.dir.y);
    printf("Player plane: x=%.2f y=%.2f\n", g->player.plane.x, g->player.plane.y);

    return (1);
}