#include <iostream>
#include <stack>

class Generador {

stack<string> PilaO;
stack<string> POper;

public:

string genera(string op, string opdo1, string opdo2);
void pushPOper(string op);
void pushPilaO(string opdo);
void agregaFF();
void sacarFF();
bool PilaOempty();
bool POperempty();
void imprimePilaO();
void imprimePOper();
int tempActual();

}

string genera(string op, string opdo1, string opdo2){




}

void pushPOper(string op) {
        
    POper.push(op);

}

void pushPilaO(string op) {
        
    PilaO.push(op);

}
