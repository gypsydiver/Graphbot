%{
//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Parser verificador de gramática correcta de graphbot

#include <cstdio>
#include <iostream>
#include <string>
#include "Generador.h"
#include "tablaVar.h"
#include "dirProc.h" 
using namespace std;

// Directorio de Procedimientos
dirProcs directorio;
procs pcd;

// Tabla de variables
tablaVariables tv;
data tvar;

// Generador de código intermedio
Generador generador;

// Contador global de parámetros y variables
int param = 0;
int vars = 0;

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
%token <sval> RW_SAVE RW_SETPOS
//comandos de tres parámetros
%token <sval> RW_SETCOLOR RW_SETBACKGROUND
//palabras reservadas
%token <sval> RW_FUNCTION RW_END RW_TRUE RW_FALSE RW_BOOLEAN RW_PROGRAM RW_FOR RW_WHILE RW_IF RW_FLOAT
//caractéres del lenguaje
%token <cval> OP_BRACKET CL_BRACKET OP_PAR CL_PAR COMMA
//comparadores
%token <sval> EQUAL GREAT_THAN LESS_THAN
%token <sval> NOT_EQUAL GREAT_EQ_THAN LESS_EQ_THAN
//operandos y operadores
%token <sval> BASIC_ARITHMETIC COM_ARITHMETIC ID FLOAT

%type <sval> varCte comandos comando comando_return comando1 comando3 expresion variable comparador llamada_funcion;
%start graphbot
%%

//Grammar rules
graphbot: 
	graph programa {
        // Imprime el directorio de procedimientos con sus respectivas tablas de variables
        directorio.output_proc();
		cout<<"Compilación Exitosa"<<endl;
        generador.start(10);
	}
	;


graph: /*empty*/ 
	| funcion graph 
 	;

funcion:
	funcion_rw funciones RW_END {
        
        pcd.tv = tv;
        pcd.numParam = param;
        pcd.varLocal = vars;
        directorio.add_proc(pcd);
        // Deja limpia la variable tablaVariables para el siguiente caso
        tv.remove_all();
        param = 0;
        vars = 0; 
        
        // Genera retorno
        generador.start(13);
}
    ;

funcion_rw:
   	RW_FUNCTION ID parametros {
        string id = $2;
        // Busca si la función no esta ya dentro del directorio de procedimientos
        if(!directorio.find_proc(id)) {
        // Agrega función al directorio con su respectiva tabla de variables
        pcd.nombre = $2;
        pcd.dirI = cont_cuadruplos;
        }
        else
            errores(1, $2);
    }
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

parametros: 
	 ID var {
		// Agrega variable a la tabla
        tvar.nombre = $1;
        tvar.tipo = 0;
        tvar.dirV = 0;
        tvar.dirI = 0;        
        tv.add_var(tvar);
        param++;
    }  
	;

var: /* empty */ 
	| COMMA parametros
	;

programa:
        programa_rw funciones RW_END {

        pcd.tv = tv;
        pcd.numParam = param;
        pcd.varLocal = vars;
        directorio.add_proc(pcd);
        // Deja limpia la variable tablaVariables para el siguiente caso
        tv.remove_all();
        vars = 0;
}
    ;

programa_rw:
	RW_PROGRAM ID {
        string id = $2;
		// Agrega procedimiento main al directorio 
        if(!directorio.find_proc(id)) {
        // Agrega función al directorio con su respectiva tabla de variables
        pcd.nombre = $2;
        pcd.dirI = cont_cuadruplos;
        generador.rellena(1, cont_cuadruplos);        
	}
}
	;

comandos: 
	comando {
		cout<<"Matched <COMANDO>: "<<$1<<endl;
		//comandos que regresan nada
	     generador.pushPOper($1);
         generador.start(6);
	}
	| comando_return{
		cout<<"Matched <COMANDO_RETURN>: "<<$1<<endl;
		//comandos que regresan algún valor
	     generador.pushPOper($1);
         generador.start(7);

	}
    | comando1 expresion{
    	cout<<"Matched <COMANDO1>: "<<$1<<endl;
	    generador.pushPOper($1);
        generador.start(3);
    }
    | RW_SAVE ID variable {	

        cout<<"Matched <SAVE> a ID: "<<$2<<endl;
        string id = $2;
        // Si la misma variable se vuelve a asignar, se borra la anterior y se mete la nueva
        if(tv.find_var(id)) {
        int var = tv.getid_var(id);
        tv.remove_var(var); }
		// Agrega una variable a la tabla de variables        
        tvar.nombre = $2;
        tvar.dirV = 0;
        tv.add_var(tvar);
        vars++;

        if(tvar.tipo == 0) {
	    generador.pushPOper($1);
		generador.pushPilaO($2);
        generador.start(4); }
        else
        generador.rellena_save(generador.popPSaltos(), $2);
        

	}
	| RW_SETPOS expresion expresion {
		cout<<"Matched <COMANDO2>:"<<$1<<endl;
	    generador.pushPOper($1);
        generador.start(4);    
	}
	| comando3 expresion expresion expresion {
		cout<<"Matched <COMANDO3>: "<<$1<<endl;
	    generador.pushPOper($1);
        generador.start(5); 
	}
	| llamada_funcion {
        
         generador.param(param);
         param = 0;  
         string id = $1;
         int dir = directorio.get_dirI(id); 
         generador.gosub(id, dir); 
	
	}
	;

llamada_funcion_aux: /* empty */
	| expresion llamada_funcion_aux {
      param++;  
}
	;

llamada_funcion:
	ID OP_PAR llamada_funcion_aux CL_PAR {
        string id = $1;
		// Busca si la función no esta ya dentro del directorio de procedimientos
        if(!directorio.find_proc(id)) 
	    errores(3, $1); 
        else if (directorio.num_Param(id) != param)
        errores(4, $1);

        generador.era(directorio.get_tam(id));        
        $$ = $1;

    }
	;

comando: 
	RW_SHOW {$$ = $1;}
	| RW_HIDE {$$ = $1;}
	| RW_CLEAN {$$ = $1;}
	| RW_HOME {$$ = $1;}
	| RW_PLAYMUSIC {$$ = $1;}
	| RW_STOPMUSIC {$$ = $1;}
	;

comando_return:
	RW_GETCOLORR {$$ = $1;}
	| RW_GETCOLORB {$$ = $1;}
	| RW_GETCOLORG {$$ = $1;}
	| RW_GETPENSIZE {$$ = $1;}
	| RW_GETX {$$ = $1;}
	| RW_GETY {$$ = $1;}
	;

comando1: 
	RW_MOVE {$$ = $1;}
	| RW_TURN {$$ = $1;}
	| RW_SETX {$$ = $1;}
	| RW_SETY {$$ = $1;}
	| RW_SETPENSIZE {$$ = $1;}
	| RW_SETBACKGROUNDTXT {$$ = $1;}
	| RW_CAMERAUP {$$ = $1;}
	| RW_CAMERADOWN {$$ = $1;}
	| RW_CAMERALEFT {$$ = $1;}
	| RW_CAMERARIGHT {$$ = $1;}
	;

comando3: 
	RW_SETCOLOR {$$ = $1;}
	| RW_SETBACKGROUND {$$ = $1;}
	;

variable:
	expresion {
	 	cout<<"Matched SAVE_EXPRESION"<<endl;
        // Variable del tipo FLOAT representado por un 0
        tvar.tipo = 0;
        tvar.dirI = 0;
        
	}
    |	lista_OPBRACKET funciones lista_aux CL_BRACKET {
		cout<<"Matched SAVE_LISTA"<<endl;
        // Variable del tipo LISTA representado por un 1
        tvar.tipo = 1;
        // Retorno
        generador.start(13);
        // Rellena goto anterior con con_cuadruplos actual
        generador.rellena(generador.popPSaltos(), cont_cuadruplos);
	}
	;

lista_OPBRACKET:
    OP_BRACKET {

        // Genera cuádruplo de save para lista
	    generador.pushPOper("save");
        generador.pushPilaO(to_string(cont_cuadruplos+2));
		generador.pushPilaO("&");
        generador.pushPSaltos(cont_cuadruplos);
        generador.start(4);

        // Goto al final
        generador.pushPSaltos(cont_cuadruplos);
        generador.start(14);   
 
        tvar.dirI = cont_cuadruplos;    
    }
    ;

for: 
	for_rw for_aux lista {
		// Generar aumento a la variable de control
		generador.start(12);

		int falso = generador.popPSaltos();
		// Genera retorno (Goto)
		generador.start(10);

		// Rellena
		generador.rellena(falso,cont_cuadruplos);
	}
	;

for_rw:
	RW_FOR {
		// 1.- Meter cont_cuadruplos a PSaltos
		generador.pushPSaltos(cont_cuadruplos);
	}
	;

for_aux:
	for_id COMMA expresion COMMA expresion CL_BRACKET {
		// Generar el cuádruplo de comparación entre la variable de control y el valor límite
		string aumento = generador.popPilaO();
		string limite = generador.popPilaO();
		string id = generador.popPilaO();

		generador.pushPilaO(limite);
		generador.pushPOper("<");
		generador.start(8);

		generador.pushPilaO(id);
		generador.pushPilaO(aumento);
		
		// Generar GotoF
		generador.start(11);
	}
	;

for_id:
	OP_BRACKET ID{
        // Busca si la variable no esta declarada
        string id = $2;
        if(!tv.find_var(id))
		errores(2, $2);

		generador.pushPilaO($2);
		generador.pushPilaO($2);
	}
	;

while: 
	while_aux lista {
		int falso = generador.popPSaltos();
		// Genera retorno (Goto)
		generador.start(10);

		// Rellena
		generador.rellena(falso, cont_cuadruplos);
	}
	;

while_aux:
	while_rw expresion{
		// Genera GotoF
		generador.start(9);
	}
	;

while_rw:
	RW_WHILE{
		// 1.- Meter cont_cuadruplos a PSaltos
		generador.pushPSaltos(cont_cuadruplos);
	}
	;

condicion: 
	condicion_aux lista{
		// Rellena
		int fin = generador.popPSaltos();
		generador.rellena(fin, cont_cuadruplos);
	}
	;

condicion_aux:
	RW_IF expresion {
		// Genera GotoF
		generador.start(9);
	}
	;

lista:
	OP_BRACKET funciones lista_aux CL_BRACKET {
		cout<<"Matched LISTA"<<endl;
	}
	;

lista_aux: /* empty */ 
	| COMMA funciones lista_aux
	;

expresion: 
	exp exp_aux	{
		cout<<"Matched EXPRESION"<<endl;
	}
	;

exp_aux: /* empty */
    | comparador exp { generador.pushPOper($1);
                       generador.start(8); }
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
    }

    | varCte {
		cout<<"1.- Meter "<<$1<<" a PilaO"<<endl;
		// 1.- Meter $1 a PilaO
		generador.pushPilaO($1);
	}
    ;

varCte:
	ID {
        string id = $1;
        // Busca si la variable no esta declarada
        if(!tv.find_var(id))
		errores(2, $1);
        else if (tv.find_type(id) != 0)
        errores(5, $1);
		$$ = $1;
	}
	| FLOAT	{$$ = $1;}
	| RW_TRUE {$$ = $1;}
	| RW_FALSE {$$ = $1;}
	;

comparador: 
	EQUAL {$$ = $1;}
	| NOT_EQUAL {$$ = $1;}
	| GREAT_EQ_THAN {$$ = $1;}
	| LESS_EQ_THAN {$$ = $1;}
	| GREAT_THAN {$$ = $1;}
	| LESS_THAN {$$ = $1;}
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

        case 4:
			cout << "Cantidad de parámetros errónea en función " << val << " esperaba " << directorio.num_Param(val) << " recibí " << param << "." << endl;
			exit(-1);
			break;

        case 5:
			cout << "Variable " << val << " es de tipo lista y no puede ser utilizada en una expresión. " << endl;
			exit(-1);
			break;
	} 
}
