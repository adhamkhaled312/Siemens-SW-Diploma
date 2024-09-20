mylang: lex.yy.c y.tab.c
	gcc -g lex.yy.c y.tab.c -o mylang

lex.yy.c: y.tab.c mylang.l
	lex mylang.l

y.tab.c: mylang.y
	yacc -d mylang.y

clean: 
	rm -rf lex.yy.c y.tab.c y.tab.h mylang

