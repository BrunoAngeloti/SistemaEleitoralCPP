#ifndef INOUT_H_
#define INOUT_H_

#include <string>	
#include <vector>
#include "Partido.h"
#include "Candidato.h"	
using namespace std;

class Inout{
    public:
        vector<Partido> lePartidos(string arq);
        vector<Candidato> leCandidatos(string arq);
    private:
        
};

#endif