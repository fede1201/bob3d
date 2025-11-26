#include "../include/cub3d.h"

static int map_weight(t_game *g)
{
    int max_width;
    int i;
    int line_length;

    max_width = 0;
    i = 0;
    while (g->map.grid[i])
    {
        line_length = ft_strlen(g->map.grid[i]);
        if (line_length > max_width)
            max_width = line_length;
        i++;
    }
    return (max_width);
}

static int trim_map_array(t_game *g, int start, int end){
    int i;

    i = 0;
    g->map.grid = (char **)malloc(sizeof(char *) * (end - start + 1));
    if (!g->map.grid)
        return (0);
    while (start < end)
    {
        g->map.grid[i] = ft_strdup(g->file[start]);
        i++;
        start++;
    }
    g->map.grid[i] = NULL;
    g->map.height = i;
    g->map.width = map_weight(g);
    return (1);
}

int trim_map(t_game *g)
{
    int     start;
    int     end;
   
    start = 0;
    while (g->file[start] && !ft_is_map_line(&g->file[start][0]))
        start++;
    end = start;
    while (g->file[end] && ft_is_map_line(&g->file[end][0]))
        end++;
    if (end == start)
        return (0);
    trim_map_array(g, start, end);
    return (1);
}
