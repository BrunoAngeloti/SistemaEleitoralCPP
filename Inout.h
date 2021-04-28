#ifndef INOUT_H_
#define INOUT_H_

#include <string>	
#include <list>
#include "Partido.h"	
using namespace std;

class Inout{
    public:
        list<Partido> lePartidos(string arq);
    private:
        
};

#endif