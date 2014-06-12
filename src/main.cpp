#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "wx/glcanvas.h"

// include OpenGL
#ifdef __WXMAC__
#include "OpenGL/glu.h"
#include "OpenGL/gl.h"
#endif

#include "base.h"
#include "globals.h"
#include "movement.h"
#include "SOIL.h"
#include "Sound.h"
#include "stringfunc.h"

using namespace std;

IMPLEMENT_APP(Graphbot)
int draw(int cuadruplo, int comando, int opdo1, int opdo2,int opdo3);
void readFromFile(const char* filename);
void loadTextures();

//this declaration could go somewhere else
MainFrame *MainWin;

bool Graphbot::OnInit(){
    loadResourcesPath();
    
    MainWin = new MainFrame(_("Graphbot"), wxPoint(0,22), wxSize(1270,770));
    MainWin->Show();

    //system("pwd");
    //run the compiler
    //system(executeCommand);
    //readFromFile(codigoInt);
    return true;
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1,title, pos, size){
    // normally we would initialize objects such as buttons and textboxes here
    
    //int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
    
    glPane = new BasicGLPane(this,GL_PANE_pane);
    
    codeGrounds = new wxTextCtrl(this, TEXT_Main, "//Start here with your Graphbot program!", wxPoint(0,0), wxSize(390,750), wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    terminal = new TerminalWx(this,TERMINAL_term,wxPoint(390,571),66,7,_T("ID_TERM"));

    terminal->SetFont(terminal->GetFont().MakeLarger().MakeLarger().MakeLarger());
    terminal->DisplayChars("Graphbot>");
}

void MainFrame::OnExit( wxCommandEvent& event ){
    Close(TRUE); // Tells the OS to quit running this process
}

BEGIN_EVENT_TABLE (MainFrame, wxFrame)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(BasicGLPane, wxGLCanvas)
    //EVT_PAINT(BasicGLPane::render)
END_EVENT_TABLE()

BasicGLPane::BasicGLPane(wxFrame* parent,wxWindowID id) :
wxGLCanvas(parent, id, NULL, wxPoint(390, 0), wxSize(880, 570), wxFULL_REPAINT_ON_RESIZE){
	m_context = new wxGLContext(this);
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    
    //system("pwd");
    prepare2DViewport(0,0,getWidth(), getHeight());
}

BasicGLPane::~BasicGLPane(){
	delete m_context;
}

void BasicGLPane::resized(wxSizeEvent& evt){
    Update();
}

/** Inits the OpenGL viewport for drawing in 2D. */
void BasicGLPane::prepare2DViewport(int topleft_x, int topleft_y, int bottomright_x, int bottomright_y){
    
    //glClearColor(fondoR, fondoG, fondoB, 1.0f); // Default White Background
    //glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_TEXTURE_2D);   // textures
    //glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-orthoWidth, orthoWidth,-orthoHeight, orthoHeight);
    glViewport(topleft_x, topleft_y, bottomright_x-topleft_x, bottomright_y-topleft_y);
    
    
    
    
   // glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
}

int BasicGLPane::getWidth(){
    return GetSize().x;
}

int BasicGLPane::getHeight(){
    return GetSize().y;
}

void loadTextures(){
    texturas[0] = SOIL_load_OGL_texture("Textura1.jpg",SOIL_LOAD_AUTO,1,SOIL_FLAG_INVERT_Y);
    texturas[1] = SOIL_load_OGL_texture("Textura2.jpg",SOIL_LOAD_AUTO,2,SOIL_FLAG_INVERT_Y);
    texturas[2] = SOIL_load_OGL_texture("Textura3.jpg",SOIL_LOAD_AUTO,3,SOIL_FLAG_INVERT_Y);
    texturas[3] = SOIL_load_OGL_texture("Textura4.jpg",SOIL_LOAD_AUTO,4,SOIL_FLAG_INVERT_Y);
    texturas[4] = SOIL_load_OGL_texture("graphbot.png",SOIL_LOAD_AUTO,5,SOIL_FLAG_INVERT_Y);
}

void show(){
    if (showBotOrNot) {
        // Texturas
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        glPushMatrix();
        
        glTranslatef(pointerx, pointery, 0.0);
        glRotatef(direccionEnGrados-90.0, 0.0, 0.0, 1.0);
        glTranslatef(0.0,0.0,0.0);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glColor3f(1.0f,1.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D, texturas[4]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex2f(-coor, -coor);
        glTexCoord2f(1.0f, 0.0f);
        glVertex2f(coor, -coor);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f(coor, coor);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(-coor, coor);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void dibuja_textura(int num){
    if(num < 5 && num >= 0) {
        //Texturas
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        glMatrixMode(GL_PROJECTION);
        
        glPushMatrix();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //glColor3f(1.0f,0.0f,0.0f);
        glBindTexture(GL_TEXTURE_2D, texturas[num]);
        glLoadIdentity();
        gluOrtho2D(0, 1, 0, 1);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex2f(0,0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex2f(1, 0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f(1, 1);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(0,1);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void BasicGLPane::reset(){
    //reset relevant variables
    lineSize = 3.0;
    penDown = true;
    direccionEnGrados = 90.0;
    pointerx = pointery = 0.0;
    //compilo = false;
    //stop any music if it was played
    if(musicWasPlayed){
        musicWasPlayed = false;
        alSourceStop(source);
        cleanUp();
    }
    
    if(!loadedTextures){
        loadedTextures = true;
        loadTextures();
    }
}

void BasicGLPane::render(){
    //if(!IsShown()) return;
    wxGLCanvas::SetCurrent(*m_context);
    //wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event
    
    reset();
    
    glLoadIdentity();
    glClearColor(fondoR, fondoG, fondoB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    
    prepare2DViewport(0, 0, getWidth(), getHeight());
    
    if(compilo){
        
        dibuja_textura(num_txt);
    
        for(int i=1; i<= cuad.cuantos_cuadruplos; i++){
            cuadruplo cuadruploActual = cuad.get(i);
            //cout << "turup i ="<<i<<endl;
            i = draw(cuadruploActual.cuadruplo, cuadruploActual.comando,cuadruploActual.opdo1, cuadruploActual.opdo2,cuadruploActual.opdo3);
        }
    
        show();
        compilo = false;
    }
    //glFlush();
    SwapBuffers();
}

void postRedisplay(){
    MainWin->glPane->render();
}

//this whole function can be done triggering events
void TerminalWx::runInput(wxString input){
    //save the contents of the wxTextCtrl to src
    input.Trim();
    if(input.compare("run") == 0){
        compilo = false;
        MainWin->codeGrounds->SaveFile(srcFile,0);
        FILE *parserOutput = popen(executeCommand,"r");
        char output[1024];
        fgets(output, 1024, parserOutput);
        cout << output << endl;
        if(compilacionEx.compare(output) == 0){
            cout <<"compilación exitosa"<<endl;
            // Carga las constantes
            cargando.carga_globales();
                
            readFromFile(codigoInt);
            compilo = true;
        }
        pclose(parserOutput);
        DisplayChars(output);
        postRedisplay();
    }else if(input.compare("reset") == 0){
        //cout<<"BAM reset"<<endl;
        //default background color is white
        fondoR = fondoG = fondoB = 1.0;
        //default draw color is black
        colorR = colorG = colorB = 0.0;
        num_txt = -1;
        MainWin->glPane->reset();
        glClearColor(fondoR, fondoG, fondoB, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        MainWin->glPane->SwapBuffers();
        
    }else if(input.compare("about") == 0){
    
    }else if(input.compare("load") == 0){
        MainWin->codeGrounds->LoadFile(savedFile);
    }else if(input.compare("save") == 0){
        MainWin->codeGrounds->SaveFile(savedFile,0);
    }else if(input.compare("rainbow") == 0){
        MainWin->codeGrounds->LoadFile(rainbowEx);
    }else if(input.compare("castle") == 0){
        MainWin->codeGrounds->LoadFile(castleEx);
    }else if(input.compare("hearts") == 0){
        MainWin->codeGrounds->LoadFile(heartEx);
    }else if(input.compare("fibonacci") == 0){
        MainWin->codeGrounds->LoadFile(fiboEx);
    }
}

int draw(int cuadruplo, int comando, int opdo1, int opdo2,int opdo3){
    int retorno;
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
            glClearColor(fondoR, fondoG, fondoB, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            break;
            
            // Home
        case 5003:
            pointerx = pointery = 0.0;
            direccionEnGrados = 90.0;
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
            if(musicWasPlayed){
                alSourceStop(source);
                cleanUp();
            }
            break;
            
            // PlayMusic
        case 5011:
            if(!musicWasPlayed){
                loadSoundSource();
                alSourcePlay(source);
                musicWasPlayed = true;
            }
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
            
            //   cout << "Posx: " << pointerx << " PosY: "<<pointery << endl;
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
            
            // SetBackgroundTxt
        case 5021:
            num_txt = (int) memoria_actual.get(opdo1) - 1;
            
            if(!textura) {
                textura = true;
                postRedisplay();
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
            glClearColor(fondoR,fondoG,fondoB,1.0);
            
            num_txt = -1;
            
            if(!background) {
                background = true;
                postRedisplay();
            }
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
            
            if(memoria_actual.get(opdo1) > memoria_actual.get(opdo2)){
                memoria_actual.setTemporal(opdo3, 1);
            }else{
                memoria_actual.setTemporal(opdo3, 0);
            }
            break;
            
            // Menor que <
        case 5028:
            
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
            if(memoria_actual.get(opdo1) == 0) {
                //parche para el for, pues al terminar suma uno y se brinca un cuádruplo
                return opdo2-1;
            }
            break;
            
            // Param
        case 5038:{
            // Toma en cuenta las temporales de la memoria pasada
            Memoria pasada = Pila_Memorias.top();
            memoria_actual.set(opdo2, pasada.get(opdo1));
        }
            break;
            
            // Era
        case 5039:{
            Memoria memoria;
            memoria.nueva(opdo3, opdo1, opdo2);
            Pila_Memorias.push(memoria_actual);
            memoria_actual = memoria;
        }break;
            
            // Retorno Funcion
        case 5040:
            
            memoria_actual.destruye();
            memoria_actual = Pila_Memorias.top();
            Pila_Memorias.pop();
            
            // Regresa al cuadruplo donde estaba antes
            retorno = Pila_Cuadruplos.top();
            Pila_Cuadruplos.pop();
            return retorno-1;
            break;
            
            // Retorno Lista
        case 5041:
            // Regresa al cuadruplo donde estaba antes
            retorno = Pila_Cuadruplos.top();
            Pila_Cuadruplos.pop();
            return retorno-1;
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

void readFromFile(const char* filename){
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
        //cout << "Cuadruplo Actual: " << cuadruplo << endl;
        
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
    file.close();
}