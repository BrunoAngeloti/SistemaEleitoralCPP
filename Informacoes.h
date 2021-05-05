#ifndef INFORMACOES_H_
#define INFORMACOES_H_
#include "Partido.h"
#include "Candidato.h"
using namespace std;

class Informacoes{
    public:
        void ordenaPartidos(vector<Partido>& partidos);

        void ordenaCandidatos(vector<Candidato>& candidatos);

        void ordenaCandidatosNumPartido(vector<Candidato>& candidatos);

        int retornaQtdEleitos(const vector<Candidato>& cand) const;

        int retornaQtdValidos(const vector<Candidato>& cand) const;

        int retornaQtdBeneficiados(const vector<Candidato>& candEleitos, const vector<Candidato>& maisVotados) const;

        vector<Candidato> retornaCandValidos(const vector<Candidato>& cand) const;

        vector<Candidato> retornaCandEleitos(const vector<Candidato>& candValidos) const; 

        vector<Candidato> retornaCandsMaisVotados(const vector<Candidato>& candValidos, const int qtdEleitos) const;

        vector<Candidato> identificaBeneficiados(const vector<Candidato>& candEleitos, const vector<Candidato>& maisVotados) const;

        vector<Candidato> identificaNaoEleitos(const vector<Candidato>& candEleitos, const vector<Candidato>& maisVotados) const;

        void analisaVotosPartidos(vector<Partido>& p, vector<Candidato>& candValidos);

        void identificaEleitosPartidos(vector<Partido>& p, vector<Candidato>& candEleitos);

        vector<Candidato> identificaPrimeirosPartido(const vector<Partido>& p, const vector<Candidato>& candValidos) const;

        vector<Candidato> identificaUltimosPartido(const vector<Partido>& p, const vector<Candidato>& candValidos, const vector<Candidato>& prim) const;

        vector<int> retornaIdades(const vector<Candidato>& candEleitos, const string& data) const;

        vector<int> retornaSexos(const vector<Candidato>& candEleitos) const;

        vector<int> retornaVotos(const vector<Partido>& partidos) const;

    private:
        
};

#endif