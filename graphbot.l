%{
//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Definición de léxico

#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "graphbot.tab.h"
int yylineco = 1;
%}

%%
[ \t]				;
\n					{++yylineco;}
move 				{ yylval.sval = strdup(yytext); return RW_MOVE; }
turn 				{ yylval.sval = strdup(yytext); return RW_TURN; }
setpos				{ yylval.sval = strdup(yytext); return RW_SETPOS; }
setx 				{ yylval.sval = strdup(yytext); return RW_SETX; }
sety 				{ yylval.sval = strdup(yytext); return RW_SETY; }
setcolor 			{ yylval.sval = strdup(yytext); return RW_SETCOLOR; }
setpensize 			{ yylval.sval = strdup(yytext); return RW_SETPENSIZE; }
setbackground 		{ yylval.sval = strdup(yytext); return RW_SETBACKGROUND; }
setbackgroundtxt 	{ yylval.sval = strdup(yytext); return RW_SETBACKGROUNDTXT; }
show 				{ yylval.sval = strdup(yytext); return RW_SHOW; }
hide 				{ yylval.sval = strdup(yytext); return RW_HIDE; }
clean				{ yylval.sval = strdup(yytext); return RW_CLEAN; }
home 				{ yylval.sval = strdup(yytext); return RW_HOME; }
getcolorR 			{ yylval.sval = strdup(yytext); return RW_GETCOLORR; }
getcolorG 			{ yylval.sval = strdup(yytext); return RW_GETCOLORG; }
getcolorB 			{ yylval.sval = strdup(yytext); return RW_GETCOLORB; }
getpensize			{ yylval.sval = strdup(yytext); return RW_GETPENSIZE; }
getx 				{ yylval.sval = strdup(yytext); return RW_GETX; }
gety 				{ yylval.sval = strdup(yytext); return RW_GETY; }
function 			{ yylval.sval = strdup(yytext); return RW_FUNCTION; }
save 				{ yylval.sval = strdup(yytext); return RW_SAVE; }
end 				{ yylval.sval = strdup(yytext); return RW_END; }
playmusic			{ yylval.sval = strdup(yytext); return RW_PLAYMUSIC; }
stopmusic			{ yylval.sval = strdup(yytext); return RW_STOPMUSIC; }
cameraup 			{ yylval.sval = strdup(yytext); return RW_CAMERAUP; }
cameradown			{ yylval.sval = strdup(yytext); return RW_CAMERADOWN; }
cameraleft			{ yylval.sval = strdup(yytext); return RW_CAMERALEFT; }
cameraright			{ yylval.sval = strdup(yytext); return RW_CAMERARIGHT; }
program   			{ yylval.sval = strdup(yytext); return RW_PROGRAM; }
if   				{ yylval.sval = strdup(yytext); return RW_IF; }
for 				{ yylval.sval = strdup(yytext); return RW_FOR; }
while 				{ yylval.sval = strdup(yytext); return RW_WHILE; }
"["   				{ yylval.cval = yytext[0]; return OP_BRACKET; }
"]"   				{ yylval.cval = yytext[0]; return CL_BRACKET; }
"("   				{ yylval.cval = yytext[0]; return OP_PAR; }
")"   				{ yylval.cval = yytext[0]; return CL_PAR; }
","   				{ yylval.cval = yytext[0]; return COMMA; }
"=="   				{ yylval.sval = strdup(yytext); return EQUAL; }
"!=" 				{ yylval.sval = strdup(yytext); return NOT_EQUAL; }
">=" 				{ yylval.sval = strdup(yytext); return GREAT_EQ_THAN; }
"<="				{ yylval.sval = strdup(yytext); return LESS_EQ_THAN; }
"<"				   	{ yylval.sval = strdup(yytext); return LESS_THAN; }
">"				   	{ yylval.sval = strdup(yytext); return GREAT_THAN; }
"+"					{ yylval.sval = strdup(yytext); return ADD; }
"-"   				{ yylval.sval = strdup(yytext); return SUB; }
"*"					{ yylval.sval = strdup(yytext); return TIMES; }
"/"   				{ yylval.sval = strdup(yytext); return DIV; }
[[:alpha:]][[:alnum:]|_[:alnum:]]*	 	{ yylval.sval = strdup(yytext); return ID; }
[[:digit:]]+"."[[:digit:]]+			{ yylval.sval = strdup(yytext); return FLOAT; }
%%
