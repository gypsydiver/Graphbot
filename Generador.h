#include <iostream>
#include <stack>
using namespace std;

class Generador {

    stack<string> PilaO;
    stack<string> POper;
    stack<string> PilaO_aux;
    stack<string>  POper_aux;
    int temporalActual;
    
    public:
        void agregaFF();
        void sacarFF();

        int tempActual(){
            return temporalActual;
        }

        void genera(string op, string opdo1, string opdo2){
            //imprime cuadrupo
            cout << op << " " << opdo1 << " " << opdo2 << " " << temporalActual << endl;
            
            //agrega tempActual a PilaO
            pushPilaO(to_string(temporalActual));

            //actualiza temporal
            temporalActual++;
            cout<<"Temporal actual: "<<temporalActual<<endl;

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

        bool PilaOEmpty() {
            return PilaO.empty();
        }

        bool POperEmpty(){
            return POper.empty();
        }

        void imprimePilaO(){
            while(! PilaO.empty()){
                cout << PilaO.top() << ", ";
                PilaO_aux.push(popPilaO());

            }

            while(! PilaO_aux.empty()){
                pushPilaO(PilaO_aux.top());
                PilaO_aux.pop();
            
            }
        }

        void imprimePOper(){
             while(! POper.empty()){
                cout << POper.top() << ", ";
                POper_aux.push(popPOper());

            }

            while(! POper_aux.empty()){
                pushPOper(POper_aux.top());
                POper_aux.pop();
            
            }
        }
};


