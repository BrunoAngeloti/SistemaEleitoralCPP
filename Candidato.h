#ifndef CANDIDATO_H_
#define CANDIDATO_H_
#include <list>
#include <string>	
#include <vector>	
using namespace std;

class Candidato{
    public:
        Candidato(list<string> lista);
        //Candidato(
            //int numero, int votos_nominais, string situacao, string nome,
            //string nome_urna, char sexo, string data_nasc, string destino_voto, int numero_partido
        //);

        string getNome(); 
        void setNome(string nome); 

        string getSexo(); 
        void setSexo(string sexo); 

        string getData_nasc(); 
        void setData_nasc(string data_nasc); 

        int getNumero(); 
        void setNumero(int numero); 

        int getNumero_partido(); 
        void setNumero_partido(int numero_partido); 

        int getVotos_nominais(); 
        void setVotos_nominais(int votos_nominais); 

        string getSituacao(); 
        void setSituacao(string situacao);

        string getNome_urna(); 
        void setNome_urna(string nome_urna); 

        string getDestino_voto(); 
        void setDestino_voto(string destino_voto); 

        bool identificaEleitos();
        bool identificaValidade();
        
        bool comparaNumPartido(int numeroId);
        int retornaIdadeCandidato(string dataRef);

        void imprimeCandidato();


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