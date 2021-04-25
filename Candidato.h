#ifndef CANDIDATO_H_
#define CANDIDATO_H_

#include <string>		// Necessário para usar strings
using namespace std;

class Candidato{
    public:
        Candidato(int numero, int votos_nominais, string situacao, string nome, string nome_urna, char sexo, string data_nasc, string destino_voto, int numero_partido);
    private:
        string nome;
        char sexo; 
        string data_nasc;  
        int numero;
        int numero_partido;
        int votos_nominais;
        string situacao; 
        string nome_urna;
        string destino_voto; 
};

#endif