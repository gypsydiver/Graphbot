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

        
    string tempDeAvail(){
            string temporalSolicitado = "t" + to_string(tempActual());

            //agrega tempActual a PilaO
            pushPilaO(temporalSolicitado);

            temporalActual++;

            return temporalSolicitado;
        }

        void genera(string op, string opdo1, string opdo2, string opdo3, int tipo){

            ofstream fileout;
            fileout.open("CodigoInt.txt", std::ios::app);
            
            switch(tipo){
                case 0: // Expresión
                    fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << tempDeAvail() << endl;            
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
                    fileout << cont_cuadruplos << ". " << op << "  " << tempDeAvail() << endl;
                    break;            
                
                case 5: // Sin parámetros y no regresa nada
                    fileout << cont_cuadruplos << ". " << op << endl;
                    break;
                
                case 6: // Comparadores
                    fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << tempDeAvail() << endl;
                    break;
            }

            //actualiza el contador de cuádruplos
            cont_cuadruplos++;

            //actualiza temporal
            cout<<"Temporal actual: "<<tempActual()<<endl;
            
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
          	string posible_operador = POper.top();
            if((posible_operador == "+")|| (posible_operador == "-")){
                string opdo2 = popPilaO();
                string opdo1= popPilaO();
                POper.pop();
                genera(posible_operador,opdo1,opdo2, "", 0);                                      
            }
      	}
            break;

            case 2:
	    	// 4.- Si pop(POper) == '*' o '/'            
              if(! POperEmpty()){
	        string posible_operador = POper.top();
	        if((posible_operador == "*")|| (posible_operador == "/")){
	            string opdo2 = popPilaO();
	            string opdo1= popPilaO();
                POper.pop();
	            genera(posible_operador,opdo1,opdo2, "", 0);
	        }
	    }
            break;

            case 3:
            // 1 parámetro
          if(! POperEmpty()){
            string posible_operador = popPOper();
            string opdo1 = popPilaO();
            genera(posible_operador,opdo1, "", "", 1);      
            
        }
          break;

            case 4:
          // 2 parámetros
         if(! POperEmpty()){
            string posible_operador = popPOper();
            string opdo2 = popPilaO();
            string opdo1 = popPilaO();
            genera(posible_operador,opdo1, opdo2, "", 2);      
            
        }
          break;

            case 5:
         // 3 parámetros
          if(! POperEmpty()){
            string posible_operador = popPOper();
            string opdo3 = popPilaO();
            string opdo2 = popPilaO();
            string opdo1 = popPilaO();
            genera(posible_operador,opdo1, opdo2, opdo3, 3);      
            
        }

          break;

            case 6:
            // Sin parámetros y no regresa nada
             if(! POperEmpty()){
	        string posible_operador = popPOper();
	            genera(posible_operador,"","", "", 5);

}
            break;

         case 7:
          // Comparadores
         if(! POperEmpty()){
            string posible_operador = popPOper();
            string opdo2 = popPilaO();
            string opdo1 = popPilaO();
            genera(posible_operador,opdo1, opdo2, "", 6);      
            
        }
          break;
        
               }
}
};

