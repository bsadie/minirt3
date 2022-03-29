.PHONY: all clean fclean re

CC = clang

CFLAGS= -Wall -Wextra -Werror -g
NAME = miniRT

SRCS_DIR = sources
INCL_DIR = includes

MINIRT = minirt
MAIN = main
PARSING = parsing
GEOMETRY = geometry
LIGHT = light
UTILS = utils

INCLUDES = $(INCL_DIR)/$(MINIRT)/minirt.h			\
			$(INCL_DIR)/$(GEOMETRY)/cylinder.h		\
			$(INCL_DIR)/$(GEOMETRY)/intersect.h		\
			$(INCL_DIR)/$(GEOMETRY)/plane.h			\
			$(INCL_DIR)/$(GEOMETRY)/quadratic.h		\
			$(INCL_DIR)/$(GEOMETRY)/ray.h			\
			$(INCL_DIR)/$(GEOMETRY)/sphere.h		\
			$(INCL_DIR)/$(GEOMETRY)/v3_operations.h	\
			$(INCL_DIR)/$(GEOMETRY)/v3.h			\
			$(INCL_DIR)/$(GEOMETRY)/matrix.h		\
			$(INCL_DIR)/$(LIGHT)/color.h			\
			$(INCL_DIR)/$(LIGHT)/color2.h			\
			$(INCL_DIR)/$(LIGHT)/color3.h			\
			$(INCL_DIR)/$(LIGHT)/shading.h			\
			$(INCL_DIR)/$(LIGHT)/shading_utils.h	\
			$(INCL_DIR)/$(LIGHT)/specular.h			\
			$(INCL_DIR)/$(PARSING)/scene.h			\
			$(INCL_DIR)/$(PARSING)/parse_objects.h	\
			$(INCL_DIR)/$(PARSING)/parse_scene.h	\
			$(INCL_DIR)/$(PARSING)/parser_utils_1.h	\
			$(INCL_DIR)/$(PARSING)/parser_utils_2.h	\
			$(INCL_DIR)/$(PARSING)/parser.h			\
			$(INCL_DIR)/$(PARSING)/scene.h			\
			$(INCL_DIR)/$(UTILS)/ft_1.h				\
			$(INCL_DIR)/$(UTILS)/ft_2.h				\
			$(INCL_DIR)/$(UTILS)/ft_3.h				\
			$(INCL_DIR)/$(UTILS)/get_next_line.h	\
			$(INCL_DIR)/$(UTILS)/get_next_line_utils.h	\
			$(INCL_DIR)/$(UTILS)/list.h				\
			$(INCL_DIR)/$(UTILS)/free.h

SRCS = $(SRCS_DIR)/$(MINIRT)/main.c					\
		$(SRCS_DIR)/$(MINIRT)/minirt.c				\
		$(SRCS_DIR)/$(GEOMETRY)/intersect.c			\
		$(SRCS_DIR)/$(GEOMETRY)/cylinder.c			\
		$(SRCS_DIR)/$(GEOMETRY)/plane.c				\
		$(SRCS_DIR)/$(GEOMETRY)/quadratic.c			\
		$(SRCS_DIR)/$(GEOMETRY)/ray.c				\
		$(SRCS_DIR)/$(GEOMETRY)/sphere.c			\
		$(SRCS_DIR)/$(GEOMETRY)/v3_operations.c		\
		$(SRCS_DIR)/$(GEOMETRY)/v3.c				\
		$(SRCS_DIR)/$(GEOMETRY)/matrix.c			\
		$(SRCS_DIR)/$(LIGHT)/color.c				\
		$(SRCS_DIR)/$(LIGHT)/color2.c				\
		$(SRCS_DIR)/$(LIGHT)/color3.c				\
		$(SRCS_DIR)/$(LIGHT)/shading.c				\
		$(SRCS_DIR)/$(LIGHT)/shading_utils.c		\
		$(SRCS_DIR)/$(LIGHT)/specular.c				\
		$(SRCS_DIR)/$(PARSING)/parse_objects.c		\
		$(SRCS_DIR)/$(PARSING)/parse_scene.c		\
		$(SRCS_DIR)/$(PARSING)/parser_utils_1.c		\
		$(SRCS_DIR)/$(PARSING)/parser_utils_2.c		\
		$(SRCS_DIR)/$(PARSING)/parser.c				\
		$(SRCS_DIR)/$(UTILS)/ft_1.c					\
		$(SRCS_DIR)/$(UTILS)/ft_2.c					\
		$(SRCS_DIR)/$(UTILS)/ft_3.c					\
		$(SRCS_DIR)/$(UTILS)/get_next_line.c		\
		$(SRCS_DIR)/$(UTILS)/get_next_line_utils.c	\
		$(SRCS_DIR)/$(UTILS)/list.c					\
		$(SRCS_DIR)/$(UTILS)/free.c



OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


b:
	$(CC) $(CFLAGS) -g $(SRCS)
	$(CC) -o test $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
