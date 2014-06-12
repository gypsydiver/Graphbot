//
//  Cargador.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/3/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

#ifndef Graphbot_Cargador_h
#define Graphbot_Cargador_h

#include <fstream>
#include <map>
using namespace std;

class Cargador {
    
    map<int, float> constantes_globales;
    map<int, float>::const_iterator it;
    
public:
    void carga_globales() {
        
        ifstream file;
        char *tokens;
        char *tok;
        string line;
        string flotante;
        string direccion;
        
        file.open("constNum.txt");
        
        while (getline(file, line)){
            
            tok = &*line.begin();
            tokens = strtok(tok,":");
            float flotante = atof(tokens);
            tokens = strtok (NULL, ":");
            int direccion = atoi(tokens);
            
            constantes_globales[direccion] = flotante;
        }
        file.close();
    }
    
    float getConstante(int dir) {
        return constantes_globales[dir];        
    }
};
#endif
