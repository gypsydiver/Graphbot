#include <stdio.h>
#include <cmath>
#include <string.h>
#include <GLUT/glut.h>
#include <assert.h>
#include <stack>
#include "Cargador.h"
#include "Memoria.h"
#include "Sound.h"
#include "imageloader.h"
using namespace std;

const float PI = 3.141592653589793238462643383279502884197169399375105820974944;
// Funciones
void loadTexture(Image* image,int k);
void freeTexture(GLuint texture);

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

bool showBotOrNot = true;
bool lighton = false;

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
static GLuint texturas[4];


void init()
{
    glLoadIdentity();
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-screenWidth,screenWidth,-screenHeight,screenHeight);
    
    // Carga las constantes
    cargando.carga_globales();
    
    // Carga luces
    float spot_cutoff = 30.0;
    float spot_exponent = 1.0;
    float light_ambient[] = {0.0, 0.2, 0.0, 1.0};
    float light_diffuse_specular[] = {0.8, 0.8, 0.8, 1.0};
    float focus_emission [] = {0.8,0.8,0.8,1.0};

    
    glEnable(GL_DEPTH_TEST);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse_specular);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_diffuse_specular);
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,spot_cutoff);
    glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,spot_exponent);
    glColor4fv(focus_emission); // Propiedad nueva


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
        glGenTextures(4, texturas);
        Image* image;
        
        image = loadBMP("graphbot.bmp"); loadTexture(image,3);
        delete image;
            
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
        glBindTexture(GL_TEXTURE_2D, texturas[3]);
        
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
                
                 glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
                
                glBegin(GL_LINES);
        
                glVertex2f(pointerx, pointery);
                newPosition(memoria_actual.get(opdo1));
                glVertex2f(pointerx, pointery);
        
                glEnd();
                
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
                 
                 // LightOn
            case 5017:
                
                glEnable(GL_LIGHTING);
                glEnable(GL_LIGHT0);
                
                 break;
                 
                 // LightOff
            case 5018:
                
                glDisable(GL_LIGHTING);
                glDisable(GL_LIGHT0);
                
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
                // Texturas
                glEnable(GL_TEXTURE_2D);
                glGenTextures(3, texturas);
                Image* image;
                
                image = loadBMP("Textura1.bmp"); loadTexture(image,0);
                image = loadBMP("Textura2.bmp"); loadTexture(image,1);
                image = loadBMP("Textura3.bmp"); loadTexture(image,2);
                delete image;
                
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
                 if(opdo1 < 1000)
                     memoria_actual.setLista(opdo2, opdo1);
                 // Guarda variable tipo Flotante
                 else
                     memoria_actual.setFlotante(opdo2, memoria_actual.get(opdo1));
                
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
                
                glClearColor(memoria_actual.get(opdo1), memoria_actual.get(opdo2),memoria_actual.get(opdo3),0.0);
                glClear(GL_COLOR_BUFFER_BIT);
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
                cout << "opdo1 - " <<opdo1<< " : "<< memoria_actual.get(opdo1) << endl;
                cout << "opdo2 - " <<opdo2<< " : "<< memoria_actual.get(opdo2) << endl;
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
                cout << "opdo1: " << memoria_actual.get(opdo1) << endl;
                if(memoria_actual.get(opdo1) == 0) {
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
    
    show();
   // light();
    glFlush();
    
}

int main(int argc,char** argv) {

    file.open("CodigoInt.txt");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Graphbot");
    init();
    graphbot(1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
    
}

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h)
{
    
}

Image::~Image()
{
    delete[] pixels;
}

namespace
{
    //Converts a four-character array to an integer, using little-endian form
    int toInt(const char* bytes)
    {
        return (int)(((unsigned char)bytes[3] << 24) |
                     ((unsigned char)bytes[2] << 16) |
                     ((unsigned char)bytes[1] << 8) |
                     (unsigned char)bytes[0]);
    }
    
