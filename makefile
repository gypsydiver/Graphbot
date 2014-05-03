clean:
	rm graphbot.output && rm graphbot.tab.* && rm lex.yy.c

reset:
	rm MaquinaVirtual/Build/Products/Debug/constNum.txt
	rm MaquinaVirtual/Build/Products/Debug/CodigoInt.txt
	rm MaquinaVirtual/Build/Products/Debug/MaquinaVirtual

graphbot.tab.c graphbot.tab.h: graphbot.y
	bison -dr all graphbot.y

lex.yy.c: graphbot.l graphbot.tab.h
	flex graphbot.l

graphbot: lex.yy.c graphbot.tab.c graphbot.tab.h
	g++ graphbot.tab.c lex.yy.c -ll -o graphbot
