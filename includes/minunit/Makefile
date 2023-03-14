################  COLORS	######################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG	TESTS	##################
DIR				=			../srcs/
DIR_OUTS		=			./outs/
EXEC_OUTS		=			$(wildcard $(DIR_OUTS)*)
YOUR_FILES		=			# Add your files with the function you can test
TESTS			=			# Add your test names without .c
HEADERS_TEST 	= 			minunit.h
################ CONFIG YOUR PROJECT #############
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		######################

all: 		$(TESTS) $(EXEC_OUTS)
	@echo $(EXEC_OUTS)

$(TESTS): $(HEADERS)
	$(CC)	-g $(addsuffix .c, $@) $(YOUR_FILES) -o $(addprefix $(DIR_OUTS), $@)

$(EXEC_OUTS):
	@echo  "$(L_YELLOWB)$@:$(L_WHITE) " && $@

clean:
	@rm			-f $(SRCS:.c=.o)
	@cd 		$(DIR) && $(MAKE) $@

fclean:			clean
	@rm 		-f $(EXEC_OUTS)
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

.PHONY: re fclean clean all $(TESTS) $(EXEC_OUTS)