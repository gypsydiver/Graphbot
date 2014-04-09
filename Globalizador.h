#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Globalizador {
    const static int offset_constantesg = 1000;

    map<float, int> constantes_globales; 
    map<float, int>::const_iterator it;
    int constanteActual = 0;
    
    public:
   
    int asigna_globales(string token) {
       float llave = stof(token);
       it = constantes_globales.find(llave); 
        // Checar si la constante ya esta en la estructura
       if (it != constantes_globales.end()) {
           // Si sí, regresa el valor
           return constantes_globales[llave];
       }else {
           // Si no, agrega a hash table y regresa el valor asignado
           int direccion = asigna_constante();   
           constantes_globales[llave] = direccion;
           return direccion;
       }
    }
    
    void toFile(){
        ofstream fileout;
        fileout.open("constNum.txt", std::ios::app);
        for(it = constantes_globales.begin(); it != constantes_globales.end(); ++it) {
            fileout <<it->first<<":"<<it->second<<endl;
        }
        fileout.close();
    }

    void readFromFile(){

    }

    private:
        int asigna_constante() {
            return offset_constantesg + (constanteActual++);
        }
};
