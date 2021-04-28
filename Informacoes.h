#ifndef INFORMACOES_H_
#define INFORMACOES_H_
#include "Partido.h"
#include "Candidato.h"
using namespace std;

class Informacoes{
    public:
        vector<Partido> ordenaPartidos(vector<Partido> partidos);
        vector<Candidato> ordenaCandidatos(vector<Candidato> candidatos);
        int retornaQtdEleitos(vector<Candidato> cand);
        int retornaQtdValidos(vector<Candidato> cand);
        int retornaQtdBeneficiados(vector<Candidato> candEleitos, vector<Candidato> maisVotados);
        vector<Candidato> retornaCandValidos(vector<Candidato> cand);
        vector<Candidato> retornaCandEleitos(vector<Candidato> candValidos, int qtdEleitos);
        vector<Candidato> retornaCandsMaisVotados(vector<Candidato> candValidos, int qtdEleitos);
        vector<Candidato> identificaBeneficiados(vector<Candidato> candEleitos, vector<Candidato> maisVotados);
        vector<Candidato> identificaNaoEleitos(vector<Candidato> candEleitos, vector<Candidato> maisVotados);
        
    private:
        
};

#endif