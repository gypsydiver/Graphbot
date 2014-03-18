%{
//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Parser verificador de gramática correcta de graphbot

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include "Generador.h" 
using namespace std;

// Tabla de variables
typedef map<string, int> TablaVar;
TablaVar tabla;
// Directorio de Procedimientos
multimap <string, TablaVar> dirProc;

// Iteradores
multimap<string, TablaVar >::iterator proc;
map<string, int>::iterator tab;

// Generador de código intermedio
Generador generador;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int yylineco;

// Funciones de errores
void yyerror(const char *s);
void errores(int i, string val);

// Imprime tabla de variables;
void print();

%}
%union {
	char *sval;
	char cval;
}

//Bison declarations
//Comandos de cero parámetros
%token <sval> RW_SHOW RW_HIDE RW_CLEAN RW_HOME RW_GETCOLORR RW_GETCOLORB RW_GETCOLORG RW_GETPENSIZE RW_GETX RW_GETY RW_STOPMUSIC RW_PLAYMUSIC
//comandos de un parámetro
%token <sval> RW_MOVE RW_TURN RW_SETX RW_SETY RW_SETPENSIZE RW_CAMERAUP RW_CAMERADOWN RW_CAMERALEFT RW_CAMERARIGHT RW_SETBACKGROUNDTXT
//comandos de dos parámetros
%token <sval> RW_SAVE
//comandos de tres parámetros
%token <sval> RW_SETCOLOR RW_SETBACKGROUND
//palabras reservadas
%token <sval> RW_FUNCTION RW_END RW_TRUE RW_FALSE RW_BOOLEAN RW_PROGRAM RW_FOR RW_WHILE RW_IF RW_FLOAT
//caractéres del lenguaje
%token <cval> OP_BRACKET CL_BRACKET OP_PAR CL_PAR COMMA
//comparadores
%token <cval> EQUAL GREAT_THAN LESS_THAN
%token <sval> NOT_EQUAL GREAT_EQ_THAN LESS_EQ_THAN
//operandos y operadores
%token <sval> BASIC_ARITHMETIC COM_ARITHMETIC ID FLOAT

%type <sval> varCte;
%start graphbot
%%

//Grammar rules
graphbot: 
	graph programa {
		cout<<"Compilación Exitosa"<<endl;
	}
	;


graph: /*empty*/ 
	| funcion graph 
 	;

funcion:
	RW_FUNCTION ID parametros funciones RW_END {
        proc = dirProc.find($2);
        // Busca si la función no esta ya dentro del directorio de procedimientos
        if(proc == dirProc.end())
        // Agrega función al directorio con su respectiva tabla de variables
        dirProc.insert(make_pair ($2, tabla));
        else
        errores(1, $2);
    }
	;

parametros: /* empty */ 
	| var parametros
	;

funciones: 
	 for funcion_aux 
    | comandos funcion_aux
	| while funcion_aux
	| condicion funcion_aux
	;

funcion_aux: /* empty */ 
	| funciones
	;

var: 
	var1 ID var2 {
		// Agrega variable a la tabla
		tabla.insert(make_pair($2, 0));
    }  
	;

var1: 
	RW_FLOAT 		{cout<<"Matched RW_FLOAT"<<endl;}
	| RW_BOOLEAN	{cout<<"Matched RW_BOOLEAN"<<endl;}
	;

var2: /* empty */ 
	| COMMA var
	;

programa:
	RW_PROGRAM ID funciones RW_END {
		// Agrega procedimiento main al directorio 
		dirProc.insert(make_pair ($2, tabla));
	}
	;

comandos: 
	comando {
		//comandos que regresan nada
         generador.start(5);
	}
	| comando_return{
		//comandos que regresan algún valor
	}
    | comando1 expresion{
    	generador.genera($1,$2,"",1);
    }
    | RW_SAVE ID variable {	
		// Agrega una variable a la tabla de variables
        tabla.insert(make_pair($2, 0));
	}
	| RW_SETPOS expresion expresion {
		cout<<"Matched COMANDO2 via RW_SETPOS"<<endl;
	}
	| comando3 expresion expresion expresion {
		//pending
	}
	| llamada_funcion {
		//pending
	}
	;

