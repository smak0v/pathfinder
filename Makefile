APP_NAME = pathfinder

LIBMXF = libmx

LIB_NAME = libmx.a

INC = \
libmx.h \
pathfinder.h

INCF = \
libmx/inc/libmx.h \
inc/pathfinder.h

SRC = \
main.c \
mx_error_handler.c \
mx_check_all_lines.c \
mx_check_first_line.c \
mx_is_line_correct.c \
mx_parse_line.c \
mx_check_str_set.c \
mx_get_set_element_index.c \
mx_get_islands_matrix.c \
mx_get_islands.c \
mx_create_graph.c \
mx_create_adjacency_node.c \
mx_add_edge.c \
mx_get_all_paths.c \
mx_get_all_paths_util.c \
mx_get_all_min_paths.c \
mx_get_path_weight.c \
mx_print_path.c \
mx_print_all_paths.c \
mx_get_min_paths.c \
mx_generate_error.c \
mx_del_lists.c \
mx_del_graph.c \
mx_del_islands.c

SRCF = \
src/main.c \
src/mx_error_handler.c \
src/mx_check_all_lines.c \
src/mx_check_first_line.c \
src/mx_is_line_correct.c \
src/mx_parse_line.c \
src/mx_check_str_set.c \
src/mx_get_set_element_index.c \
src/mx_get_islands_matrix.c \
src/mx_get_islands.c \
src/mx_create_graph.c \
src/mx_create_adjacency_node.c \
src/mx_add_edge.c \
src/mx_get_all_paths.c \
src/mx_get_all_paths_util.c \
src/mx_get_all_min_paths.c \
src/mx_get_path_weight.c \
src/mx_print_path.c \
src/mx_print_all_paths.c \
src/mx_get_min_paths.c \
src/mx_generate_error.c \
src/mx_del_lists.c \
src/mx_del_graph.c \
src/mx_del_islands.c

OBJ = \
main.o \
mx_error_handler.o \
mx_check_all_lines.o \
mx_check_first_line.o \
mx_is_line_correct.o \
mx_parse_line.o \
mx_check_str_set.o \
mx_get_set_element_index.o \
mx_get_islands_matrix.o \
mx_get_islands.o \
mx_create_graph.o \
mx_create_adjacency_node.o \
mx_add_edge.o \
mx_get_all_paths.o \
mx_get_all_paths_util.o \
mx_get_all_min_paths.o \
mx_get_path_weight.o \
mx_print_path.o \
mx_print_all_paths.o \
mx_get_min_paths.o \
mx_generate_error.o \
mx_del_lists.o \
mx_del_graph.o \
mx_del_islands.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMXF)
	@cp $(SRCF) .
	@cp $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(OBJ) $(LIBMXF)/$(LIB_NAME) -o $(APP_NAME)
	@mkdir ./obj
	@mv $(OBJ) ./obj

uninstall:
	@make uninstall -C $(LIBMXF)
	@rm -rf $(APP_NAME)

clean:
	@make clean -C $(LIBMXF)
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf ./obj
	@rm -rf pathfinder.h.gch

reinstall: uninstall all
