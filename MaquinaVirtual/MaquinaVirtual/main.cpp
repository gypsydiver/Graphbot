#include <stdio.h>
#include <string.h>
#include <GLUT/glut.h>
#include <stack>
#include "Cargador.h"
#include "Memoria.h"
#include "Sound.h"
using namespace std;

// Manejo de archivo de Código Intermedio
ifstream file;
string line;
char *tokens;
char *tok;

int cuadruplo;
int comando;
int opdo1;
int opdo2;
int opdo3;

stack<int> Pila_Cuadruplos;

// Manejo de cursor
int pointerx = 0;
int pointery = 0;
float direccionEnGrados = 0.0;
float res;

// Manejo de Memorias
stack<Memoria> Pila_Memorias;
Memoria memoria_actual;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
    
    // Carga las constantes
    cargando.carga_globales();
}

void graphbot(int num) {
    
    file.seekg(0, ios::beg);
    
    for(int i = 1; i < num; i++) {
        getline(file, line);
    }
    
}

void display() {
    
    // Lee Código Intermedio
    while (getline(file, line)){
        
        tok = &*line.begin();
        tokens = strtok(tok,".");
        
        // Obtiene el cuadruplo actual
        cuadruplo = atoi(tokens);
        tokens = strtok (NULL, " ");
        cout << "Cuadruplo Actual: " << cuadruplo << endl;
        
        // Obtiene el comando
        comando = atoi(tokens);
        tokens = strtok (NULL, " ");

        // Obtiene el primer operando
        if (tokens != NULL)
            opdo1 = atoi(tokens);
        else
            opdo1 = NULL;
        tokens = strtok (NULL, " ");

        // Obtiene el segundo operando
        if (tokens != NULL)
            opdo2 = atoi(tokens);
        else
            opdo2 = NULL;
        tokens = strtok (NULL, " ");

        // Obtiene el tercer operando
        if (tokens != NULL)
            opdo3 = atoi(tokens);
        else
            opdo3 = NULL;
        tokens = strtok (NULL, " ");
        
        // Prepara ventana
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(3.0);
        
        switch(comando) {
                
                 // Show
            case 5000:
                
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                
                glBegin(GL_TRIANGLES);
                glVertex2f(-5, 0);
                glVertex2f(5, 0);
                glVertex2f(0, 10);
                glEnd();
                glFlush();
                
                 break;
                
                // Hide
            case 5001:
                 break;
                
                // Clean
            case 5002:
                
                 glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
                 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                 glutSwapBuffers();
                
                 break;
                 
                 // Home
            case 5003:
                 break;
                 
                 // GetColorR
            case 5004:
                 break;
                 
                 // GetColorG
            case 5005:
                 break;
                 
                 // GetColorB
            case 5006:
                 break;
                 
                 // GetPenSize
            case 5007:
                 break;
                 
                 // Get X
            case 5008:
                 break;
                 
                 // Get Y
            case 5009:
                 break;
                 
                 // StopMusic
            case 5010:
                alSourceStop(source);
                cleanUp();
                 break;
                 
                 // PlayMusic
            case 5011:
                loadSoundSource();
                alSourcePlay(source);
                break;

                 // Move
            case 5012:
                /*
                glBegin(GL_LINES);
                
                glVertex2i(pointerx, pointery);
                pointery = pointery + memoria_actual.get(opdo1);
                glVertex2i(pointerx, pointery);
        
                glEnd();
                glFlush();*/
                break;
            
                 //Turn
            case 5013:/*
                cout << "ENTRE AL TURN" << endl;
                glRotatef (memoria_actual.get(opdo1), 0.0, 0.0, 1.0);
                //glFlush ();*/
                break;
                
                 // Set X
            case 5014:
            
                pointerx = memoria_actual.get(opdo1);
                
                break;
                
                 // Set Y
            case 5015:
                
                pointery = memoria_actual.get(opdo1);

                break;
                
                 // SetPenSize
            case 5016:
                 break;
                 
                 // CameraUp
            case 5017:
                 break;
                 
                 // CameraDown
            case 5018:
                 break;
                 
                 // CameraLeft
            case 5019:
                 break;
                 
                 // CameraRight
            case 5020:
                 break;
                 
                 // SetBackgroundText
            case 5021:
                 break;

                 // Save
            case 5022:
                
                 // Guarda variable tipo Lista
                 if(opdo1 < 1000)
                 memoria_actual.setLista(opdo2, opdo1);
                 // Guarda variable tipo Flotante
                 else
                 memoria_actual.setFlotante(opdo2, memoria_actual.get(opdo1));
                
                 cout << "Variable con dirección: " << opdo2 << " , tiene valor: " << memoria_actual.get(opdo2) << endl;
                 break;
                
                 // SetPos
            case 5023:
                 break;
                 
                 // SetColor
            case 5024:
                 break;
                 
                 // SetBackground
            case 5025:
                 break;

                // Igual ==
            case 5026:
                
                if(memoria_actual.get(opdo1) == memoria_actual.get(opdo2))
                    memoria_actual.setTemporal(opdo3, 1);
                else
                    memoria_actual.setTemporal(opdo3, 0);
                
                break;
                 
                 // Mayor que >
            case 5027:
                  
                  if(memoria_actual.get(opdo1) > memoria_actual.get(opdo2))
                  memoria_actual.setTemporal(opdo3, 1);
                  else
                  memoria_actual.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Menor que <
            case 5028:
                  
                  if(memoria_actual.get(opdo1) < memoria_actual.get(opdo2))
                  memoria_actual.setTemporal(opdo3, 1);
                  else
                  memoria_actual.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Diferente de !=
            case 5029:
                  
                  if(memoria_actual.get(opdo1) != memoria_actual.get(opdo2))
                    memoria_actual.setTemporal(opdo3, 1);
                  else
                    memoria_actual.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Mayor o igual que >=
            case 5030:
                  
                  if(memoria_actual.get(opdo1) >= memoria_actual.get(opdo2))
                  memoria_actual.setTemporal(opdo3, 1);
                  else
                  memoria_actual.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Menor o igual que <=
            case 5031:
                  
                  if(memoria_actual.get(opdo1) <= memoria_actual.get(opdo2))
                  memoria_actual.setTemporal(opdo3, 1);
                  else
                  memoria_actual.setTemporal(opdo3, 0);
                  
                 break;
                
                // Suma
            case 5032:
                
                res = memoria_actual.get(opdo1) + memoria_actual.get(opdo2);
                memoria_actual.setTemporal(opdo3, res);
                
                break;
                
                // Resta
            case 5033:
                
                res = memoria_actual.get(opdo1) - memoria_actual.get(opdo2);
                memoria_actual.setTemporal(opdo3, res);
                
                break;
                
                // Multiplicación
            case 5034:
                
                res = memoria_actual.get(opdo1) * memoria_actual.get(opdo2);
                memoria_actual.setTemporal(opdo3, res);
                
                break;
                
                // División
            case 5035:
                
                res = memoria_actual.get(opdo1) / memoria_actual.get(opdo2);
                memoria_actual.setTemporal(opdo3, res);
                
                break;
                
                
                 // Goto 
                 case 5036:
                
                file.clear();
                graphbot(opdo1);
                
                 break;
            
                // GotoF
            case 5037:
                
                if(!memoria_actual.get(opdo1)) {
                    file.clear();
                    graphbot(opdo2); }
                 break;
                
                 // Param
            case 5038:
                
                memoria_actual.setFlotante(opdo1, opdo2);
                
                 break;
                 
                 // Era
            case 5039:
                
                Memoria memoria;
                memoria.nueva(opdo3, opdo1, opdo2);
                Pila_Memorias.push(memoria);
                memoria_actual = Pila_Memorias.top();
                
                 break;
                 
                 // Retorno Funcion
            case 5040:
                
                memoria_actual = Pila_Memorias.top();
                Pila_Memorias.pop();
                memoria_actual.destruye();
                memoria_actual = Pila_Memorias.top();
                
                // Regresa al cuadruplo donde estaba antes
                file.clear();
                graphbot(Pila_Cuadruplos.top());
                Pila_Cuadruplos.pop();
                
                break;
                
                // Retorno Lista
            case 5041:
                
                // Regresa al cuadruplo donde estaba antes
                file.clear();
                graphbot(Pila_Cuadruplos.top());
                Pila_Cuadruplos.pop();
                
                break;
                
                // Gosub
            case 5042:
                
                Pila_Cuadruplos.push(cuadruplo+1);
                file.clear();
                graphbot(opdo1);
                
                break;

        }
        
    }
    
}

int main(int argc,char** argv) {

    file.open("CodigoInt.txt");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Graphbot");
   // glutSwapBuffer();
    init();
    graphbot(1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
    
}
