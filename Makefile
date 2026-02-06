# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 18:07:17 by demane            #+#    #+#              #
#    Updated: 2026/02/06 15:50:54 by demane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC= @cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM= @rm -rf
DIR_SRCS = srcs
DIR_OBJS = objs
DIR_PARSING = parsing
DIR_UTILS = utils

FILES_PARSING = parsing.c ft_atoil.c
FILES_UTILS = utils.c
FILES_MAIN = main.c


SRCS_PARSING = $(addprefix $(DIR_SRCS)/$(DIR_PARSING)/, $(FILES_PARSING))
SRCS_UTILS = $(addprefix $(DIR_SRCS)/$(DIR_UTILS)/, $(FILES_UTILS))
SRCS_MAIN = $(addprefix $(DIR_SRCS)/, $(FILES_MAIN))

SRCS = $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_MAIN)

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
	@printf "\n$(GREEN)✔ Build PHILOSOPHERS terminé$(RESET)\n"

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
