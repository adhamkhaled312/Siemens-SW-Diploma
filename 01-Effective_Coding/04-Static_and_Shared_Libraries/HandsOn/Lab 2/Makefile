NAME    :=  expressionEval
LIBNAME    :=  expressionLib
SNAME   :=  $(LIBNAME).lib
DNAME   :=  $(LIBNAME).dll
SRC     :=  $(wildcard *.cpp)
LIBSRC     :=  $(wildcard lib/*.cpp)
OBJ     :=  $(SRC:.cpp=.o)
LIBOBJ     :=  $(LIBSRC:.cpp=.o)
CFLAGSLIB  :=  -ansi -pedantic -Wall -W -Werror -g3 -fPIC -std=c++0x
INC = -Ilib
CFLAGS  := -Wall -std=c++0x -lstdc++ $(INC)
LDFLAGS :=  -L. $(CFLAGSLIB)
LDLIBS  :=  -l$(...)
CC = g++

.PHONY: all clean fclean re

all: $(SNAME) $(DNAME)


expressionEvalNative:  $(LIBOBJ) $(OBJ) 
	$(CC) $(CFLAGS)  $^ -o $@ 

$(SNAME): $(LIBOBJ)
	$(AR) $(ARFLAGS) $@ $^

$(DNAME): LDFLAGS += -shared
$(DNAME): $(LIBOBJ)
	$(CC) $(LDFLAGS) $^ -o $@

expressionEvalStatic: $(OBJ) $(SNAME)
	$(CC) -o $@  $^

expressionEvalDynamic: $(OBJ) $(DNAME)
	$(CC) -o $@  $^

run: 
	./expressionEvalNative.exe
clean:
	rm *.o *.exe lib/*.o *.lib *.dll

fclean: clean
	rm $(SNAME) $(DNAME)

re: fclean all