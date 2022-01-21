# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 22:28:20 by aelousse          #+#    #+#              #
#    Updated: 2021/12/29 13:43:32 by aelousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
SRC = so_long.c get_next_line.c game_settings.c game_utils.c game_utils2.c game_utils3.c game_movement.c game_rules.c
BNS_SRC = so_long_bonus.c get_next_line.c game_settings_bonus.c game_utils.c game_utils2.c game_bonus.c game_movement.c game_rules.c game_animation.c
OBJS = ${SRC:.c=.o}
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
FFLAGS = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(FFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BOBJ)
	@$(CC) $(CFLAGS) $(FFLAGS) $(BNS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJS) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all
	@echo "Clear"

re: fclean all
