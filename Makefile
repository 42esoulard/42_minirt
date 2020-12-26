NAME = miniRT
CC = clang
CFLAGS = -Wall -Wextra
CFLAGS += -Werror
#CFLAGS += -O3 -march=native
#CFLAGS += -fsanitize=address
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

LFLAGS = -L$(LIBFT_DIR)
LFLAGS += -lft -lmlx -framework OpenGL -framework AppKit
SRCS_DIR = sources/

SRCS =  navigation/navigation_cam_lights.c navigation/navigation_util.c \
	navigation/snippet_obj.c navigation/snippet_obj2.c navigation/snippet_util.c \
	parsing/file2.c parsing/parse_obj.c parsing/parse_obj2.c \
	parsing/parsing_amb.c parsing/parsing_cam.c parsing/parsing_checks.c \
	parsing/parsing_light.c parsing/parsing_util.c parsing/parsing_vector.c \
	parsing/parsing_win.c \
	vectors/color_util.c vectors/color_util2.c vectors/vector_util.c \
	vectors/vector_util2.c vectors/vector_util3.c \
	exit_functions.c intersect_light.c intersect_light1.c intersect_obj.c \
	intersect_obj1.c lights.c obj_cylinder.c obj_general_intersect.c \
	obj_plane.c obj_pyramid.c obj_sphere.c obj_square.c obj_triangle.c rotation.c \
	save_bmp.c

SRCS_REG = mini_rt.c routine.c parsing/file.c navigation/snippet.c navigation/snippet2.c

SRCS_BONUS = mini_rt_bonus.c routine_bonus.c parsing/file_bonus.c navigation/snippet_bonus.c \
	navigation/snippet2_bonus.c

INC_DIR = includes/
CFLAGS += -I$(INC_DIR)

INC = color_util.h file.h intersect_light.h intersect_light1.h \
	intersect_obj.h intersect_obj1.h lights.h mini_rt.h \
	navigation_cam_lights.h navigation_util.h obj_cylinder.h \
	obj_general_intersect.h obj_plane.h obj_sphere.h obj_square.h \
	obj_triangle.h parse_obj.h parsing_amb.h parsing_cam.h \
	parsing_checks.h parsing_light.h parsing_util.h parsing_vector.h \
	parsing_win.h rotation.h routine.h snippet.h snippet2.h \
	snippet_obj.h snippet_util.h variables.h vector_util.h \
	save_bmp.h

SRCS := $(addprefix $(SRCS_DIR),$(SRCS)) 
SRCS_REG := $(addprefix $(SRCS_DIR),$(SRCS_REG))
SRCS_BONUS := $(addprefix $(SRCS_DIR),$(SRCS_BONUS)) 
INC := $(addprefix $(INC_DIR),$(INC))
OBJS_FILES = $(SRCS:.c=.o)
OBJS_REG = $(SRCS_REG:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(OBJS_FILES) $(OBJS_BONUS)
else
	OBJS = $(OBJS_FILES) $(OBJS_REG)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	@echo "\033[1;35m	-----> Libft ready to roll! <-----\033[0m"
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;35m	-----> MiniRT ready to sail! <-----\033[0m"

bonus:
	$(MAKE) WITH_BONUS=1 all
	@echo "\033[1;36m	-----> Bonus ready to sail! <-----\033[0m"

.c.o: $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "\033[1;33m	-----> Object files sent overboard! Arrr <-----\033[0m"

fclean :        clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	@echo "\033[1;33m	-----> The deck's clean, cap'n! <-----\033[0m"

re:             fclean all
	$(MAKE) re -C $(LIBFT_DIR)
	@echo "\033[1;35m	-----> All aboard the grrreat MiniRT ship! <-----\033[0m"

.phony: bonus clean re fclean all