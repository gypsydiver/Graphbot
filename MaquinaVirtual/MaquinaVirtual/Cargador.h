#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Cargador {

    map<int, float> constantes_globales; 
    map<int, float>::const_iterator it;
 
    public:

    void carga_globales() {

    ifstream file;
    char * tokens;
    char *tok;
    string line;
    string flotante;
    string direccion;

    file.open("/Users/claudiahdz/Graphbot/MaquinaVirtual/MaquinaVirtual/constNum.txt");

        while (getline(file, line)){
        
        tok = &*line.begin();
        tokens = strtok(tok,":");
        float flotante = stof(tokens);
        tokens = strtok (NULL, ":");        
        int direccion = atoi(tokens); 
    
        constantes_globales[direccion] = flotante;      
        }

    }

    float getConstante(int dir) {
    return constantes_globales[dir];        
    }


};

