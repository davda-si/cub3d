NAME = cub3d

SRC_DIR = src
SRC = $(SRC_DIR)/calc_utils.c \
	  $(SRC_DIR)/calc_utils2.c \
	  $(SRC_DIR)/calculations.c \
	  $(SRC_DIR)/error.c \
	  $(SRC_DIR)/gen_utils.c \
	  $(SRC_DIR)/hehe.c \
	  $(SRC_DIR)/hook.c \
	  $(SRC_DIR)/main.c \
	  $(SRC_DIR)/map_parse.c \
	  $(SRC_DIR)/map_utils.c \
	  $(SRC_DIR)/map.c \
	  $(SRC_DIR)/mlx_diy.c \
	  $(SRC_DIR)/parser_utils.c \
	  $(SRC_DIR)/parser_utils2.c \
	  $(SRC_DIR)/parser_utils3.c \
	  $(SRC_DIR)/parser.c \
	  $(SRC_DIR)/render.c \
	  $(SRC_DIR)/rotations.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address 

MLXFLAGS = -L. -lXext -L. -lX11 -lm -lz -o3

LIBFT_PATH = ./inc/libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./inc/mlx_linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

OBJ_DIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White
BILGreen='\033[1;38;2;147;196;125m'

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

MSG1 = @echo ${BILGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${BILGreen}"Cleaned Successfully ✔︎"${Color_Off}
MSG3 = @echo ${BILGreen}"Cleaned ${NAME} Successfully ✔︎"${Color_Off}
HOWTO = @echo ${BIGreen}"To run the program write:"${BIWhite}"./${NAME} maps/[map]"${Color_Off}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)
	$(MSG1)
	$(HOWTO)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(MINILIBX):
	@make -s -C $(MINILIBX_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(OBJ_DIR)
	 $(MSG2)
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_PATH)
	 $(MSG3)

re: fclean all

.PHONY:         all clean fclean re
