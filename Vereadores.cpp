#include <iostream>
#include <list>
#include <vector>
#include "Inout.h"
#include "Partido.h"
#include "Informacoes.h"
#include "Candidato.h"


int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Insira uma quantidade correta de argumentos!" << endl;
        cout << "./<executavel> <diretório arquivo candidatos> <diretório arquivo partidos> <data da eleição>" << endl;
        return 0;
    } 

    //------------------Leitura arquivos---------------------

    Inout in = Inout();
    Informacoes info = Informacoes();
    string fileCandidatos = argv[1];
    string filePartidos = argv[2];
    string dataEleicao = argv[3];

    // Chama método para ler os candidatos e os partidos
    vector<Candidato> candidatos = in.leCandidatos(fileCandidatos);
    vector<Partido> partidos = in.lePartidos(filePartidos);

    // Conta o número de candidatos eleitos
    int qtdEleitos = info.retornaQtdEleitos(candidatos);

    // Chama método para retornar candidatos validos
    vector<Candidato> candidatosValidos = info.retornaCandValidos(candidatos);

    // Organiza os candidatos válidos por ordem de mais votados
    candidatosValidos = info.ordenaCandidatos(candidatosValidos);


    //-------------------ANALISA CANDIDATOS--------------------

    // Os candidatos eleitos são separados em um vetor
    vector<Candidato> candidatosEleitos = info.retornaCandEleitos(candidatosValidos);

    // Os mais votados são separados em um vetor
    vector<Candidato> maisVotados = info.retornaCandsMaisVotados(candidatosValidos, qtdEleitos);

    // Os mais votados que não foram eleitos são separados em um vetor
    vector<Candidato> naoEleitos =  info.identificaNaoEleitos(candidatosEleitos, maisVotados);

    // Os eleitos que não foram os mais votados são separados em um vetor
    vector<Candidato> beneficiados = info.identificaBeneficiados(candidatosEleitos, maisVotados);


    //--------------ANALISA VOTOS PARTIDO---------------

    // Identifica o total de votos de cada partido
    partidos = info.analisaVotosPartidos(partidos, candidatosValidos);

    // Identifica quantos candidatos foram eleitos de cada partido
    partidos = info.identificaEleitosPartidos(partidos, candidatosEleitos);

    // Organiza os partidos por maior numero de votos no total
    partidos = info.ordenaPartidos(partidos);

    // Armazena o primeiro candidato de cada partido
    vector<Candidato> primeiros = info.identificaPrimeirosPartido(partidos, candidatosValidos);

    // Organiza os primeiros candidatos dos partidos por maior numero de votos nominais
    primeiros = info.ordenaCandidatosNumPartido(primeiros);

    // Armazena o ultimo candidato de cada partido
    vector<Candidato> ultimos = info.identificaUltimosPartido(partidos, candidatosValidos, primeiros);


    //------------------------CALCULOS DE IDADES, GÊNEROS E VOTOS------------------------

    vector<int> idades = info.retornaIdades(candidatosEleitos, dataEleicao);
    vector<int> sexos = info.retornaSexos(candidatosEleitos);
    vector<int> votos= info.retornaVotos(partidos);


    //------------------------IMPRESSÕES DO CÓDIGO-------------------------

    in.imprimeRelatorios(
        qtdEleitos, candidatosEleitos, partidos, maisVotados, 
        naoEleitos, candidatosValidos, beneficiados, primeiros, ultimos
    );
            
    
}