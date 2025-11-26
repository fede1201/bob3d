#include "../include/cub3d.h"

static char *init_line(void)
{
    char *line;

    line = (char *)malloc(1);
    if (!line)
        return (NULL);
    line[0] = '\0';
    return (line);
}

static char *process_buffer(char *line, char *buffer, size_t len, size_t n)
{
    char *new_line;

    if (buffer[0] == '\n')
        return (line);
    new_line = (char *)malloc(len + n + 1);
    if (!new_line)
    {
        free(line);
        return (NULL);
    }
    ft_strlcpy(new_line, line, len + 1);
    ft_strlcat(new_line, buffer, len + n + 1);
    free(line);
    return (new_line);
}

char *get_next_line(int fd)
{
    char    *line;
    char    buffer[2];
    ssize_t n;
    size_t  len = 0;

    line = init_line();
    if (!line)
        return (NULL);

    while ((n = read(fd, buffer, 1)) > 0)
    {
        buffer[n] = '\0';
        line = process_buffer(line, buffer, len, n);
        if (!line)
            return (NULL);
        len += n;
        if (buffer[0] == '\n')
            break;
    }
    if (n < 0 || (n == 0 && len == 0))
    {
        free(line);
        return (NULL);
    }
    return (line);
}
