#include "../include/cub3d.h"

static int file_count(char **file)
{
    int c = 0;

    if (!file)
        return (0);
    while (file[c])
        c++;
    return (c);
}

static char **alloc_expanded_array(char **file, int count)
{
    char    **new_file;
    int     i;

    i = 0;
    new_file = malloc(sizeof(char *) * (count + 2));
    if (!new_file)
        return (NULL);
    while (i < count)
    {
        new_file[i] = file[i];
        i++;
    }
    new_file[count] = NULL;
    new_file[count + 1] = NULL;
    return (new_file);
}

static void append_line_to_file_array(char ***file, char *line)
{
    int     count;
    char    **new_file;
    size_t  llen;

    count = file_count(*file);
    new_file = alloc_expanded_array(*file, count);
    if (!new_file)
        return ;
    llen = ft_strlen(line);
    new_file[count] = malloc(llen + 1);
    if (!new_file[count])
    {
        free(new_file);
        return ;
    }
    ft_strlcpy(new_file[count], line, llen + 1);
    new_file[count + 1] = NULL;
    free(*file);
    *file = new_file;
}

void    read_file(t_game *g, const char *filename)
{
    char    *line;

    g->file_fd = open(filename, O_RDONLY);
    line = get_next_line(g->file_fd);
    while (line)
    {
        append_line_to_file_array(&(g->file), line);
        free(line);
        line = get_next_line(g->file_fd);
    }
    close(g->file_fd);
}
