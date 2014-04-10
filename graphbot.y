%{
//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Parser verificador de gramática correcta de graphbot

//#include <cstdio>
//#include <iostream>
#include <string>
#include "Globalizador.h"
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

// Maneja la asignación de memoria de constantes numericas y saltos
Globalizador globalizador;

// Generador de código intermedio
Generador generador;

// Contador global de parámetros y variables
int param = 0;
int varsFlotante = 0;
int varsLista = 0;

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
    int ival;
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
%token <sval> RW_FUNCTION RW_END RW_PROGRAM RW_FOR RW_WHILE RW_IF
//caractéres del lenguaje
%token <cval> OP_BRACKET CL_BRACKET OP_PAR CL_PAR COMMA
//comparadores
%token <sval> EQUAL GREAT_THAN LESS_THAN
%token <sval> NOT_EQUAL GREAT_EQ_THAN LESS_EQ_THAN
//operandos y operadores
%token <sval> ADD SUB TIMES DIV ID FLOAT

%type <sval> llamada_funcion;
//tengo hueva
%token <sval> RW_MAIN
%type <ival> comparador comandos comando comando_return comando1 comando3 varCte expresion variable
%start graphbot
%%

//Grammar rules
graphbot: 
	graph programa {
        // Imprime el directorio de procedimientos con sus respectivas tablas de variables
        directorio.output_proc();
        globalizador.toFile();
		cout<<"Compilación Exitosa"<<endl;
	}
	;


graph: /*empty*/ 
	| funcion graph 
 	;

funcion:
	funcion_rw funciones funcion_aux RW_END {
        pcd.tv = tv;
        pcd.numParam = param;
        pcd.varFlotante = varsFlotante;
        pcd.varLista = varsLista;
        pcd.tmp = generador.tempActual()-2000;  
        directorio.add_proc(pcd);
        // Deja limpia la variable tablaVariables para el siguiente caso
        tv.remove_all();
        param = 0;
        varsLista = 0;
        varsFlotante = 0;
        
        // Genera retorno
        generador.start(13);

        generador.reinicializa_temp();
        generador.reinicializa_variable();
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
	 for  
    | comandos 
	| while 
	| condicion 
	;

funcion_aux: /* empty */
	| funciones funcion_aux
	;

parametros: /* empty */
	|ID var {
		// Agrega variable a la tabla
        tvar.nombre = $1;
        tvar.tipo = 0;
        tvar.dirV = generador.variablesDeAvail(true);
        tvar.dirI = 0;        
        tv.add_var(tvar);
        param++;
    }  
	;

var: /* empty */ 
	| COMMA parametros
	;

programa:
    programa_rw funciones funcion_aux RW_END {
        pcd.tv = tv;
        pcd.numParam = param;
        pcd.varFlotante = varsFlotante;
        pcd.varLista = varsLista;
        //mala práctica
        pcd.tmp = generador.tempActual()-2000;
        //generador.generaEraMain(varsFlotante, varsLista, pcd.tmp);
        directorio.add_proc(pcd);
        // Deja limpia la variable tablaVariables para el siguiente caso
        tv.remove_all();
        varsFlotante = 0;
        varsLista = 0;
	}
    ;

programa_rw:
	RW_PROGRAM RW_MAIN {
		string id = $2;
		// Agrega procedimiento main al directorio 
        if(!directorio.find_proc(id)) {
	        // Agrega función al directorio con su respectiva tabla de variables
	        pcd.nombre = id;
	        pcd.dirI = cont_cuadruplos;
	        generador.rellena(2, pcd.dirI);
		}
	}
	;

comandos: 
	comando {
		//cout<<"Matched <COMANDO>: "<<$1<<endl;
		//comandos que regresan nada
	     generador.pushPOper($1);
         generador.start(6);
	}
	| comando_return{
		//cout<<"Matched <COMANDO_RETURN>: "<<$1<<endl;
		//comandos que regresan algún valor
	     generador.pushPOper($1);
         generador.start(7);
	}
    | comando1 expresion{
    	//cout<<"Matched <COMANDO1>: "<<$1<<endl;
	    generador.pushPOper($1);
        generador.start(3);
    }
    | RW_SAVE ID variable {	
        //cout<<"Matched <SAVE> a ID: "<<$2<<endl;
        string id = $2;
        // Si la misma variable se vuelve a asignar, se borra la anterior y se mete la nueva
        if(tv.find_var(id)) {
        int var = tv.getid_var(id);
        tv.remove_var(var); }
		// Agrega una variable a la tabla de variables        
        tvar.nombre = $2;
        if(tvar.tipo == 0) {
        	varsFlotante++;
            //genera direccion virtual para variable de tipo flotante
            tvar.dirV = generador.variablesDeAvail(true);
            //genera cuadruplo save flotante
        	generador.pushPOper(5022);
		    generador.pushPilaO(tvar.dirV);
            generador.start(4); 
        }else if(tvar.tipo == 1){
        	varsLista++;
            //genera direccion virtual para variable tipo lista
            tvar.dirV = generador.variablesDeAvail(false);
            //genera cuadruplo save lista
            generador.rellena_save(generador.popPSaltos(), tvar.dirV);
        }
        //agrega variable a tabla de variables
        tv.add_var(tvar);

	}
	| RW_SETPOS expresion expresion {
		//cout<<"Matched <COMANDO2>:"<<$1<<endl;
	    generador.pushPOper(5023);
        generador.start(4);    
	}
	| comando3 expresion expresion expresion {
		//cout<<"Matched <COMANDO3>: "<<$1<<endl;
	    generador.pushPOper($1);
        generador.start(5); 
	}
	| llamada_funcion {
         generador.param(param);
         param = 0;  
         string id = $1;
         int dir = directorio.get_dirI(id); 
         generador.gosub(dir); 
	}
	;

llamada_funcion_aux: /* empty */
	| expresion llamada_funcion_aux {
      param++;  
	}
	;

llamada_funcion:
	ID parametros_llamada_funcion {
        string id = $1;
		// Busca si la función no esta ya dentro del directorio de procedimientos
        if(!directorio.find_proc(id)) 
	    	errores(3, $1); 
        else if (directorio.num_Param(id) != param)
        	errores(4, $1);

        generador.era(directorio.num_Param(id), directorio.num_varFlotante(id), directorio.num_varLista(id),directorio.get_tmp(id));        
        $$ = $1;
    }
	;

parametros_llamada_funcion: /*empty*/
	| OP_PAR llamada_funcion_aux CL_PAR 
	;

comando: 
	RW_SHOW {$$ = 5000;}
	| RW_HIDE {$$ = 5001;}
	| RW_CLEAN {$$ = 5002;}
	| RW_HOME {$$ = 5003;}
	| RW_PLAYMUSIC {$$ = 5011;}
	| RW_STOPMUSIC {$$ = 5010;}
	;

comando_return:
	RW_GETCOLORR {$$ = 5004;}
	| RW_GETCOLORB {$$ = 5006;}
	| RW_GETCOLORG {$$ = 5005;}
	| RW_GETPENSIZE {$$ = 5007;}
	| RW_GETX {$$ = 5008;}
	| RW_GETY {$$ = 5009;}
	;

comando1: 
	RW_MOVE {$$ = 5012;}
	| RW_TURN {$$ = 5013;}
	| RW_SETX {$$ = 5014;}
	| RW_SETY {$$ = 5015;}
	| RW_SETPENSIZE {$$ = 5016;}
	| RW_SETBACKGROUNDTXT {$$ = 5021;}
	| RW_CAMERAUP {$$ = 5017;}
	| RW_CAMERADOWN {$$ = 5018;}
	| RW_CAMERALEFT {$$ = 5019;}
	| RW_CAMERARIGHT {$$ = 5020;}
	;

comando3: 
	RW_SETCOLOR {$$ = 5024;}
	| RW_SETBACKGROUND {$$ = 5025;}
	;

variable:
	expresion {
	 	//cout<<"Matched SAVE_EXPRESION"<<endl;
        // Variable del tipo FLOAT representado por un 0
        tvar.tipo = 0;
        tvar.dirI = 0;
        
	}
    | lista_OPBRACKET funciones lista_aux CL_BRACKET {
		//cout<<"Matched SAVE_LISTA"<<endl;
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
	    generador.pushPOper(5022);
        generador.pushPilaO(cont_cuadruplos+2);
		generador.pushPilaO(-1);
        generador.pushPSaltos(cont_cuadruplos);
        generador.start(4);

        // Goto al final
        generador.pushPSaltos(cont_cuadruplos);
        generador.start(14);   
 
        tvar.dirI = cont_cuadruplos;    
    }
    ;

for: 
	for_rw for_aux ciclo_estatutos {
		// Generar aumento a la variable de control
		generador.start(12);

		int falso = generador.popPSaltos();
		// Genera retorno (Goto)
		generador.start(10);

		// Rellena
		generador.rellena(falso,cont_cuadruplos);
	}
	;

ciclo_estatutos:
    lista
    | ID {
        // Verifica que variable sea de tipo lista
        string id = $1;        
        if(tv.find_type(id) == 0)
        errores(6, $1);
        
        int dir = tv.getdirI(id); 
        generador.gosub(dir);
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
		int aumento = generador.popPilaO();
		int limite = generador.popPilaO();
		int id = generador.popPilaO();

		generador.pushPilaO(limite);
		generador.pushPOper(5028);
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
        else if (tv.find_type(id) == 1)
        errores(5, $2);
        
        int direccion = tv.getdirV(id);

		generador.pushPilaO(direccion);
		generador.pushPilaO(direccion);
    }
	;

while: 
	while_aux ciclo_estatutos {
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
	condicion_aux ciclo_estatutos{
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
		//cout<<"Matched LISTA"<<endl;
	}
	;

lista_aux: /* empty */ 
	| COMMA funciones lista_aux
	;

expresion: 
	exp exp_aux	{
		//cout<<"Matched EXPRESION"<<endl;
	}
	;

exp_aux: /* empty */
    | comparador exp {
    	generador.pushPOper($1);
    	generador.start(8);
    }
    ;

exp:
	termino termino_aux	{ 	
		// 5.- Si pop(POper) == '+' o '-'
        generador.start(1);	}  
	;

termino_aux: /* empty */
    | ADD exp 	{	
		// 3.- Meter '+' a POper
	    generador.pushPOper(5032);
	}
	| SUB exp 	{	
		// 3.- Meter '-' a POper
	    generador.pushPOper(5033);
	}
	;

termino:
	factor factor_aux {	
		// 4.- Si pop(POper) == '*' o '/'
        generador.start(2); }
	;

factor_aux: /* empty */
	| TIMES termino {
		// 2.- Meter '*' a POper  
		generador.pushPOper(5034); 
	}
	| DIV termino {
		// 2.- Meter '/' a POper  
		generador.pushPOper(5035); 
	}
    ;

factor: 
    OP_PAR expresion CL_PAR {
    }
    | varCte {
		//cout<<"1.- Meter "<<$1<<" a PilaO"<<endl;
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
		
        $$ = tv.getdirV(id);
	}
	| FLOAT	{
		$$ = globalizador.asigna_globales($1);
    }
	;

comparador: 
	EQUAL {$$ = 5026;}
	| NOT_EQUAL {$$ = 5029;}
	| GREAT_EQ_THAN {$$ = 5030;}
	| LESS_EQ_THAN {$$ = 5031;}
	| GREAT_THAN {$$ = 5027;}
	| LESS_THAN {$$ = 5028;}
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

        case 6:
			cout << "Variable " << val << " no es de tipo lista." << endl;
            exit(-1);
		break;
	} 
}
