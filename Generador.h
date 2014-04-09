#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int temporalActual = 2000;
int variablesActual = 3000;
int cont_cuadruplos = 2;

class Generador {
    private:
        stack<int> PilaO;
        stack<int> POper;
        stack<int> PSaltos;
        stack<int> PilaO_aux;
        stack<int> POper_aux;
       
        int tempDeAvail(){
            int temporalSolicitado = tempActual();

            //agrega tempActual a PilaO
            pushPilaO(temporalSolicitado);

            temporalActual++;

            return temporalSolicitado;
        }

        int popPOper() {
            int top;
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

        int variableActual() {
            return variablesActual;
        }

        int tempActual(){
            return temporalActual;
        }


        void reinicializa_variable() {
        
        variablesActual = 3000;

        }

        void reinicializa_temp() {
       
         temporalActual = 2000;
        
        }

        int variablesDeAvail() {
            int variableSolicitada = variableActual();

            variablesActual++;

            return variableSolicitada;

        }

        int popPilaO() {
            int top;
            top = PilaO.top();
            PilaO.pop();
            return top;
        }

        int popPSaltos() {
            int top;
            top = PSaltos.top();
            PSaltos.pop();
            return top;
        }

        void rellena(int salto, int donde){
            //salto es donde se debe de rellenar, donde es a donde tiene que ir ese salto
            ifstream filein;
            ofstream fileout;
            filein.open("CodigoInt.txt");
            fileout.open("temp.txt");
            string line;
            string rep = to_string(salto);
            string str = "#";

            while (getline(filein, line)){
                while (true){
                    size_t pos = line.find(rep);
                    size_t pos1 = line.find(str);
                    size_t len = str.length();

                    // Encontró la posición del cuádruplo
                    if ((pos != std::string::npos) && (pos1 != std::string::npos)){
                        int size = line.size();
                        line.replace(pos1, len, to_string(donde));
                        fileout << line << endl;
                    }else {
                        fileout << line << endl;
                    }
                    break;
                }
            }

            filein.close();
            fileout.close();

            remove("CodigoInt.txt");
            rename("temp.txt","CodigoInt.txt");
        }

         void rellena_save(int salto, int var){
            //salto es donde se debe de rellenar, donde es a donde tiene que ir ese salto
            ifstream filein;
            ofstream fileout;
            filein.open("CodigoInt.txt");
            fileout.open("temp.txt");
            string line;
            string rep = to_string(salto);
            string str = "-1";

            while (getline(filein, line)){
                while (true){
                    size_t pos = line.find(rep);
                    size_t pos1 = line.find(str);
                    size_t len = str.length();

                    // Encontró la posición del cuádruplo
                    if ((pos != std::string::npos) && (pos1 != std::string::npos)){
                        int size = line.size();
                        line.replace(pos1, len, to_string(var));
                        fileout << line << endl;
                    }else {
                        fileout << line << endl;
                    }
                    break;
                }
            }

            filein.close();
            fileout.close();

            remove("CodigoInt.txt");
            rename("temp.txt","CodigoInt.txt");
        }


        /*void agregaFF(){
            pushPOper("$");
        }

        bool sacarFF(){
            if(POper.top() == "$"){
                POper.pop();
                //cout<<"Después de FF: "<<POper.top()<<endl;
            }
            return false;
        } */

        void pushPOper(int op) {  
            POper.push(op);
        }

        void pushPilaO(int op) {
            PilaO.push(op);
        }

        void pushPSaltos(int op) {
            PSaltos.push(op);
        }
        
        void start(int i){
            ofstream fileout;
            fileout.open("CodigoInt.txt", std::ios::app);

            switch(i) {
                case 1:
                    // 5.- Si pop(POper) == '+' o '-'            
                    if(!POper.empty() && PilaO.size() >=2){
                        int posible_operador = POper.top();
                        if((posible_operador == 32) || (posible_operador == 33)){
                            int opdo2 = popPilaO();
                            int opdo1= popPilaO();
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
                        int posible_operador = POper.top();
                        if((posible_operador == 34) || (posible_operador == 35)){
                            int opdo2 = popPilaO();
                            int opdo1= popPilaO();
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
                        int op = popPOper();
                        int opdo1 = popPilaO();
                       // genera(posible_operador,opdo1, "", "", 1);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << endl;
    
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;
                    }
                break;

                case 4:
                    // 2 parámetros
                    if(!POper.empty() && PilaO.size() >=2){
                        int op = popPOper();
                        int opdo2 = popPilaO();
                        int opdo1 = popPilaO();
                        //genera(posible_operador,opdo1, opdo2, "", 2);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << endl;  
                    
                         //actualiza el contador de cuádruplos
                         cont_cuadruplos++;
    
                    }
                break;

                case 5:
                    // 3 parámetros
                    if(!POper.empty() && PilaO.size() >=3){
                        int op = popPOper();
                        int opdo3 = popPilaO();
                        int opdo2 = popPilaO();
                        int opdo1 = popPilaO();
                        //genera(posible_operador,opdo1, opdo2, opdo3, 3);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << opdo3 << endl;
                        
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

                case 6:
                    // Sin parámetros y no regresa nada
                    if(!POper.empty()){
                        int op = popPOper();
                        //genera(op,"","","", 5);
                        fileout << cont_cuadruplos << ". " << op << endl;
                        
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

                case 7:
                    // Sin parámetros y regresa algo
                    if(!POper.empty()){
                        int op = popPOper();
                        fileout << cont_cuadruplos << ". " << op << " " << tempDeAvail() << endl;

                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;

                case 8:
                    // Comparadores
                    if(!POper.empty() && PilaO.size() >=2){
                        int op = popPOper();
                        int opdo2 = popPilaO();
                        int opdo1 = popPilaO();
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << " " << tempDeAvail() << endl;        
           
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                    }
                break;
                         
            case 9:
                    //GotoF's
                    /*Checar tipos*/
                    if(!PilaO.empty()){
                        int resultado = popPilaO();
                        //Genera GotoF
                        fileout << cont_cuadruplos << ". " << "37 "<< resultado << " #"<< endl;
                        pushPSaltos(cont_cuadruplos);
                        
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;
                    }
                break;

                case 10:
                    //Goto's
                    if(!PSaltos.empty()){
                        int retorno = popPSaltos();
                        fileout << cont_cuadruplos << ". " << "36 "<< retorno <<endl;

                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;
                    }

                break;
 
                case 11:
                    //GotoF de for's
                    /*Checar tipos*/
                    if(PilaO.size() >= 3){
                        int aumento = popPilaO();
                        int id = popPilaO();

                        int resultado = popPilaO();
                        //Genera GotoF
                        fileout << cont_cuadruplos << ". " << "37 "<< resultado << " #"<< endl;
                        pushPSaltos(cont_cuadruplos);
                        
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;

                        pushPilaO(id);
                        pushPilaO(aumento);
                        pushPilaO(id);
                    }
                break;

                case 12:
                    //aumento a la variable de control
                    pushPOper(32);
                    start(1);
                    pushPOper(22);  
                    start(4);
                break;

                case 13:
                    // Genera retorno
                    fileout << cont_cuadruplos << ". " << 41 << endl;
                    //actualiza el contador de cuádruplos
                    cont_cuadruplos++; 
                break;

                case 14:
                    //Goto's
                        fileout << cont_cuadruplos << ". " << "36 #" << endl;

                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;
                    

                break;

                case 15:
                    // SAVE
                    if(!POper.empty() && PilaO.size() >=2){
                        int op = popPOper();
                        int opdo2 = popPilaO();
                        int opdo1 = popPilaO();
                        //genera(posible_operador,opdo1, opdo2, "", 2);
                        fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << endl;  
                    
                         //actualiza el contador de cuádruplos
                         cont_cuadruplos++;
    
                    }
                break;


             }
                        }


            void param(int param){
            ofstream fileout;
            fileout.open("CodigoInt.txt", std::ios::app);

             // Genera parametros
                    if (PilaO.size() >= param){
                    for(int i = param; i > 0; i--){
                    int param = popPilaO();
                    fileout << cont_cuadruplos << ". " << "39 " << param << " param" << i << endl;
                    //actualiza el contador de cuádruplos
                    cont_cuadruplos++; 
            }
                    }
            }

            void gosub(int dir){
            ofstream fileout;
            fileout.open("CodigoInt.txt", std::ios::app);

            // Genera gosub
            fileout << cont_cuadruplos << ". " << "42 " << dir << endl;
            //actualiza el contador de cuádruplos
            cont_cuadruplos++; 
            }

            void era(int tam){
            ofstream fileout;
            fileout.open("CodigoInt.txt", std::ios::app);

            // Genera era
            fileout << cont_cuadruplos << ". " << "40 " << tam << endl;
            //actualiza el contador de cuádruplos
            cont_cuadruplos++; 
            }


};
