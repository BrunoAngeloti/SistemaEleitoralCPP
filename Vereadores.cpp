#include <iostream>
#include "Candidato.h"
#include "Partido.h"

//#include "Informacoes.h"
//#include "Inout.h"

int main(int argc, char* argv[]){
    Partido* part1 = new Partido(15, 150, "Partido Dos Trabalhadores", "PT");
    Partido* part2 = new Partido(65, 123, "Movimento Democrático Brasileiro", "MDB");

    Candidato* cand1 = new Candidato(59, 475, "Eleito", "Bruno Angeloti", "Brunin de JP", 'I', "11/11/2001", "Válido", 15);
    Candidato* cand2 = new Candidato(85, 538, "Eleito", "Victoria Louzada", "Vivi do RJ", 'F', "05/01/2001", "Válido", 65);

    cout << "Partido: " << part1->getNome_partido() << ", Votos: " << part1->getVotos_legenda() << "\n";
    cout << "Partido: " << part2->getNome_partido() << ", Votos: " << part2->getVotos_legenda() << "\n\n";

    cout << "Candidato: " << cand1->getNome() << ", Nascimento: " << cand1->getData_nasc() << "\n";
    cout << "Candidata: " << cand2->getNome() << ", Nascimento: " << cand2->getData_nasc() << "\n\n";

    int t = cand1->retornaIdadeCandidato("11/11/2021");
    cout << "Idade Bruno: " << t << "\n\n";
    
}