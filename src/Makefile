LIBRARY_NAME = head
LIBRARY_FLAGS = -Wall
BINARY_FLAGS = -Wall

.PHONY: all
all: dynamic dynamic_sys

dynamic: dynamic_lib main.c
	gcc $(BINARY_FLAGS) main.c -l$(LIBRARY_NAME) -L. -o executable

dynamic_sys: dynamic_lib main_dyn.c
	gcc $(BINARY_FLAGS) main_dyn.c -ldl -o executable_dyn

#No dependencies since version control needs to be performed manually
dynamic_lib:
	gcc $(LIBRARY_FLAGS) -c $(LIBRARY_NAME).c
	gcc $(LIBRARY_FLAGS) -shared -o lib$(LIBRARY_NAME).so $(LIBRARY_NAME).o

.PHONY: clean
clean:
	rm -f *.o *.so executable executable_dyn
