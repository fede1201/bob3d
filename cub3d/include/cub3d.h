#ifndef CUB3D_H
#define CUB3D_H

#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include "error_handler.h"
#include "struct_cub_3d.h"
# include "raycast.h"
# include "keycodes_mac.h" 
# include "../libft/libft.h"
# include "../mlx/mlx.h"

//main
void print_matrix(char **matrix);
//_______________________________

//utils
uint32_t	rgb_to_u32(int r, int g, int b);
char        *get_next_line(int fd);
int	        is_pure_num(const char *s);
void        free_split(char **m);
const char	*skip_ws(const char *s);
int         ft_is_map_line(const char *s);
//_______________________________

//init_check
void	init_check(t_game *g, int argc, char **argv);
void    check_args(int argc, char *argv[]);
int     check_ientifier_duplicate(char **file);
int     fill_check_start(t_game *g);
//_______________________________


//parsing


//debug
void debug_fill_game(t_game *g);

//engine
void	start_engine(t_game *g);
void	init_color_bg(t_game *g);
void	strcut_fill_bg(t_game *g);
void	draw_background(t_game *g);
void	create_framebuffer(t_game *g);
int		render_frame(t_game *g);
int		load_textures(t_game *g);
void	draw_walls_tex(t_game *g);
void	destroy_framebuffer(t_game *g);
void	zbuffer_destroy(t_game *g);
void	cleanup_game(t_game *g);
int		hook_close(t_game *g);
int   hook_key_press(int key, t_game *g);
int   hook_key_release(int key, t_game *g);
int   hook_close(t_game *g);
void  hooks_init(t_game *g);
void  handle_input(t_game *g);
int   can_walk(t_game *g, double nx, double ny);
void  cleanup_game(t_game *g);
int   zbuffer_create(t_game *g);
void  zbuffer_destroy(t_game *g);

//_______________________________

void	check_open_and_valid(const char *path);
void    read_file(t_game *g, const char *filename);

//parse controll
int start_parsing(t_game *g);

//colors parsing
int     parse_ceiling_color(t_game *g, char **file);
int     parse_floor_color(t_game *g, char **file);
int     parse_color_id_in_file(t_rgb *dst, char **file, char id);
//_______________________________

//textures parsing
int     texture_start(t_game *g, char **file);
//_______________________________

//map parsing
int     trim_map(t_game *g);
int init_player(t_game *g);
//_______________________________

#endif