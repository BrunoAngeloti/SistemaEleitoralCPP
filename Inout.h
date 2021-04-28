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
        void imprimeRelatorios(
            int qtdEleitos, 
            vector<Candidato> candidatosEleitos, 
            vector<Partido> partidos, 
            vector<Candidato> maisVotados, 
            vector<Candidato> naoEleitos,
            vector<Candidato> candidatosValidos, 
            vector<Candidato> beneficiados,
            vector<Candidato> primeiros, 
            vector<Candidato> ultimos
        );
        void imprimeIdadeSexoVoto(vector<string> idades, vector<string> sexos, vector<string> votos, int qtdEleitos);
    private:
        void imprimeNumVagas(int qtdEleitos);
        void imprimeVereadoresEleitos(vector<Candidato> candidatosEleitos, vector<Partido> partidos);
        void imprimeMaisVotados(vector<Candidato> maisVotados, vector<Partido>  partidos);
        void imprimeNaoEleitos(vector<Candidato> maisVotados, vector<Candidato> naoEleitos, vector<Partido> partidos);
        void imprimeBeneficiados(vector<Candidato> candValidos, vector<Candidato> beneficiados, vector<Partido> partidos);
        void imprimePartidos(vector<Partido> partidos);
        void imprimePrimUlt(vector<Candidato> primeiros, vector<Candidato> ultimos, vector<Partido> partidos);
};

#endif