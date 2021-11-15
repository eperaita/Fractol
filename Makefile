NAME = fractol

CC = clang
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 
FFLAGS = -L . -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src/
OBJ_DIR = obj/

SRC = main.c\
	  recursive.c\
	  color.c\
	  utils.c\
	  hooks.c\

OBJ = $(SRC:.c=.o)

INCLUDES = libft.a


all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES) $(OBJ_DIR)
	@$(MAKE) -C mlx/
	mv mlx/libmlx.a .
	@$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) $(INCLUDES) $(FFLAGS) -o $(NAME)

$(INCLUDES): 
	@$(MAKE) -C libft/
	mv libft/libft.a .

$(OBJ): $(addprefix $(SRC_DIR), $(SRC))
	@$(CC) $(CFLAGS) -c $^
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)

clean:
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean
	@$(RM) $(addprefix $(OBJ_DIR), $(OBJ)) 

fclean: clean
	@rm -rf $(OBJ_DIR)
	@$(RM)  libft.a
	@$(RM)  libmlx.a

re:	fclean all

.PHONY: all clean fclean re bonus
