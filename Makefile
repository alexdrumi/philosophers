NAME		=	philo
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
SRC			=	destroy.c eat_sleep_think_cycle.c ft_atoi_overflow.c init_mutexes.c \
				init_philos.c init_threads.c main.c monitoring_threads.c parse.c print.c \
				set_status.c utils.c
PREFIX_S	=	c
PREFIX_O	=	o
SRCS_P		=	srcs
OBJ_P		=	objs
OBJS		=	$(SRC:.c=.o)
RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Finished building philo"
	@echo "You can now run ./philo [number of philosophers] [time to die] [time to eat] [time to sleep] [amount to eat (optional)]"

%.o: %.c 
	@printf "Building object files.... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "Objects cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable cleaned"

re: fclean all
