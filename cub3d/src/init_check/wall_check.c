// #include "../include/cub3d.h"

// int advance_resolver(t_game *g, int y, int start, int end)
// {
//     int first_wall;
//     int last_wall;

//     first_wall = 0;
//     last_wall = 0;
//     while(g->map.grid[y - 1][start + 1] == '1' && start < ft_strlen(g->map.grid[y - 1]) -1)
//     {
//         start++;
//         if(first_wall_helper(g, y) <= (start -1) && first_wall_helper(g, y) >= (start +1))
//         {
//             first_wall = 1;
//             break;
//         }
//     }
//     while(g->map.grid[y - 1][end - 1] == '1' && end > 0)
//     {
//         end--;
//         if(last_wall_helper(g, y) <= (end -1) && last_wall_helper(g, y) >= (end +1))
//         {
//             last_wall = 1;
//             break;
//         }
//     }
//     return (first_wall && last_wall);
// }
// int valid_raw_closed(t_game *g, int y, int start, int end)
// {
//     if(first_wall_helper(g, y) <= (start -1) && first_wall_helper(g, y) >= (start +1) &&
//        last_wall_helper(g, y) <= (end -1) && last_wall_helper(g, y) >= (end +1))
//         return (0);
//     else
//         return(advance_resolver(g, y, start, end));
// }

// // int first_wall_helper(t_game *g, int y)
// {
//     int x;

//     x = 0;
//     while (g->map.grid[y][x])
//     {
//         if (g->map.grid[y][x] == '1')
//             return (x);
//         x++;
//     }
//     return (-1);
// }

// int last_wall_helper(t_game *g, int y)
// {
//     int x;

//     x = ft_strlen(g->map.grid[y]) - 1;
//     while (x >= 0)
//     {
//         if (g->map.grid[y][x] == '1')
//             return (x);
//         x--;
//     }
//     return (-1);
// }

// void    strt_wall_check(t_game *g)
// {
//     int y;
//     int x;
//     int last_row_start;
//     int last_row_end;
//     int last_raw_len;

//     y = 0;
//     x = 0;

//     if(y == '0' || y == g->map.height -1)
//     {
//             last_row_start = first_wall_helper(g, g->map.height -1);
            
//         while (g->map.grid[y][x])
//         {
//             if (g->map.grid[y][x] != '1' && g->map.grid[y][x] != ' ')
//                 PRINT_ERR("ERR_MAP_NOT_CLOSED");
//             x++;
//         }
//     }
    


// }