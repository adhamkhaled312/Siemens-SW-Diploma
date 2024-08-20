NAME:=main
NAME_STATIC:=$(NAME)_static
NAME_DYNAMIC:=$(NAME)_dynamic
LIBNAME:=libcalc
SNAME:=$(LIBNAME).a
DNAME:=$(LIBNAME).so
SRC:=main.cpp
OBJ:=main.o
LIBSRC:=$(wildcard *.c)
LIBOBJ:=$(LIBSRC:.c=.o)
ARFLAGS:=rcs
CFLAGS:= -Wall -fPIC
AR=ar
CC=gcc


#.PHONY:clean

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
	$(CC) -o $@ $< -L. -lcalc

$(NAME_DYNAMIC): $(OBJ) $(DNAME)
	$(CC) -o $@ $< -L. -lcalc -Wl,-rpath,.

%(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBOBJ) $(SNAME) $(DNAME) $(NAME_STATIC) $(NAME_DYNAMIC)
