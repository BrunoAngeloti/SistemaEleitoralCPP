#ifndef PARTIDO_H_
#define PARTIDO_H_
#include <vector>
#include <list>
#include <string>
using namespace std;

class Partido{
    public:
        Partido(list<string> lista);
        int getNumero_partido() const;
        void setNumero_partido(int numero_partido);

        int getVotos_legenda() const;
        void setVotos_legenda(int votos_legenda); 

        string getNome_partido() const; 
        void setNome_partido(string nome_partido); 

        string getSigla_partido() const;   
        void setSigla_partido(string sigla_partido);

        int getVotos_total() const; 
        void setVotos_total(int votos_total); 

        int getVotos_nominais() const;    
        void setVotos_nominais(int votos_nominais); 

        int getCand_eleitos() const; 
        void setCand_eleitos(int cand_eleitos); 

        bool comparaPartido(const int numeroId) const;

        void imprimePartido() const;
       
  
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