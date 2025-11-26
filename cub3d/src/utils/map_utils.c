#include "../include/cub3d.h"

int    ft_is_map_line(const char *s)
{
    int    i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (s[i] != '0' && s[i] != '1' && s[i] != 'N'
            && s[i] != 'S' && s[i] != 'E'
            && s[i] != 'W' && s[i] != ' ')
            return (0);
        i++;
    }
    
    return (i > 0);
}