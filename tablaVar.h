#include <iostream>
#include <string>
using namespace std;

//data structure to hold id and data, our data-structure we want to use
struct data {
public:
		int id; //to hold a unique id for each element
        string nombre; // string name for each element
        int tipo; // type of the element
		int dirV; // virtual address of the element
        int dirI;
        int tam;
};

class tablaVariables {
		data tvar[51]; //the table to hold hashed data structs
		int numel; //number of elements in table, to check if it's full
public:
		tablaVariables();
		int hash(int &id);
		int rehash(int &id);
		int add_var(data &d);
        int remove_var(string &name);
        void remove_all();
        int getid_var(string &name);
        bool find_var(string &name);
        int find_type(string &name);
        int getdirI(string &name);
        int getdirV(string &name);         
        int get_tam(string &name);       
		void output();
};

/*this is the function to give hashed id, it's a simple one...
It's better that we use a prime number for our length, thats why I used 11
and the bigger possible, it's better because we reduce our collisions*/
int tablaVariables::hash(int &id) {
		return (id%51);
}
/*in case of ay collision(a hashed value which is already occupied before)
we use rehash function instead of hash*/
int tablaVariables::rehash(int &id) {
		return ((id+1)%51);
}

tablaVariables::tablaVariables() {
		//create an array of data structure
		int i;
		for(i=0;i<=50;i++) {
				tvar[i].id = -1; //set all ids to -1 to show they're empty
				tvar[i].nombre = ""; //set all ids to -1 to show they're empty
				tvar[i].tipo = -1; //set all data values to 0, which is default
				tvar[i].dirV = -1; //set all data values to 0, which is default
				tvar[i].dirI = -1; //set all data values to 0, which is default   
				tvar[i].tam = -1; //set all data values to 0, which is default                                
		}
		numel = 0;
}

int tablaVariables::add_var(data &d) {
		if(numel < 51) {
				//table has empty places...
				int hashed = hash(d.id);
				if(hashed >= 0 && hashed <= 50 && tvar[hashed].id == -1) {
						//slot is empty, assign new data
						tvar[hashed].id = d.id;
						tvar[hashed].nombre = d.nombre;
                        tvar[hashed].tipo = d.tipo;
                        tvar[hashed].dirV = d.dirV;
                        tvar[hashed].dirI = d.dirI;
                        tvar[hashed].tam = d.tam;
						return 0;
				} else {
						//we need to rehash the id
			int i=0;
			//try every place in table to find an empty place
			while(i<=50) {
							hashed = rehash(hashed);
							if(tvar[hashed].id == -1) {
					            	tvar[hashed].id = d.id;                                
									tvar[hashed].nombre = d.nombre;
                                    tvar[hashed].tipo = d.tipo;
                                    tvar[hashed].dirV = d.dirV;
                                    tvar[hashed].dirI = d.dirI;
                                    tvar[hashed].tam = d.tam;
									return 0;
							} else if(i==50) {
									//we couldn't find the empty place
									return -1; //terminate function with error
							}
				i++; //update value of i
			}
				}
		} else {
				//table is full
				return (-1);
		}

        return 0;
}


int tablaVariables::remove_var(string &name) {
        int id = 0;
		int hashed = hash(id);
		if(tvar[hashed].nombre.compare(name) == 0) {
				//this is the right one to delete
                tvar[hashed].id = -1;
				tvar[hashed].nombre = "";
				numel -= 1;
				return 0;
		} else {
				//we need a rehash to find the one
		int i=0;
		while(i<=50) {
					hashed = rehash(hashed);
					if(tvar[hashed].nombre.compare(name) == 0) {
                            tvar[hashed].id = -1;
							tvar[hashed].nombre = ""; //set the id to -1 because it is going to be empty
							numel -= 1; //decrease 1 from number of elements
							return 0; //success
					} else if(i==50) {
							return -1; //terminate function
			}
			i++; //update the value of i
				}
		}

        return 0;
}

void tablaVariables::remove_all() {

  for(int i=0;i<=50;i++) {
      tvar[i].id = -1;
      numel -= 1;
    }
}

bool tablaVariables::find_var(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(tvar[i].nombre.compare(name) == 0) 
				return true; 
        }
        return false;

    }

int tablaVariables::find_type(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(tvar[i].nombre.compare(name) == 0) 
				return tvar[i].tipo; 
        }
        return -1;

    }

int tablaVariables::getid_var(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(tvar[i].nombre.compare(name) == 0) {
                cout << "Candidato: " << tvar[i].nombre << endl;
                cout << "ID Candidato: " << tvar[i].id << endl;
				return tvar[i].id; 
        }
        }
        return -1;

    }

int tablaVariables::getdirI(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(tvar[i].nombre.compare(name) == 0) 
				return tvar[i].dirI; 
        }
        return -1;

    }

int tablaVariables::getdirV(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(tvar[i].nombre.compare(name) == 0) 
				return tvar[i].dirV; 
        }
        return -1;

    }

int tablaVariables::get_tam(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(tvar[i].nombre.compare(name) == 0) 
				return tvar[i].tam; 
        }
        return -1;

    }
        
void tablaVariables::output() {
		int i;
		for(i=0;i<51;i++) {
                if(tvar[i].id != -1)
				cout << "Variable: "<<tvar[i].nombre<< " Tipo: "<<tvar[i].tipo<<" dirV: "<<tvar[i].dirV<< " dirI: " << tvar[i].dirI << endl;
		}
}



