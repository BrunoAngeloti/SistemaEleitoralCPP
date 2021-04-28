#include <iostream>
#include <list>
#include <vector>
#include "Inout.h"
#include "Candidato.h"
#include "Partido.h"

//#include "Informacoes.h"


int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Insira um arquivo de entrada!" << endl;
        return 0;
    } 

    Inout* in = new Inout();

    vector<Partido> listaPartidos = in->lePartidos(argv[1]);
    vector<Candidato> listaCandidatos = in->leCandidatos(argv[2]);

    for(auto partido : listaPartidos)
        partido.imprimePartido();

    cout << "\n\n\n";
    
    for(auto candidato : listaCandidatos)
        candidato.imprimeCandidato();
             
    delete(in);
    

    /*

    Candidato* cand1 = new Candidato(59, 475, "Eleito", "Bruno Angeloti", "Brunin de JP", 'I', "11/11/2001", "Válido", 15);
    Candidato* cand2 = new Candidato(85, 538, "Eleito", "Victoria Louzada", "Vivi do RJ", 'F', "05/01/2001", "Válido", 65);

    cout << "Partido: " << part1->getNome_partido() << ", Votos: " << part1->getVotos_legenda() << "\n";
    cout << "Partido: " << part2->getNome_partido() << ", Votos: " << part2->getVotos_legenda() << "\n\n";

    cout << "Candidato: " << cand1->getNome() << ", Nascimento: " << cand1->getData_nasc() << "\n";
    cout << "Candidata: " << cand2->getNome() << ", Nascimento: " << cand2->getData_nasc() << "\n\n";

    int t = cand1->retornaIdadeCandidato("11/11/2021");
    cout << "Idade Bruno: " << t << "\n\n";*/
    
}