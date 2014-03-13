%{
//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Parser verificador de gramática correcta de graphbot

#include <cstdio>
#include <iostream>
#include <map> 
using namespace std;

// Tabla de variables
typedef map<string, int> TablaVar;
TablaVar tabla;
// Directorio de Procedimientos
multimap <string, TablaVar> dirProc;

// Iteradores
multimap<string, TablaVar >::iterator proc;
map<string, int>::iterator tab;

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

%start graphbot

%%

//Grammar rules

graphbot: 
	graph programa {cout<<"Compilación Exitosa"<<endl;
                    print();}
	;

graph: /*empty*/ 
	| funcion graph 
 	;

funcion:
	RW_FUNCTION ID funcion1 funcion2 RW_END {

        proc = dirProc.find($2);
        // Busca si la función no esta ya dentro del directorio de procedimientos
        if(proc == dirProc.end())
        // Agrega función al directorio con su respectiva tabla de variables
        dirProc.insert(make_pair ($2, tabla));
        else
        errores(1, $2);

    }
	;

funcion1: /* empty */ 
	| var funcion1
	;

funcion2: 
	 for funcion3 
    | comandos funcion3
	| while funcion3 
	| condicion funcion3
	;

funcion3: /* empty */ 
	| funcion2
	;

var: 
	var1 ID var2 {
                 // Agrega variable a la tabla
                  tabla.insert(make_pair($2, 0));}   
	;

var1: 
	RW_FLOAT 		{cout<<"Matched RW_FLOAT"<<endl;}
	| RW_BOOLEAN	{cout<<"Matched RW_BOOLEAN"<<endl;}
	;

var2: /* empty */ 
	| COMMA var
	;

programa:
	RW_PROGRAM ID funcion2 RW_END {

               // Agrega procedimiento main al directorio 
                 dirProc.insert(make_pair ($2, tabla));

}
	;

comandos: 
	comando 
	| comando1 
	| comando2 
	| comando3
	| llamada_funcion
	;

llamada_funcion_aux: /* empty */
	| expresion llamada_funcion_aux
	;

llamada_funcion:
	ID llamada_funcion_aux	{

                proc = dirProc.find($1);
                // Busca si la función no esta ya dentro del directorio de procedimientos
                if(proc == dirProc.end())
                errores(3, $1); 
                }
	;


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
	| RW_SAVE ID variable 			{// Agrega una variable a la tabla de variables
                                    tabla.insert(make_pair($2, 0));}
	;

comando3: 
	RW_SETCOLOR expresion expresion expresion 			{cout<<"Matched RW_SETCOLOR"<<endl;}
	| RW_SETBACKGROUND expresion expresion expresion	{cout<<"Matched RW_SETBACKGROUND"<<endl;}
	;

variable:
	 expresion {cout<<"Matched SAVE_EXPRESION"<<endl;}
	| lista 	{cout<<"Matched SAVE_LISTA"<<endl;}
	;

for: 
	RW_FOR for_aux lista {cout<<"Matched RW_FOR"<<endl;}
	;

for_aux:
	OP_BRACKET ID COMMA expresion COMMA expresion COMMA expresion CL_BRACKET
	;

while: 
	RW_WHILE expresion lista 	{cout<<"Matched RW_WHILE"<<endl;}
	;

condicion: 
	RW_IF expresion lista 		{cout<<"Matched RW_IF"<<endl;}
	;

lista:
	OP_BRACKET comandos lista_aux CL_BRACKET 	{cout<<"Matched LISTA"<<endl;}
	;

lista_aux: /* empty */ 
	| COMMA comandos lista_aux
	;

expresion: 
	exp 							{cout<<"Matched EXPRESION via EXP"<<endl;}
	| exp comparador exp 			{cout<<"Matched EXPRESION via EXP COMPARADOR EXP"<<endl;}
	;

exp:
	termino 	{cout<<"Matched <EXP> via <TERMINO>"<<endl;}
	| termino BASIC_ARITHMETIC exp {cout<<"Matched EXP via TERMINO BASIC_ARITHMETIC TERMINO"<<endl;}
	;

termino:
	 factor 	{cout<<"Matched <TERMINO> via <FACTOR>"<<endl;}
	| factor COM_ARITHMETIC factor 	{cout<<"Matched <FACTOR> via <FACTOR> COM_ARITHMETIC <FACTOR>"<<endl;}
	;

factor: 
     OP_PAR expresion CL_PAR 	{cout<<"Matched FACTOR"<<endl;}
     | varCte					{cout<<"Matched <FACTOR> via <varCte>"<<endl;}
     ;

varCte:
	ID 				{cout<<"Matched varCte via ID: "<<$1<<endl;

                    tab = tabla.find($1);
                    // Busca si la variable no esta declarada
                    if(tab == tabla.end())
                    errores(2, $1);
                                                                }

	| FLOAT			{printf("Matched varCte via FLOAT: %f\n",$1);}
	| RW_TRUE		{cout<<"Matched varCte via TRUE"<<endl;}
	| RW_FALSE		{cout<<"Matched varCte via FALSE"<<endl;}
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
    print();
	// might as well halt now:
	exit(-1);
}

// Función que maneja los errores
void errores(int i, string val) {
    
    switch (i) {
        // La función ya se encuentra en el directorio de procedimientos 
        case 1: 
        cout << "Función "<< val << " ya declarada." << endl;
        print();
        exit(-1);
        break;

       // La variable no ha sido declarada
        case 2:
        cout << "Variable "<< val <<  " no declarada." <<  endl;
        print();
        exit(-1);
        break;

       // La función no esta declarada
        case 3:
        cout << "Función " << val << " no existe." << endl;
        print();
        exit(-1);
        break;
      } 
}

// Imprime el Directorio de Procedimientos
void print(){
  
     for ( proc=dirProc.begin() ; proc != dirProc.end(); proc++ ) {
        cout << "\n\nProcedimiento:\n" << (*proc).first << endl;
     for( tab=(*proc).second.begin(); tab != (*proc).second.end(); tab++)
        cout << (*tab).first << " => " << (*tab).second << endl;
     }

}    