    //Converts a two-character array to a short, using little-endian form
    short toShort(const char* bytes)
    {
        return (short)(((unsigned char)bytes[1] << 8) |
                       (unsigned char)bytes[0]);
    }
    
    //Reads the next four bytes as an integer, using little-endian form
    int readInt(ifstream &input)
    {
        char buffer[4];
        input.read(buffer, 4);
        return toInt(buffer);
    }
    
    //Reads the next two bytes as a short, using little-endian form
    short readShort(ifstream &input)
    {
        char buffer[2];
        input.read(buffer, 2);
        return toShort(buffer);
    }
    
    //Just like auto_ptr, but for arrays
    template<class T>
    class auto_array
    {
    private:
        T* array;
        mutable bool isReleased;
    public:
        explicit auto_array(T* array_ = NULL) :
        array(array_), isReleased(false)
        {
        }
        
        auto_array(const auto_array<T> &aarray)
        {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }
        
        ~auto_array()
        {
            if (!isReleased && array != NULL)
            {
                delete[] array;
            }
        }
        
        T* get() const
        {
            return array;
        }
        
        T &operator*() const
        {
            return *array;
        }
        
        void operator=(const auto_array<T> &aarray)
        {
            if (!isReleased && array != NULL)
            {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }
        
        T* operator->() const
        {
            return array;
        }
        
        T* release()
        {
            isReleased = true;
            return array;
        }
        
        void reset(T* array_ = NULL)
        {
            if (!isReleased && array != NULL)
            {
                delete[] array;
            }
            array = array_;
        }
        
        T* operator+(int i)
        {
            return array + i;
        }
        
        T &operator[](int i)
        {
            return array[i];
        }
    };
}

Image* loadBMP(const char* filename)
{
    ifstream input;
    input.open(filename, ifstream::binary);
    assert(!input.fail() || !"Could not find file");
    char buffer[2];
    input.read(buffer, 2);
    assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
    input.ignore(8);
    int dataOffset = readInt(input);
    
    //Read the header
    int headerSize = readInt(input);
    int width;
    int height;
    switch (headerSize)
    {
        case 40:
            //V3
            width = readInt(input);
            height = readInt(input);
            input.ignore(2);
            assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
            assert(readShort(input) == 0 || !"Image is compressed");
            break;
        case 12:
            //OS/2 V1
            width = readShort(input);
            height = readShort(input);
            input.ignore(2);
            assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
            break;
        case 64:
            //OS/2 V2
            assert(!"Can't load OS/2 V2 bitmaps");
            break;
        case 108:
            //Windows V4
            assert(!"Can't load Windows V4 bitmaps");
            break;
        case 124:
            //Windows V5
            assert(!"Can't load Windows V5 bitmaps");
            break;
        default:
            assert(!"Unknown bitmap format");
    }
    
    //Read the data
    int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
    int size = bytesPerRow * height;
    auto_array<char> pixels(new char[size]);
    input.seekg(dataOffset, ios_base::beg);
    input.read(pixels.get(), size);
    
    //Get the data into the right format
    auto_array<char> pixels2(new char[width * height * 3]);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                pixels2[3 * (width * y + x) + c] =
                pixels[bytesPerRow * y + 3 * x + (2 - c)];
            }
        }
    }
    
    input.close();
    
    return new Image(pixels2.release(), width, height);
}

// Convierte la imagen en una textura y regresa el id de la textura
void loadTexture(Image* image,int k)
{
    
    glBindTexture(GL_TEXTURE_2D, texturas[k]); //Tell OpenGL which texture to edit
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    //Map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                 0,                            //0 for now
                 GL_RGB,                       //Format OpenGL uses for image
                 image->width, image->height,  //Width and height
                 0,                            //The border of the image
                 GL_RGB, //GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                 //as unsigned numbers
                 image->pixels);               //The actual pixel data
}

void freeTexture(GLuint texture)
{
    glDeleteTextures( 1, &texture);  // Delete our texture, simple enough.
}


