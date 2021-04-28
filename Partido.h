#ifndef PARTIDO_H_
#define PARTIDO_H_
#include <vector>
#include <list>
#include <string>		// Necessário para usar strings
using namespace std;

class Partido{
    public:
        Partido(list<string> lista);
        int getNumero_partido();
        void setNumero_partido(int numero_partido);

        int getVotos_legenda();
        void setVotos_legenda(int votos_legenda); 

        string getNome_partido(); 
        void setNome_partido(string nome_partido); 

        string getSigla_partido();   
        void setSigla_partido(string sigla_partido);

        int getVotos_total(); 
        void setVotos_total(int votos_total); 

        int getVotos_nominais();    
        void setVotos_nominais(int votos_nominais); 

        int getCand_eleitos(); 
        void setCand_eleitos(int cand_eleitos); 

        bool comparaPartido(int numeroId);

        void imprimePartido();
       
  
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