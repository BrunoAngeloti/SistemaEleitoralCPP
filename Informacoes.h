#ifndef INFORMACOES_H_
#define INFORMACOES_H_
#include "Partido.h"
#include "Candidato.h"
using namespace std;

class Informacoes{
    public:
        void ordenaPartidos(vector<Partido> & partidos);

        void ordenaCandidatos(vector<Candidato> & candidatos);

        void ordenaCandidatosNumPartido(vector<Candidato> & candidatos);

        int retornaQtdEleitos(vector<Candidato> & cand);

        int retornaQtdValidos(vector<Candidato> & cand);

        int retornaQtdBeneficiados(vector<Candidato> & candEleitos, vector<Candidato> & maisVotados);

        vector<Candidato> retornaCandValidos(vector<Candidato> & cand);

        vector<Candidato> retornaCandEleitos(vector<Candidato> & candValidos);

        vector<Candidato> retornaCandsMaisVotados(vector<Candidato> & candValidos, int qtdEleitos);

        vector<Candidato> identificaBeneficiados(vector<Candidato> & candEleitos, vector<Candidato> & maisVotados);

        vector<Candidato> identificaNaoEleitos(vector<Candidato> & candEleitos, vector<Candidato> & maisVotados);

        void analisaVotosPartidos(vector<Partido> & p, vector<Candidato> & candValidos);

        void identificaEleitosPartidos(vector<Partido> & p, vector<Candidato> & candEleitos);

        vector<Candidato> identificaPrimeirosPartido(vector<Partido> & p, vector<Candidato> & candValidos);

        vector<Candidato> identificaUltimosPartido(vector<Partido> & p, vector<Candidato> & candValidos, vector<Candidato> & prim);

        vector<int> retornaIdades(vector<Candidato> & candEleitos, string data);

        vector<int> retornaSexos(vector<Candidato> & candEleitos);

        vector<int> retornaVotos(vector<Partido> & partidos);

    private:
        
};

#endif