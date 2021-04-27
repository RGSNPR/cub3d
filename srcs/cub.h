#ifndef CUB_H
# define CUB_H

//# include "../mlx/mlx.h"
# include "../loh/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct s_player
{
	double					posx;
	double					posy;
	double					fov;
	double					p_angle;
	short					w;
	short					a;
	short					s;
	short					d;
	short					left;
	short					right;
}				t_player;

typedef struct s_sizes
{
	size_t					win_h;
	size_t					win_w;
	size_t					map_h;
	size_t					map_w;
	size_t					tex_h;
	size_t					tex_w;
}				t_sizes;

typedef struct s_texs
{
	int						sizeh;
	int						sizew;
	void					*img;
	char					*addr;
	int						line_length;
	int						bits_per_pixel;
	int						endian;
}				t_texs;

typedef struct s_sprite
{
	double					pos_x;
	double					pos_y;
	double					len;
	double					dir;
	double					dist;
	double					koef;
	short					h_offset;
	short					v_offset;
	int						screen_size;

}				t_sprite;

typedef struct s_wall
{
	int		hwall;
	int		start;
	int		end;
	int		fpoint;
	int		tex_y;
	int		tex_x;
	int		color;
	double	koef_y;
	double	koef_x;
}			t_wall;

typedef struct s_tx
{
	double	len;
	int		x;
}			t_tx;

typedef struct s_ray
{
	double					ax;
	double					ay;
	double					x;
	double					y;
	double					lenx;
	double					leny;
}				t_ray;

typedef struct s_data
{
	void					*img_map;
	void					*img_3d;
	void					*mlx;
	void					*win;
	char					*addr_map;
	char					*addr_3d;
	char					**map;
	char					*map_file;
	unsigned int			stolbs;
	unsigned int			stroks;
	int						line_length;
	int						bits_per_pixel;
	int						endian;
	double					wall_x;
	double					wall_y;
	double					tex_x;
	int						count_sprite;
	int						count_params;
	int						floor_tex;
	int						ceiling_tex;
	int						map_flag;
	t_player				player;
	t_sizes					sizes;
	t_sprite				*sprites;
	t_texs					n_tex;
	t_texs					sprite;
	t_texs					w_tex;
	t_texs					s_tex;
	t_texs					e_tex;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	exit_error(char *error);
int		key_hook(t_data *data);
int		get_clr(t_texs *data, int x, int y, char *addr);
int		kubik_move(t_data data);
int		check_1st_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int		check_2nd_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int		check_3rd_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int		check_4th_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int		is_parameter(char *line);
int		key_release(int keycode, t_data *data);
int		red_cross(void);
int		key_press(int keycode, t_data *data);
int		draw_hook(t_data *data);
int		key_hook(t_data *data);
int		get_clr(t_texs *data, int x, int y, char *addr);
void	pl_move_fwd(t_data *data);
void	pl_move_bwd(t_data *data);
void	pl_move_lft(t_data *data);
void	pl_move_rght(t_data *data);
void	pl_turn_left(t_data *data);
void	pl_turn_right(t_data *data);
void	raycast_1st(t_ray *ray, t_data *data, double ang);
void	raycast_2nd(t_ray *ray, t_data *data, double ang);
void	raycast_3rd(t_ray *ray, t_data *data, double ang);
void	raycast_4th(t_ray *ray, t_data *data, double ang);
double	raycasting(t_data *data, double ang);
void	render(t_data *data);
void	take_pix(t_data *data, int line, int *x, int y);
void	take_line(t_data *data);
void	name_file(t_data *data, int fd);
void	screenshot(t_data *data);
void	calculate_point_div_neg(t_data *data, t_ray *ray, double ang);
void	calculate_point_mul_neg(t_data *data, t_ray *ray, double ang);
void	calculate_point_div_pos(t_data *data, t_ray *ray, double ang);
void	calculate_point_mul_pos(t_data *data, t_ray *ray, double ang);
void	init_data(t_data *data);
void	ext_data_init(t_data *data);
void	exit_error(char *error);
void	put_sprite_to_window(t_data *data, t_sprite *sprite, int j, int i);
void	find_map(t_data *data, int fd, char **line);
void	clean_array(char **arr);
void	draw_map(t_data *data);
void	draw_wall(t_data *data, double ang, t_tx *tx, t_texs *texs);
void	draw_sprite(t_data *data, t_sprite *sprite, double *arr);
void	draw_floor(t_data *data, unsigned int color);
void	draw_ceiling(t_data *data, unsigned int color);
void	check_dvoyki(t_data *data);
void	swap_sprite(t_sprite *sprite_1, t_sprite *sprite_2);
void	sort_sprites(t_data *data);
void	check_player(t_data *data);
int		check_line(char *line, char *set);
int		check_map_line(char *line, char *set);
void	check_map_item(t_data *data, char **map);
void	check_map_unit(char **map, int i, int j);
void	check_map_validity(t_data *data, char **map);
void	sort_sprites(t_data *data);
char	**fill_map_array(t_data *data);
char	*parser(t_data *data);
char	*check_tex(t_data *data, char *line);
char	*check_res(t_data *data, char *line);
int		check_format(char *map_name);
int		darr_len(char **arr);
int		check_format(char *map_name);
int		clr_atoi(const char *str);
//void	draw_3d(t_data *data, unsigned int c, int i, int x, int y);

# define TURQUOISE	0x0000CED1
# define RED			0x00FF0000
# define BLUE		0x000000FF
# define GREEN		0x00008000
# define YELLOW		0x00FFFF00
# define WHITE		0x00FFFFFF
# define PURPLE		0x00800080
# define GREY		0x00808080
# define PINK		0x00FF69B4
# define SKY			0x0087CEEB

# define ESC			53
# define W			13
# define A			0
# define S			1
# define D			2
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124

# define R			"R"
# define NO			"NO"
# define SO			"SO"
# define WE			"WE"
# define EA			"EA"
# define SS			"S"
# define F			"F"
# define C			"C"

# define MSS 20
# define PLAYER_SIZE	5
# define STEP 2
# define STEP_DIR 0.05

#endif
