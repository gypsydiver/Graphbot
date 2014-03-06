%{
//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Parser verificador de gramática correcta de graphbot

#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int yylineco;

void yyerror(const char *s);
%}
%union {
	float fval;
	char *sval;
	char cval;
}

//Bison declarations
%token <sval> RW_MOVE
%token <sval> RW_TURN
%token <sval> RW_SETPOS
%token <sval> RW_SETX
%token <sval> RW_SETY
%token <sval> RW_SETCOLOR
%token <sval> RW_SETPENSIZE
%token <sval> RW_SETBACKGROUND
%token <sval> RW_SETBACKGROUNDTXT
%token <sval> RW_SHOW
%token <sval> RW_HIDE
%token <sval> RW_CLEAN
%token <sval> RW_HOME
%token <sval> RW_GETCOLOR
%token <sval> RW_GETPENSIZE
%token <sval> RW_GETPOS
%token <sval> RW_GETX
%token <sval> RW_GETY
%token <sval> RW_FUNCTION
%token <sval> RW_SAVE
%token <sval> RW_END
%token RW_TRUE RW_FALSE
%token <sval> RW_BOOLEAN
%token <sval> RW_PLAYMUSIC
%token <sval> RW_STOPMUSIC
%token <sval> RW_CAMERAUP
%token <sval> RW_CAMERADOWN
%token <sval> RW_CAMERALEFT
%token <sval> RW_CAMERARIGHT
%token <sval> RW_PROGRAM
%token <sval> RW_FOR
%token <sval> RW_WHILE
%token <sval> RW_IF
%token <sval> RW_FLOAT
%token <cval> OP_BRACKET
%token <cval> CL_BRACKET
%token <cval> OP_PAR
%token <cval> CL_PAR
%token <cval> COMMA
%token <cval> EQUAL
%token <sval> NOT_EQUAL
%token <sval> GREAT_EQ_THAN
%token <sval> LESS_EQ_THAN
%token <cval> GREAT_THAN
%token <cval> LESS_THAN
%token <cval> BASIC_ARITHMETIC
%token <cval> COM_ARITHMETIC
%token <sval> ID
%token <fval> FLOAT
%%
//Grammar rules

graphbot: 
	graph programa {cout<<"Matched GRAPHBOT"<<endl;}
	;

graph: /*empty*/ 
	| funcion graph 
 	;

funcion:
	RW_FUNCTION ID funcion1 funcion2 RW_END {cout<<"Matched FUNCION"<<endl;}
	;

funcion1: /* empty */ 
	| var funcion1
	;

funcion2: 
	comandos funcion3 
	| for funcion3 
	| while funcion3 
	| condicion funcion3
	;

funcion3: /* empty */ 
	| funcion2
	;

var: 
	var1 ID var2 {cout<<"Matched VARIABLE_DE_FUNCION"<<endl;}
	;

var1: 
	RW_FLOAT 		{cout<<"Matched RW_FLOAT"<<endl;}
	| RW_BOOLEAN	{cout<<"Matched RW_BOOLEAN"<<endl;}
	;

var2: /* empty */ 
	| COMMA var
	;

programa:
	RW_PROGRAM ID funcion2 RW_END {cout<<"Matched PROGRAMA"<<endl;}
	;

comandos: 
	comando 
	| comando1 
	| comando2 
	| comando3
	| llamada_funcion
	;

llamada_funcion:
	ID llamada_funcion_aux	{cout<<"Matched FUNCION DEFINIDA POR EL USUARIO"<<endl;}
	;

llamada_funcion_aux: /* empty */
	|expresion llamada_funcion_aux


comando: 
	RW_SHOW 		{cout<<"Matched RW_SHOW"<<endl;}
	| RW_HIDE 		{cout<<"Matched RW_HIDE"<<endl;}
	| RW_CLEAN 		{cout<<"Matched RW_CLEAN"<<endl;}
	| RW_HOME 		{cout<<"Matched RW_HOME"<<endl;}
	| RW_GETCOLOR 	{cout<<"Matched RW_GETCOLOR"<<endl;}
	| RW_GETPENSIZE {cout<<"Matched RW_GETPENSIZE"<<endl;}
	| RW_GETPOS 	{cout<<"Matched RW_GETPOS"<<endl;}
	| RW_GETX 		{cout<<"Matched GETX"<<endl;}
	| RW_GETY 		{cout<<"Matched GETY"<<endl;}
	| RW_PLAYMUSIC 	{cout<<"Matched RW_PLAYMUSIC"<<endl;}
	| RW_STOPMUSIC	{cout<<"Matched RW_STOPMUSIC"<<endl;}
	;

