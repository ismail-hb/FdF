NAME	=	fdf
INC_DIR	=	src
SRC_DIR	=	src
OBJ_DIR	=	obj
INC	  	=	$(addprefix $(INC_DIR)/,	fdf.h)
SRC	  	=	$(addprefix $(SRC_DIR)/,	main.c)
OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_A =	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror
CINC	=	-I./libft -I$(HOME)/Desktop/minilibx
LFLAGS	=
LLIB	=	-L./libft -lft -L$(HOME)/Desktop/minilibx -lmlx	\
-framework OpenGL -framework AppKit
# -lm -lXext -lX11



all: libft $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) $(LLIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CINC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

libft:
	make -C ./libft

run:
	@make -s
	./fdf ../test_maps/42.fdf

re: fclean all

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

print:
	@echo "\n-------------------- FILES --------------------\n"
	@echo "NAME		$(NAME:%=\n%)\n"
	@echo "INC		$(INC:%=\n%)\n"
	@echo "SRC		$(SRC:%=\n%)\n"
	@echo "OBJ		$(OBJ:%=\n%)\n"
	@echo "\n-------------------- FLAGS --------------------\n"
	@echo "LLIB		$(LLIB:%=\n%)\n"
	@echo "LFLAGS	$(LFLAGS:%=\n%)\n"
	@echo "CFLAGS	$(CFLAGS:%=\n%)\n"
	@echo "CINC		$(CINC:%=\n%)\n"

.PHONY: all libft re clean fclean print
