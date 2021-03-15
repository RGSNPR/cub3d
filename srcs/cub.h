#ifndef CUB_H
#define CUB_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>

typedef struct	s_player
{
	float					posx;
	float					posy;
	float					fov;
	float					p_angle;
}				t_player;

typedef struct	s_data
{
    void					*img_map;
	void					*img_3d;
	void					*mlx;
    void					*win;
    char					*addr_map;
	char					*addr_3d;
	char					**map;
	unsigned int			stolbs;
	unsigned int			stroks;
	int						line_length;
	int						bits_per_pixel;
	int						endian;
	t_player				player;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, char *addr);
void	draw_square(int size, int x, int y, t_data *data, unsigned int color, char *addr);
void	draw_rect(int xsize, int ysize, int x, int y, t_data *data, unsigned int color, char *addr);
int		key_hook(int keycode);
int		kubik_move(t_data data);
void	kubik_draw(int x, int y, t_data data, unsigned int color);
void	draw_map(t_data data);
char	**fill_map_array(t_data *data);
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

#define ESC			53
#define W			13
#define A			0
#define S			1
#define D			2
#define UP			126
#define DOWN		125
#define LEFT		123
#define RIGHT		124

#define MAP_SQUARE_SIZE	20
#define PLAYER_SIZE	2
#define STEP 4

#endif
