# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmita <mmita@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 15:19:46 by mmita             #+#    #+#              #
#    Updated: 2023/07/11 15:46:57 by mmita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		init.c \
		algorithm.c \
		mini_alg.c \
		pos.c \
		move.c \
		cost.c \
		\
		utils.c \
		utils_input.c \
		utils_check.c \
		utils_stack.c \
		utils_ft.c \
		\
		push.c \
		swap.c \
		rotate.c \
		r-rotate.c \

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRCS	= $(addprefix $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./include/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "${GREEN} ◎ $(YELLOW)Compilando ${RED} ▢ ▢ ▢ ▷  $(CYAN)$< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< -o $@ $(INCS)
			
$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
			
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

	@echo "$(GREEN)\n\nPush Swap compilado correctamente$(DEF_COLOR)\n"
clean:
	@ rm -rf $(OBJ_PATH)
	@echo "$(RED)	Objetos eliminados correctamente$(DEF_COLOR)\n"

fclean: clean
	@ rm -f $(NAME)
	@echo "$(RED)	Archivos eliminados correctamente$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
