CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
NAME		= philo_bonus

SRC_DIR		= srcs
OBJ_DIR		= objs

SRCS		= $(SRC_DIR)/main.c \
			$(SRC_DIR)/parsing/ft_atoi.c \
			$(SRC_DIR)/utils/time.c \
			$(SRC_DIR)/utils/utils.c \
			$(SRC_DIR)/init/init_rules.c \
			$(SRC_DIR)/init/init_sems.c \
			$(SRC_DIR)/monitor/monitor.c \
			$(SRC_DIR)/routine/think_time.c \
			$(SRC_DIR)/routine/print_action.c \
			$(SRC_DIR)/routine/routine.c \
			$(SRC_DIR)/routine/child_process.c \
			$(SRC_DIR)/routine/setup_meal.c \
			$(SRC_DIR)/routine/eat_routine.c \
			$(SRC_DIR)/routine/sleep_think.c \
			$(SRC_DIR)/routine/cleanup_child.c \
			$(SRC_DIR)/routine/cleanup_parent.c \
			$(SRC_DIR)/routine/fork_loop.c \
			$(SRC_DIR)/routine/wait_loop.c \
			$(SRC_DIR)/routine/kill_loop.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
