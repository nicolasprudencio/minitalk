CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
LIBFT_DIR	=	./includes/libft/
LIBFT		=	-I $(LIBFT_DIR)header 
LIBS_LINK	=	-L $(LIBFT_DIR) -lrt -lm -lft
MINUNIT		=	-I ./includes/minunit 
INCLUDE		=	-I ./includes $(LIBFT) $(MINUNIT)

SRCS_QUEUE	=	enqueue.c dequeue.c

SRCS_ALL	=	$(addprefix srcs/server/data/queue/,$(SRCS_QUEUE))

OBJS_DIR		=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_ALL:.c=.o))


MAIN_SERVER	=	srcs/server/main.c
MAIN_NIKKO	=	srcs/client/nikko/main.c
MAIN_FAUNA	=	srcs/client/polarium/main.c
ENQUEUE_TEST	=	srcs/server/tests/enqueue_test.c
DEQUEUE_TEST	=	srcs/server/tests/dequeue_test.c

ANSI		=	\033[0
YELLOW		=	;33
GREEN		=	;32
RED			=	;31

all: $(OBJS_ALL) libft_make server client

tests: $(OBJS_ALL) queue_test enqueue_test

enqueue_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o enqueue_test $(ENQUEUE_TEST) $(LIBS_LINK)

dequeue_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o dequeue_test $(DEQUEUE_TEST) $(LIBS_LINK)
	
libft_make:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ $(INCLUDE)

server: $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN_SERVER) -o $<
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "server:" "Compiled"

client: $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN_FAUNA) -o client_fauna
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "client_fauna:" "Compiled"
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN_NIKKO) -o client_nikko
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "client_nikko:" "Compiled"

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean

re: fclean all

.PHONY: all tests enqueue_test dequeue_test libft_make server client clean f_clean re