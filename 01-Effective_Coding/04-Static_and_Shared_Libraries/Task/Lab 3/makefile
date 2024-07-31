NAME:=main
NAME_STATIC:=$(NAME)_static
NAME_DYNAMIC:=$(NAME)_dynamic
LIBNAME:=libsum
SNAME:=$(LIBNAME).a
DNAME:=$(LIBNAME).so
SRC:=main.cpp
OBJ:=main.o
LIBSRC:=$(wildcard lib/*.cpp)
LIBOBJ:=$(LIBSRC:.cpp=.o)
ARFLAGS:=rcs
CFLAGS:= -Wall -fPIC
AR=ar
CC=g++


.PHONY: all clean run_static run_dynamic static dynamic

all: static dynamic $(NAME_STATIC) $(NAME_DYNAMIC)

run_static: $(NAME_STATIC)
	./$(NAME_STATIC)

run_dynamic: $(NAME_DYNAMIC)
	./$(NAME_DYNAMIC)

static: $(SNAME)

dynamic: $(DNAME)

$(SNAME): $(LIBOBJ)
	$(AR) $(ARFLAGS) $@  $^

$(DNAME): $(LIBOBJ)
	$(CC) -shared -o $@ $^

$(NAME_STATIC): $(OBJ) $(SNAME)
	$(CC) -o $@ $(OBJ) -L. -lsum

$(NAME_DYNAMIC): $(OBJ) $(DNAME)
	$(CC) -o $@ main.o -L. -lsum -Wl,-rpath,.

%(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $@
	
lib/%.o: lib/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBOBJ) $(SNAME) $(DNAME) $(NAME_STATIC) $(NAME_DYNAMIC)
