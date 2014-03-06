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
getcolor 			{ yylval.sval = strdup(yytext); return RW_GETCOLOR; }
getpensize			{ yylval.sval = strdup(yytext); return RW_GETPENSIZE; }
getpos				{ yylval.sval = strdup(yytext); return RW_GETPOS; }
getx 				{ yylval.sval = strdup(yytext); return RW_GETX; }
gety 				{ yylval.sval = strdup(yytext); return RW_GETY; }
function 			{ yylval.sval = strdup(yytext); return RW_FUNCTION; }
save 				{ yylval.sval = strdup(yytext); return RW_SAVE; }
end 				{ yylval.sval = strdup(yytext); return RW_END; }
true 				{ yylval.sval = strdup(yytext); return RW_TRUE; }
false				{ yylval.sval = strdup(yytext); return RW_FALSE; }
bool 				{ yylval.sval = strdup(yytext); return RW_BOOLEAN; }
playmusic			{ yylval.sval = strdup(yytext); return RW_PLAYMUSIC; }
stopmusic			{ yylval.sval = strdup(yytext); return RW_STOPMUSIC; }
cameraup 			{ yylval.sval = strdup(yytext); return RW_CAMERAUP; }
cameradown			{ yylval.sval = strdup(yytext); return RW_CAMERADOWN; }
cameraleft			{ yylval.sval = strdup(yytext); return RW_CAMERALEFT; }
cameraright			{ yylval.sval = strdup(yytext); return RW_CAMERARIGHT; }
program   			{ yylval.sval = strdup(yytext); return RW_PROGRAM; }
float 				{ yylval.sval = strdup(yytext); return RW_FLOAT; }
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
"<"				   	{ yylval.cval = yytext[0]; return LESS_THAN; }
">"				   	{ yylval.cval = yytext[0]; return GREAT_THAN; }
"+"|"-"   			{ yylval.cval = yytext[0]; return BASIC_ARITHMETIC; }
"*"|"/"   			{ yylval.cval = yytext[0]; return COM_ARITHMETIC; }
[[:alpha:]][[:alnum:]|_[:alnum:]]*	 	{ yylval.sval = strdup(yytext); return ID; }
[[:digit:]]+"."[[:digit:]]+			{ yylval.fval = atof(yytext); return FLOAT; }
%%