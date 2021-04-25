#ifndef PARTIDO_H_
#define PARTIDO_H_

#include <string>		// Necessário para usar strings
using namespace std;

class Partido{
    public:
        Partido(int numero_partido, int votos_legenda, string nome_partido, string sigla_partido);
    private:
        int numero_partido;
        int votos_legenda;
        string nome_partido;
        string sigla_partido;
        int votos_nominais;
        int votos_total;
        int cand_eleitos;
        
};

#endif