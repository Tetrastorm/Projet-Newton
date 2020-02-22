##
## EPITECH PROJECT, 2019
## PSU_nmobjdump_2019
## File description:
## Makefile
##

# ----------------------------------------
#               Variables
# ----------------------------------------

NAME			=	planet_simulator

TESTNAME		=	unit_tests

CC				=	clang

CXX				=	clang++

CFLAGS			=	-Weverything					\
					-std=gnu11

CXXFLAGS		=	-Weverything					\
					-std=c++17

SRCFILES		=	main.c

TESTSRC			=

CPPFLAGS		=	-I include/

OBJDIR			=	obj

SRCDIR			=	src

LDDIRS			=

LDFLAGS			=	-lsfml-graphics					\
					-lsfml-window					\
					-lsfml-system

SRC				=	$(addprefix $(SRCDIR)/, $(SRCFILES))
OBJ				:=	$(SRC:.c=.o)
OBJ				:=	$(OBJ:.cpp=.o)

TESTOBJ			:=	$(TESTSRC:.c=.o)
TESTOBJ			:=	$(TESTOBJ:.cpp=.o)

# ----------------------------------------
#                 RULES
# ----------------------------------------

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p "$(OBJDIR)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/: $(SRCDIR)/%.cpp
	@mkdir -p "$(OBJDIR)"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDDIRS) $(LDFLAGS)

debug: CFLAGS += -g3
debug: CXXFLAGS += -g3
debug: fclean $(NAME)

tests_run: fclean $(TESTOBJ)
	$(CXX) -o $(TESTNAME) $(TESTOBJ) $(CPPFLAGS) $(LDDIRS) $(LDFLAGS)
	./$(TESTNAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
