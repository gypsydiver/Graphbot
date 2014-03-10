#include <iostream>
#include <string>
using namespace std;

//data structure to hold id and data, our data-structure we want to use
struct data {
public:
		int id; //to hold a unique id for each element
        string name; // string name for each element
        // type of the element
        // 1 - Float
        // 2 - Bool
        int type;
		float value; 
};

class hasher {
		data dt[51]; //the table to hold hashed data structs
		int numel; //number of elements in table, to check if it's full
public:
		hasher();
		int hash(int &id);
		int rehash(int &id);
		int add(data &d);
		int remove(data &d);
		void output();
};

/*this is the function to give hashed id, it's a simple one...
It's better that we use a prime number for our length, thats why I used 11
and the bigger possible, it's better because we reduce our collisions*/
int hasher::hash(int &id) {
		return (id%51);
}
/*in case of ay collision(a hashed value which is already occupied before)
we use rehash function instead of hash*/
int hasher::rehash(int &id) {
		return ((id+1)%51);
}

hasher::hasher() {
		//create an array of data structure
		int i;
		for(i=0;i<=50;i++) {
				dt[i].id = -1; //set all ids to -1 to show they're empty
				dt[i].value = 0; //set all data values to 0, which is default
		}
		numel = 0;
}

int hasher::add(data &d) {
		if(numel < 51) {
				//table has empty places...
				int hashed = hash(d.id);
				if(hashed >= 0 && hashed <= 50 && dt[hashed].id == -1) {
						//slot is empty, assign new data
						dt[hashed].id = d.id;
                        dt[hashed].type = d.type;
                        dt[hashed].name = d.name;
						dt[hashed].value = d.value;
						return 0;
				} else {
						//we need to rehash the id
			int i=0;
			//try every place in table to find an empty place
			while(i<=50) {
							hashed = rehash(hashed);
							if(dt[hashed].id == -1) {
									dt[hashed].id = d.id;
                                    dt[hashed].type = d.type;
                                    dt[hashed].name = d.name;
									dt[hashed].value = d.value;
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
}

int hasher::remove(data &d) {
		int hashed = hash(d.id);
		if(dt[hashed].id == d.id) {
				//this is the right one to delete
				dt[hashed].id = -1;
				numel -= 1;
				return 0;
		} else {
				//we need a rehash to find the one
		int i=0;
		while(i<=50) {
					hashed = rehash(hashed);
					if(dt[hashed].id == d.id) {
							dt[hashed].id = -1; //set the id to -1 because it is going to be empty
							numel -= 1; //decrease 1 from number of elements
							return 0; //success
					} else if(i==50) {
							return -1; //terminate function
			}
			i++; //update the value of i
				}
		}
}

void hasher::output() {
		int i;
		for(i=0;i<51;i++) {
                if(dt[i].id != -1)
				cout <<"Id Proc: "<<dt[i].id<<" Nombre: "<<dt[i].name<<" Tipo: "<<dt[i].type<<" Valor:"<<dt[i].value<<endl;
		}
}


