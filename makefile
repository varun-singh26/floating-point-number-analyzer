
CC = gcc
FLAGS = -Wall -Werror -std=c99
APP = fp_analyzer




all: $(APP)_f $(APP)_d

$(APP)_f: $(APP).c main.c
	gcc $(FLAGS) $^ -o $@



$(APP)_d: $(APP).c main.c
	gcc $(FLAGS )-D DOUBLE $^ -o $@


clean: 
	rm -rf $(APP)_f $(APP)_d


