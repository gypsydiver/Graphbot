//
//  globals.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/3/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

#ifndef Graphbot_globals_h
#define Graphbot_globals_h

#include <stack>
#include "Cuadruplos.h"
#include "Memoria.h"
#include "ResourcesPath.h"

using namespace std;
const float PI = 3.141592653589793238462643383279502884197169399375105820974944;

//string for executing the parser
const char * savedFile = "keepsafe";
const char * srcFile = "src";
const char * rainbowEx = "rainbow.txt";
const char * castleEx = "castle.txt";
const char * fiboEx = "fibonacci.txt";
const char * heartEx = "heart.txt";
const char * executeCommand = "./graphbot src";
const char * codigoInt = "CodigoInt.txt";

// Manejo de archivo de Código Intermedio
ifstream file;
string line;

bool showBotOrNot = true;
bool penDown = true;

Cuadruplos cuad;

stack<int> Pila_Cuadruplos;

// Manejo de OPENGL
float pointerx = 0.0;
float pointery = 0.0;
float direccionEnGrados = 90.0;
float res;

float coor = 10.0;

float fondoR =1.0, fondoG =1.0, fondoB = 1.0;

float colorR = 0.0;
float colorG = 0.0;
float colorB = 0.0;

float lineSize = 3.0;

int screenWidth = 880;
int screenHeight = 570;
int orthoWidth = screenWidth/3;
int orthoHeight = screenHeight/3;

// Manejo de fondo
bool background = false;
bool textura = false;
int num_txt = -1;

// Manejo de Memorias
stack<Memoria> Pila_Memorias;
Memoria memoria_actual;

// Guarda texturas
static GLuint texturas[5];

static bool loadedTextures = false;
bool compilo = false;
string compilacionEx  = "Compilación Exitosa \n";

#endif
