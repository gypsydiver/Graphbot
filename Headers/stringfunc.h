//
//  stringfunc.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/3/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

//we redefine our own stoi since previous versions of c++11 do not include it

#ifndef Graphbot_stringfunc_h
#define Graphbot_stringfunc_h
#include <sstream>
//using namespace std;
int stoi(string text){
    int number;
    if ( ! (std::istringstream(text) >> number) ) number = 0;
    return number;
}

#endif
