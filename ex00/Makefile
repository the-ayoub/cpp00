NAME			= megaphone

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -MMD
DEPFLAGS		= -MMD -MF $(DEPDIR)/$*.d

SRCDIR			= src
OBJDIR			= obj
DEPDIR			= deps

SRCS = megaphone.cpp

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS			= $(OBJS:%.o=$(DEPDIR)/%.d)

all: dir $(NAME)

$(NAME): Makefile $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\033[1;33mCPP00 EX00 [✔]\033[0m"


$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@) $(dir $(DEPDIR)/$*.d)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

dir:
	@mkdir -p $(OBJDIR) $(DEPDIR)

clean:
	@rm -rf $(OBJDIR) $(DEPDIR)
	@echo "\033[1;33mCHAU\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re dir