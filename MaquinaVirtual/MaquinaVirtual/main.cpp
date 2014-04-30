#include <stdio.h>
#include <cmath>
#include <string.h>
#include <GLUT/glut.h>
#include <assert.h>
#include <stack>
#include "SOIL.h"
#include "Cargador.h"
#include "Memoria.h"
#include "Sound.h"
#include "Cuadruplos.h"

int render(int cuadruplo, int comando, int opdo1, int opdo2,int opdo3);

using namespace std;

const float PI = 3.141592653589793238462643383279502884197169399375105820974944;

// Manejo de archivo de Código Intermedio
ifstream file;
string line;

bool showBotOrNot = true;
bool penDown = true;

Cuadruplos cuad;

stack<int> Pila_Cuadruplos;

// Manejo de OPENGL
float pointerx = 0;
float pointery = 0;
float direccionEnGrados = 90.0;
float res;

float coor1 = 0;
float coor2 = 0;
float coor3 = 0;
float coor4 = 0;

float fondoR =1.0, fondoG =1.0, fondoB = 1.0;

float colorR = 0.0;
float colorG = 0.0;
float colorB = 0.0;

float lineSize = 3.0;

int screenWidth = 200;
int screenHeight = 200;

// Manejo de Memorias
stack<Memoria> Pila_Memorias;
Memoria memoria_actual;

// Guarda texturas
static GLuint texturas[5];


