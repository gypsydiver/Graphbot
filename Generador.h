#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int temporalActual = 1;
int cont_cuadruplos = 1;

class Generador {
    private:
        stack<string> PilaO;
        stack<string> POper;
        stack<string> PilaO_aux;
        stack<string>  POper_aux;
       

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

        void imprimePilaO(){
            while(!PilaO.empty()){
                cout << PilaO.top() << ", ";
                PilaO_aux.push(popPilaO());
            }
            cout<<endl;

            while(!PilaO_aux.empty()){
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

        void pushPOper(string op) {  
            POper.push(op);
        }

        void pushPilaO(string op) {
            PilaO.push(op);
        }

        
        void start(int i){
            ofstream fileout;
            fileout.open("CodigoInt.txt", std::ios::app);

            switch(i) {
                case 1:
                    // 5.- Si pop(POper) == '+' o '-'            
                    if(!POper.empty() && PilaO.size() >=2){
                        string posible_operador = POper.top();
                        if((posible_operador == "+") || (posible_operador == "-")){
                            string opdo2 = popPilaO();
                            string opdo1= popPilaO();
                            //sacar posible_operador de la pila
                            POper.pop();
                            //genera(posible_operador,opdo1,opdo2, "", 0);
                            fileout << cont_cuadruplos << ". "<< posible_operador << " " << opdo1 << " " << opdo2 <<" "<<tempDeAvail()<<endl; 

                            //actualiza el contador de cuádruplos
                            cont_cuadruplos++;
                        }
                    }
                break;

                case 2:
                    // 4.- Si pop(POper) == '*' o '/'            
                    if(!POper.empty() && PilaO.size() >=2){
                        string posible_operador = POper.top();
                        if((posible_operador == "*") || (posible_operador == "/")){
                            string opdo2 = popPilaO();
                            string opdo1= popPilaO();
                            //sacar posible_operador de la pila
                            POper.pop();
                            //genera(posible_operador,opdo1,opdo2, "", 0);
                            fileout << cont_cuadruplos << ". "<< posible_operador << " " << opdo1 << " " << opdo2 <<" "<<tempDeAvail()<<endl;
                            
                            //actualiza el contador de cuádruplos
                            cont_cuadruplos++;

                        }
                    }
                break;

                case 3:
                    // 1 parámetro
                    if(!POper.empty() && !PilaO.empty()){
                        string op = popPOper();
                        string opdo1 = popPilaO();
                       // genera(posible_operador,opdo1, "", "", 1);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << endl;
    
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;
                    }
                break;

                case 4:
                    // 2 parámetros
                    if(!POper.empty() && PilaO.size() >=2){
                        string op = popPOper();
                        string opdo2 = popPilaO();
                        string opdo1 = popPilaO();
                        //genera(posible_operador,opdo1, opdo2, "", 2);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << endl;  
                    
                         //actualiza el contador de cuádruplos
                         cont_cuadruplos++;
    
                    }
                break;

                case 5:
                    // 3 parámetros
                    if(!POper.empty() && PilaO.size() >=3){
                        string op = popPOper();
                        string opdo3 = popPilaO();
                        string opdo2 = popPilaO();
                        string opdo1 = popPilaO();
                        //genera(posible_operador,opdo1, opdo2, opdo3, 3);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << opdo3 << endl;
                        
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

                case 6:
                    // Sin parámetros y no regresa nada
                    if(!POper.empty()){
                        string op = popPOper();
                        //genera(op,"","","", 5);
                        fileout << cont_cuadruplos << ". " << op << endl;
                        
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

                case 7:
                    // Sin parámetros y regresa algo
                    if(!POper.empty()){
                        string op = popPOper();
                        fileout << cont_cuadruplos << ". " << op << "  " << tempDeAvail() << endl;

                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

                 case 8:
                  // Comparadores
                    if(!POper.empty() && PilaO.size() >=2){
                        string op = popPOper();
                        string opdo2 = popPilaO();
                        string opdo1 = popPilaO();
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << tempDeAvail() << endl;        
           
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

            }

        }
};
