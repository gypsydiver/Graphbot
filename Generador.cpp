#include <iostream>
#include <stack>

class Generador {

stack<string> PilaO;
stack<string> POper;


void agregaFF();
void sacarFF();

string genera(string op, string opdo1, string opdo2){

    


}

string popPilaO() {

    string top;

    top = PilaO.top();
    PilaO.pop();
    return top;

}

string popPOper() {

    string top;

    top = POper.top();
    POper.pop();
    return top;

}


void pushPOper(string op) {
        
    POper.push(op);

}

void pushPilaO(string op) {
        
    PilaO.push(op);

}

bool PilaOempty() {
    
    if(PilaO.empty())
    return true;
    else
    return false;
}

bool POperempty(){

    if(POper.empty())
    return true;
    else
    return false;
}

void imprimePilaO{

while(! PilaO.empty()){
    
    cout << PilaO.top() << ", ";

    PilaO.pop();
}
    
}

void imprimePOper{

while(! POper.empty()){
    
    cout << POper.top() << ", ";

    POper.pop();
}

}

}