llamada_funcion_aux: /* empty */
	| expresion llamada_funcion_aux
	;

llamada_funcion:
	ID llamada_funcion_aux {
		proc = dirProc.find($1);
		// Busca si la función no esta ya dentro del directorio de procedimientos
		if(proc == dirProc.end())
		errores(3, $1); 
    }
	;

comando: 
	RW_SHOW 		{cout<<"Matched RW_SHOW"<<endl;
	    generador.pushPOper($1);

}
	| RW_HIDE 		{cout<<"Matched RW_HIDE"<<endl;}
	| RW_CLEAN 		{cout<<"Matched RW_CLEAN"<<endl;}
	| RW_HOME 		{cout<<"Matched RW_HOME"<<endl;}
	| RW_PLAYMUSIC 	{cout<<"Matched RW_PLAYMUSIC"<<endl;}
	| RW_STOPMUSIC	{cout<<"Matched RW_STOPMUSIC"<<endl;}
	;

comando_return:
	RW_GETCOLORR 	{cout<<"Matched RW_GETCOLORR"<<endl;}
	| RW_GETCOLORB 	{cout<<"Matched RW_GETCOLORG"<<endl;}
	| RW_GETCOLORG 	{cout<<"Matched RW_GETCOLORB"<<endl;}
	| RW_GETPENSIZE {cout<<"Matched RW_GETPENSIZE"<<endl;}
	| RW_GETX 		{cout<<"Matched GETX"<<endl;}
	| RW_GETY 		{cout<<"Matched GETY"<<endl;}
	;

comando1: 
	RW_MOVE 				{cout<<"Matched RW_MOVE"<<endl;}
	| RW_TURN 				{cout<<"Matched RW_TURN"<<endl;}
	| RW_SETX 				{cout<<"Matched RW_SETX"<<endl;}
	| RW_SETY 				{cout<<"Matched RW_SETY"<<endl;}
	| RW_SETPENSIZE 		{cout<<"Matched RW_SETPENSIZE"<<endl;}
	| RW_SETBACKGROUNDTXT 	{cout<<"Matched RW_SETBACKGROUNDTXT"<<endl;}
	| RW_CAMERAUP 			{cout<<"Matched RW_CAMERAUP"<<endl;}
	| RW_CAMERADOWN 		{cout<<"Matched RW_CAMERADOWN"<<endl;}
	| RW_CAMERALEFT 		{cout<<"Matched RW_CAMERALEFT"<<endl;}
	| RW_CAMERARIGHT		{cout<<"Matched RW_CAMERARIGHT"<<endl;}
	;

comando3: 
	RW_SETCOLOR {cout<<"Matched RW_SETCOLOR"<<endl;}
	| RW_SETBACKGROUND 	{cout<<"Matched RW_SETBACKGROUND"<<endl;}
	;

variable:
	 expresion 	{cout<<"Matched SAVE_EXPRESION"<<endl;}
	| lista 	{cout<<"Matched SAVE_LISTA"<<endl;}
	;

for: 
	RW_FOR for_aux lista {
		cout<<"Matched RW_FOR"<<endl;
	}
	;

for_aux:
	OP_BRACKET ID COMMA expresion COMMA expresion COMMA expresion CL_BRACKET {
		// Agrega una variable a la tabla de variables
        tabla.insert(make_pair($2, 0));
	}
	;

while: 
	RW_WHILE expresion lista 	{cout<<"Matched RW_WHILE"<<endl;}
	;

condicion: 
	RW_IF expresion lista 		{cout<<"Matched RW_IF"<<endl;}
	;

