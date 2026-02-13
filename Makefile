# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 18:07:17 by demane            #+#    #+#              #
#    Updated: 2026/02/13 19:40:49 by demane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_BONUS = philo_bonus
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

FILES_PARSING = parsing.c ft_atoil.c
FILES_UTILS = utils.c time.c
FILES_MAIN = main.c
FILES_MONITOR = monitor.c
FILES_INIT = init_mutex.c
FILES_ROUTINE = routine.c philo.c forks.c eat.c

FILES_PARSING_BONUS = parsing_bonus.c ft_atoil.c
FILES_UTILS_BONUS = utils_bonus.c time_bonus.c
FILES_MAIN_BONUS = main_bonus.c
FILES_MONITOR_BONUS = watcher.c
FILES_INIT_BONUS = init_bonus.c
FILES_ROUTINE_BONUS = routine_bonus.c philo_bonus.c forks_bonus.c eat_bonus.c

SRCS_PARSING = $(addprefix $(DIR_SRCS)/$(DIR_PARSING)/, $(FILES_PARSING))
SRCS_UTILS = $(addprefix $(DIR_SRCS)/$(DIR_UTILS)/, $(FILES_UTILS))
SRCS_MONITOR = $(addprefix $(DIR_SRCS)/$(DIR_MONITOR)/, $(FILES_MONITOR))
SRCS_ROUTINE = $(addprefix $(DIR_SRCS)/$(DIR_ROUTINE)/, $(FILES_ROUTINE))
SRCS_INIT = $(addprefix $(DIR_SRCS)/$(DIR_INIT)/, $(FILES_INIT))
SRCS_MAIN = $(addprefix $(DIR_SRCS)/, $(FILES_MAIN))

SRCS_PARSING_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_PARSING)/, $(FILES_PARSING_BONUS))
SRCS_UTILS_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_UTILS)/, $(FILES_UTILS_BONUS))
SRCS_MONITOR_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_MONITOR)/, $(FILES_MONITOR_BONUS))
SRCS_ROUTINE_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_ROUTINE)/, $(FILES_ROUTINE_BONUS))
SRCS_INIT_BONUS = $(addprefix $(DIR_SRCS)/$(DIR_INIT)/, $(FILES_INIT_BONUS))
SRCS_MAIN_BONUS = $(addprefix $(DIR_SRCS)/, $(FILES_MAIN_BONUS))

SRCS = $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_MONITOR) $(SRCS_INIT) $(SRCS_ROUTINE) $(SRCS_MAIN)

SRCS_BONUS = $(SRCS_PARSING_BONUS) $(SRCS_UTILS_BONUS) $(SRCS_MONITOR_BONUS) $(SRCS_INIT_BONUS) $(SRCS_ROUTINE_BONUS) $(SRCS_MAIN_BONUS)

OBJS = $(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

OBJS_BONUS = $(SRCS_BONUS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

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

bonus: $(NAME_BONUS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\n$(GREEN)✔ Build PHILOSOPHERS terminé$(RESET)\n"

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@printf "\n$(GREEN)✔ Build PHILOSOPHERS BONUS terminé$(RESET)\n"

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(progress_bar)

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
