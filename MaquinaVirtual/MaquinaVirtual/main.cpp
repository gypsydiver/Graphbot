#include <stdio.h>
#include <string.h>
#include <GLUT/glut.h>
#include "Cargador.h"
#include "Memoria.h"
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

void display() {
    
    file.open("/Users/claudiahdz/Graphbot/MaquinaVirtual/MaquinaVirtual/CodigoInt.txt");
    
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
        cout << comando << endl;
        // Obtiene el primer operando
        if (tokens != NULL)
        opdo1 = atoi(tokens);
            tokens = strtok (NULL, " ");
        cout << opdo1 << endl;
        // Obtiene el segundo operando
        if (tokens != NULL)
        opdo2 = atoi(tokens);
            tokens = strtok (NULL, " ");
        cout << opdo2 << endl;
        // Obtiene el tercer operando
        if (tokens != NULL)
            opdo3 = atoi(tokens);
        tokens = strtok (NULL, " ");
        cout << opdo3 << endl;
        
        // Prepara ventana
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(3.0);
        
        switch(comando) {
                /*
                 case 5000:
                 break;
                 
                 case 5001:
                 break;
                 
                 case 5002:
                 break;
                 
                 case 5003:
                 break;
                 
                 case 5004:
                 break;
                 
                 case 5005:
                 break;
                 
                 case 5006:
                 break;
                 
                 case 5007:
                 break;
                 
                 case 5008:
                 break;
                 
                 case 5009:
                 break;
                 
                 case 5010:
                 break;
                 
                 case 5011:
                 break;
*/
                 // Move
                case 5012:
                
                glBegin(GL_LINES);
                
                glVertex2i(pointerx, pointery);
                pointery = pointery + memoria.get(opdo1);
                glVertex2i(pointerx, pointery);
        
                glEnd();
                glFlush();
                break;
                
                
                 /* Turn
                 case 5013:
                cout << "ENTRE AL TURN" << endl;
                glRotatef (memoria.get(opdo1), 0.0, 0.0, 1.0);
                //glFlush ();
                break;*/
                
                 // Set X
                case 5014:
            
                pointerx = memoria.get(opdo1);
                
                break;
                
                 // Set Y
                case 5015:
                
                pointery = memoria.get(opdo1);

                break;
                /*
                 case 5016:
                 break;
                 
                 case 5017:
                 break;
                 
                 case 5018:
                 break;
                 
                 case 5019:
                 break;
                 
                 case 5020:
                 break;
                 
                 case 5021:
                 break;
                 
                 case 5022:
                 break;
                 
                 case 5023:
                 break;
                 
                 case 5024:
                 break;
                 
                 case 5025:
                 break;
                 
                 case 5026:
                 break;
                 
                 case 5027:
                 break;
                 
                 case 5028:
                 break;
                 
                 case 5029:
                 break;
                 
                 case 5030:
                 break;
                 
                 case 5031:
                 break; */
                
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
                
                /*   
                 // Goto 
                 case 5036:
                 
                 
                 break;
                 
                 case 5037:
                 break;
                 
                 case 5038:
                 break;
                 
                 case 5039:
                 break;
                 
                 // Era
                 case 5040:
                 break;
                 
                 case 5042:
                 break;
                 */
                // Main
            case 5043:
            {
                // Crea una nueva memoria para el main 
                memoria.nueva(opdo3, opdo1, opdo2);
                
                // Carga las constantes
                cargando.carga_globales();
            }
                break;
                
        }
        
    }
    
}

int main(int argc,char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Graphbot");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
    
}