lista:
	OP_BRACKET funciones lista_aux CL_BRACKET 	{cout<<"Matched LISTA"<<endl;}
	;

lista_aux: /* empty */ 
	| COMMA funciones lista_aux
	;

expresion: 
	exp exp_aux		{cout<<"Matched EXPRESION via EXP"<<endl;}
	;

exp_aux: /* empty */
    | comparador exp
    ;

exp:
	termino termino_aux	{ 	
		// 5.- Si pop(POper) == '+' o '-'
        generador.start(1);	}  
	;

termino_aux: /* empty */
    | BASIC_ARITHMETIC exp 	{	
		// 3.- Meter $2 ('+' o '-') a POper
	    generador.pushPOper($1);
	}

termino:
	factor factor_aux {	
		// 4.- Si pop(POper) == '*' o '/'
        generador.start(2); }
	;

factor_aux: /* empty */
	| COM_ARITHMETIC termino {
		// 2.- Meter $2 ('*' o '/') a POper  
		generador.pushPOper($1); 
	}
    ;

factor: 
    OP_PAR expresion CL_PAR {
    	cout<<"Matched FACTOR"<<endl;
    }

    | varCte {
		cout<<"1.- Meter $1 a PilaO"<<endl;
		// 1.- Meter $1 a PilaO
		generador.pushPilaO($1);
	}
    ;

varCte:
	ID {
		cout<<"Matched varCte via ID: "<<$1<<endl;
		tab = tabla.find($1);
		// Busca si la variable no esta declarada
		if(tab == tabla.end())
		errores(2, $1);
		$$ = $1;
	}

	| FLOAT	{
		cout<<"Matched varCte via FLOAT: "<<$1<<endl;
		$$ = $1;
	}

	| RW_TRUE {
		cout<<"Matched varCte via TRUE"<<endl;
   		$$ = $1;
	}

	| RW_FALSE {
		cout<<"Matched varCte via FALSE"<<endl;
		$$ = $1;
    }
	;

comparador: 
	EQUAL 				{cout<<"Matched COMPARADOR via EQUAL"<<endl;}
	| NOT_EQUAL 		{cout<<"Matched COMPARADOR via NOT_EQUAL"<<endl;}
	| GREAT_EQ_THAN 	{cout<<"Matched COMPARADOR via GREAT_EQ_THAN"<<endl;}
	| LESS_EQ_THAN 		{cout<<"Matched COMPARADOR via LESS_EQ_THAN"<<endl;}
	| GREAT_THAN 		{cout<<"Matched COMPARADOR via GREAT_THAN"<<endl;}
	| LESS_THAN 		{cout<<"Matched COMPARADOR via LESS_THAN"<<endl;}
	;
%%

int main(int argc, char ** argv) {
	// open a file handle to a particular file:
	FILE *myfile = fopen(argv[1], "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "No puedo abrir "<<argv[1]<< endl;
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
	cout << "BANG, error de parser: "<<s<<" en la línea "<<yylineco<< endl;
	// might as well halt now:
	exit(-1);
}

// Función que maneja los errores
void errores(int i, string val) {
	switch (i) {
		// La función ya se encuentra en el directorio de procedimientos 
		case 1: 
			cout << "Función "<< val << " ya declarada." << endl;
			exit(-1);
			break;

		// La variable no ha sido declarada
		case 2:
			cout << "Variable "<< val <<  " no declarada." <<  endl;
			exit(-1);
			break;

		// La función no esta declarada
		case 3:
			cout << "Función " << val << " no existe." << endl;
			exit(-1);
			break;
	} 
}

// Imprime el Directorio de Procedimientos
void print(){
	for ( proc=dirProc.begin() ; proc != dirProc.end(); proc++ ) {
		cout << "\n\nProcedimiento:\n" << (*proc).first << endl;
		for( tab=(*proc).second.begin(); tab != (*proc).second.end(); tab++){
			cout << (*tab).first << " => " << (*tab).second << endl;
		}
	}
}
