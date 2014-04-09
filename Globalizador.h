#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Globalizador {
    
    const static int offset_constantesg = 1000;
    const static int offset_saltos = 4000;

    map<float, int> constantes_globales; 
    map<float, int>::const_iterator it;
    int constanteActual = 0;

    map<int, int > saltos;
    map<int, int>::const_iterator sal;
    int saltoActual = 0;
    
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

    int asigna_saltos(int saltillo) {
       sal = saltos.find(saltillo); 
        // Checar si el salto ya esta en la estructura
       if (sal != saltos.end()) {
           // Si sí, regresa el valor
           return saltos[saltillo];
       }else {
           // Si no, agrega a hash table y regresa el valor asignado
           int direccion = asigna_salto();   
           saltos[saltillo] = direccion;
           return direccion;
       }
    }

    void setValues(int x, int y) {
        constanteActual = x;
        saltoActual = y; 
    }
    
    void toFile(){
    
    }

    void readFromFile(string filename){
        
    }

    private:

        int asigna_constante() {
            return offset_constantesg + (constanteActual++);
        }

        int asigna_salto() {
            return offset_saltos + (saltoActual++);
        }
};
