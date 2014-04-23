#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int temporalActual = 2000;
int variableFlotanteActual = 3000;
int variableListaActual = 4000;
int cont_cuadruplos = 3;

class Generador {
    private:
        stack<int> PilaO;
        stack<int> POper;
        stack<int> PSaltos;
        stack<int> PilaO_aux;
        stack<int> POper_aux;
        stack<int> PSaltos_aux;
       
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
        //tengo hueva
        void generaEraMain(int flotantes, int listas, int temporales){

            ifstream filein;
            ofstream fileout;
            filein.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
            fileout.open("MaquinaVirtual/Build/Products/Debug/temp.txt");
            string line;

            fileout << "1. 5039 "<< flotantes <<" "<< listas <<" "<< temporales<< endl;

            while (getline(filein, line)){
                    fileout << line << endl;
            }

            filein.close();
            fileout.close();

            remove("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
            rename("MaquinaVirtual/Build/Products/Debug/temp.txt","MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");

        }

        void imprimePSaltos(){
            while(! PSaltos.empty()){
                cout << PSaltos.top() << ", ";
                PSaltos_aux.push(popPSaltos());
            }
            cout<<endl;

            while(! PSaltos_aux.empty()){
                pushPSaltos(PSaltos_aux.top());
                PSaltos_aux.pop();
            }
        }

        int variableActual(bool flotante) {
            if (flotante){
                return variableFlotanteActual;
            }else{
                return variableListaActual;
            } 
        }

        int tempActual(){
            return temporalActual;
        }

        void reinicializa_variable() {
            variableFlotanteActual = 3000;
            variableListaActual = 4000;
        }

        void reinicializa_temp() {
            temporalActual = 2000;
        }

        int variablesDeAvail(bool flotante) {
            int variableSolicitada = variableActual(flotante);
            if(flotante){
                variableFlotanteActual++;
            }else{
                variableListaActual++;
            }
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
            filein.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
            fileout.open("MaquinaVirtual/Build/Products/Debug/temp.txt");
            string line;
            string rep = to_string(salto) + ".";
            string str = "#";

            while (getline(filein, line)){
                while (true){
                    size_t pos = line.find(rep);
                    size_t pos1 = line.find(str);
                    size_t len = str.length();

                    // Encontró la posición del cuádruplo
                    if ((pos != string::npos) && (pos1 != string::npos)){
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

            remove("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
            rename("MaquinaVirtual/Build/Products/Debug/temp.txt","MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
         }
        
        void rellena_save(int salto, int var){
            //salto es donde se debe de rellenar, donde es a donde tiene que ir ese salto
            ifstream filein;
            ofstream fileout;
            filein.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
            fileout.open("MaquinaVirtual/Build/Products/Debug/temp.txt");
            string line;
            string rep = to_string(salto) + ".";
            string str = "&";

            while (getline(filein, line)){
                while (true){
                    size_t pos = line.find(rep);
                    size_t pos1 = line.find(str);
                    size_t len = str.length();

                    // Encontró la posición del cuádruplo
                    if ((pos != string::npos) && (pos1 != string::npos)){
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

            remove("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
            rename("MaquinaVirtual/Build/Products/Debug/temp.txt","MaquinaVirtual/Build/Products/Debug/CodigoInt.txt");
        }

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
            fileout.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt", ios::app);

            switch(i) {
                case 1:
                    // 5.- Si pop(POper) == '+' o '-'            
                    if(!POper.empty() && PilaO.size() >=2){
                        int posible_operador = POper.top();
                        if((posible_operador == 5032) || (posible_operador == 5033)){
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
                        if((posible_operador == 5034) || (posible_operador == 5035)){
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
                        //si es un salto pendiente se marca y se rellena con rellena_save
                        if (opdo2 == -1){
                            fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " &" << endl;  
                        }
                        else {
                            fileout << cont_cuadruplos << ". " << op << " " << opdo1 << " " << opdo2 << endl;  
                        }
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
                    if(!PilaO.empty()){
                        int resultado = popPilaO();
                        //Genera GotoF
                        fileout << cont_cuadruplos << ". " << "5037 "<< resultado << " #"<< endl;
                        pushPSaltos(cont_cuadruplos);
                        //actualiza el contador de cuádruplos
                        cont_cuadruplos++;
                    }
                break;

                case 10:
                    //Goto's
                    if(!PSaltos.empty()){
                        int retorno = popPSaltos();
                        fileout << cont_cuadruplos << ". " << "5036 "<< retorno <<endl;
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
                        fileout << cont_cuadruplos << ". " << "5037 "<< resultado << " #"<< endl;
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
                    pushPOper(5032);
                    start(1);
                    pushPOper(5022);  
                    start(4);
                break;

                case 13:
                    // Genera retorno Función
                    fileout << cont_cuadruplos << ". " << "5040" << endl;
                    //actualiza el contador de cuádruplos
                    cont_cuadruplos++; 
                break;

                case 14:
                    //Goto's
                    fileout << cont_cuadruplos << ". " << "5036 #" << endl;
                    //actualiza el contador de cuádruplos
                    cont_cuadruplos++;
                break;

                case 15:
                    // Genera retorno Lista
                    fileout << cont_cuadruplos << ". " << "5041" << endl;
                    //actualiza el contador de cuádruplos
                    cont_cuadruplos++; 
                break;
            }
        }

        void param(int param){
            ofstream fileout;
            fileout.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt", ios::app);
            // Genera parametros
            int dirV = 3000+param;
            if (PilaO.size() >= param){
                for(int i = param; i > 0; i--){
                    int param = popPilaO();
                    fileout << cont_cuadruplos << ". " << "5038 " << param << " " << dirV << endl;
                    //actualiza el contador de cuádruplos
                    cont_cuadruplos++; 
                    dirV--;
                }
            }
        }

        void gosub(int dir){
            ofstream fileout;
            fileout.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt", ios::app);
            // Genera gosub
            fileout << cont_cuadruplos << ". " << "5042 " << dir << endl;
            //actualiza el contador de cuádruplos
            cont_cuadruplos++; 
        }
        
        void era(int param, int varf, int varl, int tmp){
            ofstream fileout;
            fileout.open("MaquinaVirtual/Build/Products/Debug/CodigoInt.txt", ios::app);
            // Genera era
            fileout << cont_cuadruplos << ". " << "5039 "<< param + varf <<" "<< varl <<" "<< tmp << endl;
            //actualiza el contador de cuádruplos
            cont_cuadruplos++; 
        }
};
