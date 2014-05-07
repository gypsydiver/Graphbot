clean:
	rm graphbot.output && rm graphbot.tab.* && rm lex.yy.c

reset:
	rm graphbot

graphbot.tab.c graphbot.tab.h: graphbot.y
	bison -dr all graphbot.y

lex.yy.c: graphbot.l graphbot.tab.h
	flex graphbot.l

graphbot: lex.yy.c graphbot.tab.c graphbot.tab.h
	g++ graphbot.tab.c lex.yy.c -ll -o graphbot
