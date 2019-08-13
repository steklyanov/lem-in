NAME = lem_in
CC = gcc
FLAGS = 

LIBFT_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC		=	validation.c room_lst_fnctns.c algorithm.c service_fnctn.c main.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/inc

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft
	@./lem_in < testfile

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@rm -rf lem_in.dSYM

re: fclean all

norm:
	@make -C libft norm
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm