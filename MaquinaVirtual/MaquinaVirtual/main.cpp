#include <stdio.h>
#include <string.h>
#include <GLUT/glut.h>
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

// Manejo de cursor
int pointerx = 0;
int pointery = 0;
int dir = 1;
float res;

Memoria memoria;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
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
        cout << cuadruplo << endl;
        
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
                
                glBegin(GL_LINES);
                
                glVertex2i(pointerx, pointery);
                pointery = pointery + memoria.get(opdo1);
                glVertex2i(pointerx, pointery);
        
                glEnd();
                glFlush();
                break;
            
                 //Turn
            case 5013:
                cout << "ENTRE AL TURN" << endl;
                glRotatef (memoria.get(opdo1), 0.0, 0.0, 1.0);
                //glFlush ();
                break;
                
                 // Set X
            case 5014:
            
                pointerx = memoria.get(opdo1);
                
                break;
                
                 // Set Y
            case 5015:
                
                pointery = memoria.get(opdo1);

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
                 memoria.setLista(opdo2, opdo1);
                 // Guarda variable tipo Flotante
                 else
                 memoria.setFlotante(opdo2, memoria.get(opdo1));
                
                 cout << "Variable con dirección: " << opdo2 << " , tiene valor: " << memoria.get(opdo2) << endl;
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

                  // Igual =
                 case 5026:
                 break;
                 
                 // Mayor que >
            case 5027:
                  
                  if(memoria.get(opdo1) > memoria.get(opdo2))
                  memoria.setTemporal(opdo3, 1);
                  else
                  memoria.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Menor que <
            case 5028:
                  
                  if(memoria.get(opdo1) < memoria.get(opdo2))
                  memoria.setTemporal(opdo3, 1);
                  else
                  memoria.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Diferente de !=
            case 5029:
                  
                  if(memoria.get(opdo1) != memoria.get(opdo2))
                    memoria.setTemporal(opdo3, 1);
                  else
                    memoria.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Mayor o igual que >=
            case 5030:
                  
                  if(memoria.get(opdo1) >= memoria.get(opdo2))
                  memoria.setTemporal(opdo3, 1);
                  else
                  memoria.setTemporal(opdo3, 0);
                  
                 break;
                 
                 // Menor o igual que <=
            case 5031:
                  
                  if(memoria.get(opdo1) <= memoria.get(opdo2))
                  memoria.setTemporal(opdo3, 1);
                  else
                  memoria.setTemporal(opdo3, 0);
                  
                 break;
                
                // Suma
            case 5032:
                
                res = memoria.get(opdo1) + memoria.get(opdo2);
                cout << memoria.get(opdo1) << " + " << memoria.get(opdo2) << endl;
                
                memoria.setTemporal(opdo3, res);
                cout << memoria.get(opdo3) << " TEMPORAL" << endl;
                
                break;
                
                // Resta
            case 5033:
                
                res = memoria.get(opdo1) - memoria.get(opdo2);
                cout << memoria.get(opdo1) << " - " << memoria.get(opdo2) << endl;

                memoria.setTemporal(opdo3, res);
                cout << memoria.get(opdo3) << " TEMPORAL" << endl;
                
                break;
                
                // Multiplicación
            case 5034:
                
                res = memoria.get(opdo1) * memoria.get(opdo2);
                cout << memoria.get(opdo1) << " * " << memoria.get(opdo2) << endl;

                
                memoria.setTemporal(opdo3, res);
                cout << memoria.get(opdo3) << " TEMPORAL" << endl;
                
                break;
                
                // División
            case 5035:
                
                res = memoria.get(opdo1) / memoria.get(opdo2);
                cout << memoria.get(opdo1) << " / " << memoria.get(opdo2) << endl;
                
                memoria.setTemporal(opdo3, res);
                cout << memoria.get(opdo3) << " TEMPORAL" << endl;
                
                break;
                
                
                 // Goto 
                 case 5036:
                
                file.clear();
                graphbot(opdo1);
                
                 break;
            
                // GotoF
            case 5037:
                
                if(opdo1 == 0) {
                    file.clear();
                    graphbot(memoria.get(opdo2)); }
                 break;
                
                 // Param
            case 5038:
                 break;
                 
                 // Era
            case 5039:
                 break;
                 
                 // Retorno
            case 5040:
                 break;

                // Main
            case 5042:
            {
                // Crea una nueva memoria para el main 
                memoria.nueva(opdo3, opdo1, opdo2);
                
                // Carga las constantes
                cargando.carga_globales();
                
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                
                // Triángulo inicial
                glBegin(GL_TRIANGLES);
                glVertex2f(-5, 0);
                glVertex2f(5, 0);
                glVertex2f(0, 10);
                glEnd();
                glFlush();
                
            }
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
