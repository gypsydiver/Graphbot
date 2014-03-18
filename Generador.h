#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


    int temporalActual = 1;
    int cont_cuadruplos = 1;

class Generador {

    stack<string> PilaO;
    stack<string> POper;
    stack<string> PilaO_aux;
    stack<string>  POper_aux;

    public:
        void agregaFF(){
            pushPOper("$");
        }

        bool sacarFF(){
            if(POper.top() == "$"){
                POper.pop();
                //cout<<"Después de FF: "<<POper.top()<<endl;
            }
            return false;
        }

        int tempActual(){
            return temporalActual;
        }

        void genera(string op, string opdo1, string opdo2, string opdo3, int tipo){

            ofstream fileout;
            fileout.open("/Users/claudiahdz/Graphbot/CodigoInt.txt", std::ios::app);
            
            switch(tipo){

            case 0: // Expresión
            fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << "temp" << temporalActual << endl;
            temporalActual++;            
            break;

            case 1: // 1 parámetro
            fileout << cont_cuadruplos << ". " << op << " " << opdo1 << endl;
            break;

            case 2: // 2 parámetros
            fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << endl;
            break; 

            case 3: // 3 parámetros
            fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << opdo3 << endl;
            break; 

            case 4: // Sin parámetros y regresa algo
            fileout << cont_cuadruplos << ". " << op << "  " << temporalActual << endl;
            temporalActual++;
            break;            
            
            case 5: // Sin parámetros y no regresa nada
            fileout << cont_cuadruplos << ". " << op << endl;
            break;

            }

            //actualiza el contador de cuádruplos
            cont_cuadruplos++;
            
            //agrega tempActual a PilaO
            pushPilaO(to_string(temporalActual));

            //actualiza temporal
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
            cout<<endl;

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
            cout<<endl;

            while(! POper_aux.empty()){
                pushPOper(POper_aux.top());
                POper_aux.pop();
            }
        }

        void start(int i){
        
switch(i) {
            case 1:
	    	// 5.- Si pop(POper) == '+' o '-'            
              if(! POperEmpty()){
          	string posible_operando = popPOper();
            if((posible_operando == "+")|| (posible_operando == "-")){
                string opdo2 = popPilaO();
                string opdo1= popPilaO();
                genera(posible_operando,opdo1,opdo2, "", 0);                                      
            }
      	}
            break;

            case 2:
	    	// 4.- Si pop(POper) == '*' o '/'            
              if(! POperEmpty()){
	        string posible_operando = popPOper();
	        if((posible_operando == "*")|| (posible_operando == "/")){
	            string opdo2 = popPilaO();
	            string opdo1= popPilaO();
	            genera(posible_operando,opdo1,opdo2, "", 0);
	        }
	    }
            break;

            case 5:
            // Sin parámetros y no regresa nada
             if(! POperEmpty()){
	        string posible_operando = popPOper();
	            genera(posible_operando,"","", "", 5);

}
            break;
        
        
        }
}

};

