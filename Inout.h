#ifndef INOUT_H_
#define INOUT_H_

#include <string>	
#include <vector>
#include "Partido.h"
#include "Candidato.h"	
using namespace std;

class Inout{
    public:
        vector<Partido> lePartidos(const string& arq);     
        vector<Candidato> leCandidatos(const string& arq);

        void imprimeRelatorios(
            int qtdEleitos, 
            const vector<Candidato>& candidatosEleitos, 
            const vector<Partido>& partidos, 
            const vector<Candidato>& maisVotados, 
            const vector<Candidato>& naoEleitos,
            const vector<Candidato>& candidatosValidos, 
            const vector<Candidato>& beneficiados,
            const vector<Candidato>& primeiros, 
            const vector<Candidato>& ultimos
        ) const;
        void imprimeIdadeSexoVoto(const vector<int>& idades, const vector<int>& sexos, const vector<int>& votos, const int qtdEleitos) const;
    private:
        void imprimeNumVagas(int qtdEleitos) const;
        void imprimeVereadoresEleitos(const vector<Candidato>& candidatosEleitos, const vector<Partido>& partidos) const;
        void imprimeMaisVotados(const vector<Candidato>& maisVotados, const vector<Partido>& partidos) const;
        void imprimeNaoEleitos(const vector<Candidato>& maisVotados, const vector<Candidato>& naoEleitos, const vector<Partido>& partidos) const;
        void imprimeBeneficiados(const vector<Candidato>& candValidos, const vector<Candidato>& beneficiados, const vector<Partido>& partidos) const;
        void imprimePartidos(const vector<Partido> & partidos) const;
        void imprimePrimUlt(const vector<Candidato>& primeiros, const vector<Candidato>& ultimos, const vector<Partido>& partidos) const;
        string formataSaidaDouble(const double num) const;
};

#endif