# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 18:07:17 by demane            #+#    #+#              #
#    Updated: 2026/02/16 18:00:21 by demane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC= @cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM= @rm -rf
DIR_SRCS = srcs
DIR_OBJS = objs
DIR_PARSING = parsing
DIR_UTILS = utils
DIR_MONITOR = monitor
DIR_INIT = init
DIR_ROUTINE = routine

FILES_PARSING_BONUS = parsing_bonus.c ft_atoil.c
FILES_UTILS_BONUS = utils_bonus.c time_bonus.c
FILES_MAIN_BONUS = main_bonus.c
FILES_MONITOR_BONUS = watcher.c
FILES_INIT_BONUS = init_bonus.c
FILES_ROUTINE_BONUS = routine_bonus.c philo_bonus.c forks_bonus.c eat_bonus.c

SRCS_PARSING_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_PARSING)/, $(FILES_PARSING_BONUS))
SRCS_UTILS_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_UTILS)/, $(FILES_UTILS_BONUS))
SRCS_MONITOR_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_MONITOR)/, $(FILES_MONITOR_BONUS))
SRCS_ROUTINE_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_ROUTINE)/, $(FILES_ROUTINE_BONUS))
SRCS_INIT_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_INIT)/, $(FILES_INIT_BONUS))
SRCS_MAIN_BONUS = $(addprefix $(DIR_SRCS)/, $(FILES_MAIN_BONUS))

SRCS = $(SRCS_PARSING_BONUS) $(SRCS_UTILS_BONUS) $(SRCS_MONITOR_BONUS) $(SRCS_INIT_BONUS) $(SRCS_ROUTINE_BONUS) $(SRCS_MAIN_BONUS)

OBJS = $(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

RESET   = \033[0m
GREEN   = \033[32m
CYAN    = \033[36m
BOLD  = \033[1m


BAR_WIDTH = 20
FILE_WIDTH = 20
TOTAL     = $(words $(SRCS))
COUNT     = 0

define progress_bar
	@$(eval COUNT=$(shell echo $$(( $(COUNT) + 1 ))))
	@PERCENT=$$(($(COUNT) * 100 / $(TOTAL))); \
	FILLED=$$(($(COUNT) * $(BAR_WIDTH) / $(TOTAL))); \
	EMPTY=$$(($(BAR_WIDTH) - $$FILLED)); \
	FILE="$<"; \
	SHORT_FILE=$$(printf "%-*.*s" $(FILE_WIDTH) $(FILE_WIDTH) "$$FILE"); \
	printf "\r\033[K$(BOLD)$(CYAN)[BUILD] [$(NAME)]$(RESET) %s $(CYAN)[" "$$SHORT_FILE"; \
	printf "%0.s=" $$(seq 1 $$FILLED); \
	printf "%0.s " $$(seq 1 $$EMPTY); \
	printf "] %3d%%$(RESET)" $$PERCENT
endef

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\n$(GREEN)✔ Build PHILOSOPHERS BONUS terminé$(RESET)\n"

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(progress_bar)

aff_bonus:
	cat $(SRCS) >> file_bonus.txt

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
