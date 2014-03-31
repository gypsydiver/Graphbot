#include <iostream>
#include <string>
using namespace std;

//data structure to hold id and data, our data-structure we want to use
struct procs {
public:
		int id; //to hold a unique id for each element
        string nombre; // string name for each element
        int dirI; // initial address of the element
		int tam; // size of the element
        tablaVariables tv; // vars table
};

class dirProcs {
        procs dirproc[51];
		int numel; //number of elements in table, to check if it's full
public:
		dirProcs();
		int hash(int &id);
		int rehash(int &id);
		int add_proc(procs &d);        
        bool find_proc(string &name);        
		void output_proc();
};

/*this is the function to give hashed id, it's a simple one...
It's better that we use a prime number for our length, thats why I used 11
and the bigger possible, it's better because we reduce our collisions*/
int dirProcs::hash(int &id) {
		return (id%51);
}
/*in case of ay collision(a hashed value which is already occupied before)
we use rehash function instead of hash*/
int dirProcs::rehash(int &id) {
		return ((id+1)%51);
}

dirProcs::dirProcs() {
		//create an array of data structure
		int i;
		for(i=0;i<=50;i++) {
				dirproc[i].id = -1; //set all ids to -1 to show they're empty
				dirproc[i].nombre = ""; //set all ids to -1 to show they're empty
				dirproc[i].dirI = -1; //set all data values to 0, which is default
				dirproc[i].tam = -1; //set all data values to 0, which is default
		}
		numel = 0;
}

int dirProcs::add_proc(procs &d) {
		if(numel < 51) {
				//table has empty places...
				int hashed = hash(d.id);
				if(hashed >= 0 && hashed <= 50 && dirproc[hashed].id == -1) {
						//slot is empty, assign new data
						dirproc[hashed].id = d.id;
						dirproc[hashed].nombre = d.nombre;
                        dirproc[hashed].dirI = d.dirI;
                        dirproc[hashed].tam = d.tam;
                        dirproc[hashed].tv = d.tv;
						return 0;
				} else {
						//we need to rehash the id
			int i=0;
			//try every place in table to find an empty place
			while(i<=50) {
							hashed = rehash(hashed);
							if(dirproc[hashed].id == -1) {
					            	dirproc[hashed].id = d.id;                                
									dirproc[hashed].nombre = d.nombre;
                                    dirproc[hashed].dirI = d.dirI;
                                    dirproc[hashed].tam = d.tam;
                                    dirproc[hashed].tv = d.tv; 
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

bool dirProcs::find_proc(string &name) {
    
    
    for(int i=0;i<=50;i++) {
		if(dirproc[i].nombre.compare(name) == 0) 
				return true; 
        }
        return false;

    }

void dirProcs::output_proc() {
		int i;
		for(i=0;i<51;i++) {
                if(dirproc[i].id != -1) {
				cout << "Procedimiento: "<<dirproc[i].nombre<<" DirInicial: "<<dirproc[i].dirI<<" Tamaño:"<<dirproc[i].tam<<"\nTabla Variables: " << endl;
                (dirproc[i].tv).output();
		}
}
}




