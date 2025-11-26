#include "../include/cub3d.h"

void print_matrix(char **matrix)
{
    for (int i = 0; matrix[i] != NULL; i++)
    {
        printf("%s\n", matrix[i]);
    }
}

int	main(int argc, char **argv)
{
    t_game g;

	init_check(&g, argc, argv);
    print_matrix(g.file);
    start_parsing(&g);
    //debug_fill_game(&g);
    start_engine(&g);


	return (0);
}
