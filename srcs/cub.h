#ifndef CUB_H
#define CUB_H

//# include "../mlx/mlx.h"
# include "../loh/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_player
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

typedef struct	s_sizes
{
	size_t					win_h;
	size_t					win_w;
	size_t					map_h;
	size_t					map_w;
	size_t					tex_h;
	size_t					tex_w;
}				t_sizes;

typedef struct	s_texs
{
	int						sizeh;
	int						sizew;
	void					*img;
	char					*addr;
	int						line_length;
	int						bits_per_pixel;
	int						endian;
}				t_texs;

typedef struct	s_sprite
{
	double					pos_x;
	double					pos_y;
	double					len;

}				t_sprite;

typedef struct	s_idens
{
	char					*res;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*s;
	char					*f;
	char					*c;
}				t_idens;

typedef struct	s_data
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, char *addr);
void	draw_square(int size, int x, int y, t_data *data, unsigned int color, char *addr);
void	draw_rect(int xsize, int ysize, int x, int y, t_data *data, unsigned int color, char *addr);
int		key_hook(t_data *data);
int		kubik_move(t_data data);
int check_vertical(t_data *data, float ang, float p_pos_x, float p_pos_y);
int check_horizontal(t_data *data, float ang, float p_pos_x, float p_pos_y);
int check_1st_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int check_2nd_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int check_3rd_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int check_4th_q(t_data *data, float ang, float p_pos_x, float p_pos_y);
int is_parameter(char *line);
void	find_map(t_data *data, int fd, char **line);
void	kubik_draw(int x, int y, t_data data, unsigned int color);
void	draw_map(t_data *data);
void	draw_sprite(t_data *data, t_sprite *sprite, double *arr);
void	draw_floor(t_data *data, unsigned int color, char *addr);
void	draw_ceiling(t_data *data, unsigned int color, char *addr);
void	check_dvoyki(t_data *data);
void	sort_sprites(t_data *data);
void	init_idens(t_idens *idens);
char	**fill_map_array(t_data *data);
char	*parser(t_data *data);
int		check_format(char *map_name);
//void	draw_3d(t_data *data, unsigned int c, int i, int x, int y);

#define TURQUOISE	0x0000CED1
#define RED			0x00FF0000
#define BLUE		0x000000FF
#define GREEN		0x00008000
#define YELLOW		0x00FFFF00
#define WHITE		0x00FFFFFF
#define PURPLE		0x00800080
#define GREY		0x00808080
#define PINK		0x00FF69B4
#define SKY			0x0087CEEB

#define ESC			53
#define W			13
#define A			0
#define S			1
#define D			2
#define UP			126
#define DOWN		125
#define LEFT		123
#define RIGHT		124

#define R			"R"
#define NO			"NO"
#define SO			"SO"
#define WE			"WE"
#define EA			"EA"
#define SS			"S"
#define F			"F"
#define C			"C"

#define MSS 10
#define PLAYER_SIZE	4
#define STEP 1
#define STEP_DIR 0.05

#endif
