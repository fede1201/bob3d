#include "../include/cub3d.h"

int check_ientifier_duplicate(char **file)
{
    int count[4];
    int i;

    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    count[3] = 0;
    i = 0;

    while (file[i])
    {
        const char *p = skip_ws(file[i]);
        if (ft_strncmp(p, "NO", 2) == 0)
            count[0]++;
        else if (ft_strncmp(p, "SO", 2) == 0)
            count[1]++;
        else if (ft_strncmp(p, "WE", 2) == 0)
            count[2]++;
        else if (ft_strncmp(p, "EA", 2) == 0)
            count[3]++;
        i++;
    }
    if(count[0] > 1 || count[1] > 1 || count[2] > 1 || count[3] > 1)
        PRINT_ERR(ERR_DUP_ID);
    return (1);
}