void init()
{
    glLoadIdentity();
    glClearColor(fondoR,fondoG,fondoB,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-screenWidth,screenWidth,-screenHeight,screenHeight);
    
    // Carga las constantes
    cargando.carga_globales();
    
    // Carga texturas
    
    texturas[0] = SOIL_load_OGL_texture
    (
     "Textura1.bmp",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
    texturas[1] = SOIL_load_OGL_texture
    (
     "Textura2.bmp",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
    texturas[2] = SOIL_load_OGL_texture
    (
     "Textura3.bmp",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
    texturas[3] = SOIL_load_OGL_texture
    (
     "Textura4.bmp",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
    texturas[4] = SOIL_load_OGL_texture
    (
     "graphbot.png",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
}

void graphbot(int num) {
    file.seekg(0, ios::beg);
    for(int i = 1; i < num; i++) {
        getline(file, line);
    }
    
}

float degreestoRadians(float degrees){
    return PI * degrees/180;
}

void newPosition(float length){
    pointerx = pointerx+length * cos(degreestoRadians(direccionEnGrados));
    pointery = pointery+length * sin(degreestoRadians(direccionEnGrados));
}

int updateAngle(int newToBeAngle){
    return newToBeAngle % 360;
}

void show(){
    if (showBotOrNot) {
        // Texturas
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        // Actualiza la coordenadas
        coor1 = -15; //+ pointerx;
        coor2 = 15; // + pointerx;
        coor3 = -15; // + pointery;
        coor4 = 15; // + pointery;
        
        glPushMatrix();
        
        glTranslatef(pointerx, pointery, 0.0);
        glRotatef(direccionEnGrados-90, 0.0, 0.0, 1.0);
        glTranslatef(0.0,0.0, 0.0);


        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glColor3f(1.0f,1.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D, texturas[4]);
        
        glBegin(GL_QUADS);
        
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(coor1, coor3, 0.0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(coor2, coor3, 0.0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(coor2, coor4, 0.0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(coor1, coor4, 0.0);
        
        glEnd();
        
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void display() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i=1; i<= cuad.cuantos_cuadruplos; i++){
        cuadruplo cuadruploActual = cuad.get(i);
        cout << "i = "<< i<<endl;
        cout << "numero de cuadruplo "<< cuadruploActual.cuadruplo<<endl;
        i = render(cuadruploActual.cuadruplo, cuadruploActual.comando,cuadruploActual.opdo1, cuadruploActual.opdo2,cuadruploActual.opdo3);
        cout << "i despues = "<< i<<endl;
    }
    //cout<< "SALI DEL FOR"<<endl;
    glFlush();
    
}

void readFromFile(string filename){
    int cuadruplo,comando,opdo1,opdo2,opdo3;
    char *tokens, *tok;
    file.open(filename);
    getline(file, line);
    cuad.begin(stoi(line));
    
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
        if (tokens != NULL){
            opdo1 = atoi(tokens);
            //cout << "ATOI tokens opdo1 " << opdo1 << " en memoria: "<< memoria_actual.get(opdo1)<<endl;
        }else
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
        
        cuad.set(cuadruplo, comando, opdo1, opdo2, opdo3);
    }
    cuad.listAll();
}

void teclado(unsigned char cual, int x, int y){
    switch(cual){
        case 'c':
            cuad.reset();
            exit(1);
            break;
    }
}

void reshape(int ancho, int alto){
    screenWidth = ancho;
    screenHeight = alto;
    glViewport(-screenWidth,-screenHeight, screenWidth*2,screenHeight*2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-screenWidth,screenWidth,-screenHeight,screenHeight);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    glutPostRedisplay();
}

int main(int argc,char** argv) {
    readFromFile("CodigoInt.txt");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Graphbot");
    init();
    graphbot(1);
    glutKeyboardFunc(teclado);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

int render(int cuadruplo, int comando, int opdo1, int opdo2,int opdo3){
    int retorno = 3;
    switch(comando) {
            // Show
        case 5000:
            showBotOrNot = true;
            break;
            
            // Hide
        case 5001:
            showBotOrNot = false;
            break;
            
            // Clean
        case 5002:
            glClearColor(fondoR, fondoG, fondoB, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glutSwapBuffers();
            break;
            
            // Home
        case 5003:
            pointerx = pointery = 0;
            break;
            
            // GetColorR
        case 5004:
            memoria_actual.setTemporal(opdo1, colorR);
            break;
            
            // GetColorG
        case 5005:
            memoria_actual.setTemporal(opdo1, colorG);
            break;
            
            // GetColorB
        case 5006:
            memoria_actual.setTemporal(opdo1, colorB);
            break;
            
            // GetPenSize
        case 5007:
            memoria_actual.setTemporal(opdo1, lineSize);
            break;
            
            // Get X
        case 5008:
            memoria_actual.setTemporal(opdo1, pointerx);
            break;
            
            // Get Y
        case 5009:
            memoria_actual.setTemporal(opdo1, pointery);
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
            //prepping line width and color
            glColor3f(colorR, colorG, colorB);
            glLineWidth(lineSize);
            
            if(penDown) {
                glBegin(GL_LINES);
                glVertex2f(pointerx, pointery);
                newPosition(memoria_actual.get(opdo1));
                glVertex2f(pointerx, pointery);
                glEnd();
            }else{
                newPosition(memoria_actual.get(opdo1));
            }
    
            cout << "Posx: " << pointerx << " PosY: "<<pointery << endl;
            break;
            
            // About
        case 5013:
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
            lineSize = memoria_actual.get(opdo1);
            break;
            
            // penUp
        case 5017:
            penDown = false;
            break;
            
            // penDown
        case 5018:
            penDown = true;
            break;
            
            // RightTurn
        case 5019:
            direccionEnGrados = updateAngle(direccionEnGrados - memoria_actual.get(opdo1)) * 1.0;
            break;
            
            // LeftTurn
        case 5020:
            direccionEnGrados = updateAngle(direccionEnGrados + memoria_actual.get(opdo1)) * 1.0;
            break;
            
            // SetBackgroundText
        case 5021:
        {
            //Texturas
            glEnable(GL_TEXTURE_2D);
            
            int num = (int) memoria_actual.get(opdo1) - 1;
            
            glPushMatrix();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glColor3f(1.0f,1.0f,1.0f);
            glBindTexture(GL_TEXTURE_2D, texturas[num]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-screenWidth, -screenHeight, 0.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(screenWidth, -screenHeight, 0.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(screenWidth, screenHeight, 0.0);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-screenWidth, screenHeight, 0.0);
            glEnd();
            glDisable(GL_TEXTURE_2D);
            glPopMatrix();
        }
            break;
            
            // Save
        case 5022:
            // Guarda variable tipo Lista
            if(opdo1 < 1000){
                memoria_actual.setLista(opdo2, opdo1);
            // Guarda variable tipo Flotante
            }else{
                memoria_actual.setFlotante(opdo2, memoria_actual.get(opdo1));
            }
            //cout << "Variable con dirección: " << opdo2 << " , tiene valor: " << memoria_actual.get(opdo2) << endl;
            printf("Variable con dirección: %d,tiene valor: %f\n",opdo2,memoria_actual.get(opdo2));
            break;
            
            // SetPos
        case 5023:
            pointerx = memoria_actual.get(opdo1);
            pointery = memoria_actual.get(opdo2);
            break;
            
            // SetColor
        case 5024:
            colorR = memoria_actual.get(opdo1);
            colorG = memoria_actual.get(opdo2);
            colorB = memoria_actual.get(opdo3);
            glColor3f(colorR, colorG, colorB);
            break;
            
            // SetBackground
        case 5025:
            fondoR = memoria_actual.get(opdo1);
            fondoG = memoria_actual.get(opdo2);
            fondoB = memoria_actual.get(opdo3);
            break;
            
            // Igual ==
        case 5026:
            if(memoria_actual.get(opdo1) == memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
            break;
            
            // Mayor que >
        case 5027:
             cout << "ESTOY COMPARANDO >"<<endl;
            cout << "opdo1 - " <<opdo1<< " : "<< memoria_actual.get(opdo1) << endl;
            cout << "opdo2 - " <<opdo2<< " : "<< memoria_actual.get(opdo2) << endl;
            if(memoria_actual.get(opdo1) > memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
            break;
            
            // Menor que <
        case 5028:
            cout << "ESTOY COMPARANDO <"<<endl;
            cout << "opdo1 - " <<opdo1<< " : "<< memoria_actual.get(opdo1) << endl;
            cout << "opdo2 - " <<opdo2<< " : "<< memoria_actual.get(opdo2) << endl;
            if(memoria_actual.get(opdo1) < memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
            break;
            
            // Diferente de !=
        case 5029:
            if(memoria_actual.get(opdo1) != memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
            break;
            
            // Mayor o igual que >=
        case 5030:
            if(memoria_actual.get(opdo1) >= memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
            break;
            
            // Menor o igual que <=
        case 5031:
            if(memoria_actual.get(opdo1) <= memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
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
            //parche para el for, pues al terminar suma uno y se brinca un cuádruplo
            return opdo1-1;
            break;
            
            // GotoF
        case 5037:
            cout << "opdo1: " << memoria_actual.get(opdo1) << endl;
            if(memoria_actual.get(opdo1) == 0) {
                //parche para el for, pues al terminar suma uno y se brinca un cuádruplo
                return opdo2-1;
            }
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
            retorno = Pila_Cuadruplos.top();
            Pila_Cuadruplos.pop();
            return retorno;
            break;
            
            // Retorno Lista
        case 5041:
            // Regresa al cuadruplo donde estaba antes
            retorno = Pila_Cuadruplos.top();
            Pila_Cuadruplos.pop();
            return retorno;
            break;
            
            // Gosub
        case 5042:
            Pila_Cuadruplos.push(cuadruplo+1);
            //parche para el for, pues al terminar suma uno y se brinca un cuádruplo
            return opdo1-1;
            break;
    }
    return cuadruplo;
}

