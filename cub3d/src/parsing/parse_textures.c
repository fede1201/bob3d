#include "../include/cub3d.h"

static int save_texture_generic(char **tex_path, const char *payload)
{
    *tex_path = ft_strdup(payload);
    if (!*tex_path)
        return (0);
    return (1);
}

static int save_texture_init(t_game *g, char *id, const char *payload)
{
    if (ft_strncmp(id, "NO", 2) == 0)
        return (save_texture_generic(&g->textures.no, payload));
    else if (ft_strncmp(id, "SO", 2) == 0)
        return (save_texture_generic(&g->textures.so, payload));
    else if (ft_strncmp(id, "WE", 2) == 0)
        return (save_texture_generic(&g->textures.we, payload));
    else if (ft_strncmp(id, "EA", 2) == 0)
        return (save_texture_generic(&g->textures.ea, payload));
    return (0);
}

static int extract_utils(t_game *g, const char *p, char *id)
{
    const char *payload;
    int ret;

    payload = ft_strtrim(p + ft_strlen(id), " \t\r\n");
    if (!payload)
        return (0);
    ret = save_texture_init(g, id, payload);
    free((void *)payload);
    return (ret);
}

static int texture_extract(t_game *g, const char *file, char *id)
{
    const char    *p;

    p = skip_ws(file);
    if (!p)
        return (0);
    if (ft_strncmp(p, id, ft_strlen(id)) == 0)
        return (extract_utils(g, p, id));
    return (1);
}

int    texture_start(t_game *g, char **file)
{
    int    i;

    i = 0;

    if(!check_ientifier_duplicate(file))
        return (0);
    while (file[i] && i < g->map.map_start_y)
    {
        texture_extract(g, file[i], "NO");
        texture_extract(g, file[i], "SO");
        texture_extract(g, file[i], "WE");
        texture_extract(g, file[i], "EA");
        i++;
    }

    if(!g->textures.no || !g->textures.so
       || !g->textures.we || !g->textures.ea)
        PRINT_ERR(ERR_MISS_ID);
    return (1);
}
