#ifndef CANDIDATO_H_
#define CANDIDATO_H_
#include "Partido.h"
#include <list>
#include <string>	
#include <vector>	
using namespace std;

class Candidato{
    public:
        Candidato(list<string> lista);
        
        string getNome() const; 
        void setNome(string nome); 

        string getSexo() const; 
        void setSexo(string sexo); 

        string getData_nasc() const; 
        void setData_nasc(string data_nasc); 

        int getNumero() const; 
        void setNumero(int numero); 

        int getNumero_partido() const; 
        void setNumero_partido(int numero_partido); 

        int getVotos_nominais() const; 
        void setVotos_nominais(int votos_nominais); 

        string getSituacao() const; 
        void setSituacao(string situacao);

        string getNome_urna() const; 
        void setNome_urna(string nome_urna); 

        string getDestino_voto() const; 
        void setDestino_voto(string destino_voto); 

        bool identificaEleitos() const;
        bool identificaValidade() const;
        
        bool comparaNumPartido(const int numeroId) const;
        int retornaIdadeCandidato(const string& dataRef) const;

        void imprimeCandidatos(const vector<Partido> & part) const;
        void imprime(const vector<Partido>& part, const string nome, const int num, const int votos) const;


    private:
        string nome;
        string sexo; 
        string data_nasc;  
        int numero;
        int numero_partido;
        int votos_nominais;
        string situacao; 
        string nome_urna;
        string destino_voto; 
};

#endif