comando1: 
	RW_MOVE expresion 					{cout<<"Matched RW_MOVE"<<endl;}
	| RW_TURN expresion 				{cout<<"Matched RW_TURN"<<endl;}
	| RW_SETX expresion 				{cout<<"Matched RW_SETX"<<endl;}
	| RW_SETY expresion 				{cout<<"Matched RW_SETY"<<endl;}
	| RW_SETPENSIZE expresion 			{cout<<"Matched RW_SETPENSIZE"<<endl;}
	| RW_SETBACKGROUNDTXT expresion 	{cout<<"Matched RW_SETBACKGROUNDTXT"<<endl;}
	| RW_CAMERAUP expresion 			{cout<<"Matched RW_CAMERAUP"<<endl;}
	| RW_CAMERADOWN expresion 			{cout<<"Matched RW_CAMERADOWN"<<endl;}
	| RW_CAMERALEFT expresion 			{cout<<"Matched RW_CAMERALEFT"<<endl;}
	| RW_CAMERARIGHT expresion			{cout<<"Matched RW_CAMERARIGHT"<<endl;}
	;

comando2: 
	RW_SETPOS expresion expresion	{cout<<"Matched COMANDO2 via RW_SETPOS"<<endl;}
	| RW_SAVE ID variable 			{cout<<"Matched COMANDO2 via RW_SAVE"<<endl;}
	;

comando3: 
	RW_SETCOLOR expresion expresion expresion 			{cout<<"Matched RW_SETCOLOR"<<endl;}
	| RW_SETBACKGROUND expresion expresion expresion	{cout<<"Matched RW_SETBACKGROUND"<<endl;}
	;

variable:
	FLOAT 		{cout<<"Matched SAVE_FLOAT"<<endl;}
	| expresion {cout<<"Matched SAVE_EXPRESION"<<endl;}
	| lista 	{cout<<"Matched SAVE_LISTA"<<endl;}
	;

for: 
	RW_FOR lista lista {cout<<"Matched RW_FOR"<<endl;}
	;

while: 
	RW_WHILE expresion lista 	{cout<<"Matched RW_WHILE"<<endl;}
	;

condicion: 
	RW_IF expresion lista 		{cout<<"Matched RW_IF"<<endl;}
	;

lista:
	OP_BRACKET lista1 CL_BRACKET 	{cout<<"Matched LISTA"<<endl;}
	;

lista1: FLOAT lista2 
	| expresion lista2 
	| comandos lista2
	;

lista2: /* empty */ 
	| COMMA lista1
	;

expresion: 
	exp 							{cout<<"Matched EXPRESION via EXP"<<endl;}
	| exp comparador exp 			{cout<<"Matched EXPRESION via EXP COMPARADOR EXP"<<endl;}
	| booleana comp_bool booleana 	{cout<<"Matched EXPRESION via COMPARACION BOOLEANA"<<endl;}
	| booleana 						{cout<<"Matched EXPRESION via VALOR BOOLEANO"<<endl;}
	;

booleana:
	RW_TRUE		{cout<<"Matched BOOLEANA via TRUE"<<endl;}
	|RW_FALSE	{cout<<"Matched BOOLEANA via FALSE"<<endl;}
	|ID 		{cout<<"Matched BOOLEANA via ID"<<endl;}
	;

exp:
	termino 	{cout<<"Matched <EXP> via <TERMINO>"<<endl;}
	|termino BASIC_ARITHMETIC exp {cout<<"Matched EXP via TERMINO BASIC_ARITHMETIC TERMINO"<<endl;}
	;

termino:
	factor 	{cout<<"Matched <TERMINO> via <FACTOR>"<<endl;}
	|factor COM_ARITHMETIC factor 	{cout<<"Matched <FACTOR> via <FACTOR> COM_ARITHMETIC <FACTOR>"<<endl;}
	;

factor: 
     OP_PAR expresion CL_PAR 	{cout<<"Matched FACTOR"<<endl;}
     | BASIC_ARITHMETIC varCte 	{cout<<"Matched <FACTOR> via BASIC_ARITHMETIC <varCte>"<<endl;}
     | varCte					{cout<<"Matched <FACTOR> via <varCte>"<<endl;}
     ;

varCte: 
	ID 		{cout<<"Found ID: "<<$1<<endl;}
	| FLOAT	{printf("Found FLOAT: %f\n",$1);}
	;

comparador: 
	EQUAL 				{cout<<"Matched COMPARADOR via EQUAL"<<endl;}
	| NOT_EQUAL 		{cout<<"Matched COMPARADOR via NOT_EQUAL"<<endl;}
	| GREAT_EQ_THAN 	{cout<<"Matched COMPARADOR via GREAT_EQ_THAN"<<endl;}
	| LESS_EQ_THAN 		{cout<<"Matched COMPARADOR via LESS_EQ_THAN"<<endl;}
	| GREAT_THAN 		{cout<<"Matched COMPARADOR via GREAT_THAN"<<endl;}
	| LESS_THAN 		{cout<<"Matched COMPARADOR via LESS_THAN"<<endl;}
	;

comp_bool:
	EQUAL 		{cout<<"Matched COMP_BOOL via EQUAL"<<endl;}
	|NOT_EQUAL	{cout<<"Matched COMP_BOOL via NOT_EQUAL"<<endl;}
	;
%%
int main(int argc, char ** argv) {
	
	// open a file handle to a particular file:
	FILE *myfile = fopen(argv[1], "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open "<<argv[1]<< endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		yyparse();

	} while (!feof(yyin));
}

void yyerror(const char *s) {
	cout << "BANG, parse error! Message: "<<s<<" at line "<<yylineco<< endl;
	// might as well halt now:
	exit(-1);
}