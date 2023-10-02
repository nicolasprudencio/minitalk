CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
LIBFT_DIR	=	./includes/libft/
LIBFT		=	-I $(LIBFT_DIR)header 
LIBS_LINK	=	-L $(LIBFT_DIR) -lrt -lm -lft
MINUNIT		=	-I ./includes/minunit 
INCLUDE		=	-I ./includes $(LIBFT) $(MINUNIT)

SRCS_QUEUE	=	enqueue.c dequeue.c queue_len.c enqueue_char.c queue_limit.c

SRCS_DECODE	=	dequeue_btoc.c

SRCS_ENCRYPT	=	char_to_bin.c

SRCS_SERVER	=	$(addprefix srcs/server/data/queue/,$(SRCS_QUEUE))
SRCS_SERVER	+=	$(addprefix srcs/server/decode/,$(SRCS_DECODE))

SRCS_CLIENT	=	$(addprefix srcs/client/polarium/encrypt/,$(SRCS_ENCRYPT))

OBJS_DIR		=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_SERVER:.c=.o))
OBJS_ALL	+=	$(addprefix $(OBJS_DIR)/,$(SRCS_CLIENT:.c=.o))


MAIN_SERVER	=	srcs/server/main.c
MAIN_NIKKO	=	srcs/client/nikko/main.c
MAIN_FAUNA	=	srcs/client/polarium/main.c
ENQUEUE_TEST	=	srcs/server/tests/enqueue_test.c
DEQUEUE_TEST	=	srcs/server/tests/dequeue_test.c
BTOC_TEST	=	srcs/server/tests/dequeue_btoc_test.c
CTOS_TEST	=	srcs/server/tests/char_to_bin_test.c
Q_LEN_TEST	=	srcs/server/tests/queue_len_test.c

ANSI		=	\033[0
YELLOW		=	;33
GREEN		=	;32
RED			=	;31

all: $(OBJS_ALL) libft_make server client

tests: $(OBJS_ALL) queue_test enqueue_test btoc_test

enqueue_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o enqueue_test $(ENQUEUE_TEST) $(LIBS_LINK)

dequeue_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o dequeue_test $(DEQUEUE_TEST) $(LIBS_LINK)
	
btoc_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o btoc_test $(BTOC_TEST) $(LIBS_LINK)

ctos_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o ctos_test $(CTOS_TEST) $(LIBS_LINK)

qlen_test: $(OBJS_ALL) libft_make
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o qlen_test $(Q_LEN_TEST) $(LIBS_LINK)

libft_make:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ $(INCLUDE)

server: $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(INCLUDE) -o $@ $(MAIN_SERVER) $(LIBS_LINK)
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "server:" "Compiled"

client: $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN_FAUNA) $(INCLUDE) -o client_fauna $(LIBS_LINK)
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "client_fauna:" "Compiled"
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN_NIKKO) $(INCLUDE) -o client_nikko $(LIBS_LINK)
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "client_nikko:" "Compiled"

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf client_fauna
	@rm -rf client_nikko

fclean: clean
	@rm -rf enqueue_test
	@rm -rf dequeue_test
	@rm -rf btoc_test
	@rm -rf qlen_test
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all tests enqueue_test dequeue_test btoc_test q_len_test libft_make server client clean f_clean re
