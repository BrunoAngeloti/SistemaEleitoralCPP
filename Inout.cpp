#include "Inout.h"
#include <iostream>
#include <fstream>

vector<Partido> Inout::lePartidos(string arq){
    ifstream entrada;
    int cont = 0;
    bool fimArquivo = false;

    entrada.open(arq);

    list<Partido> listaPartidos;
    list<string> aux;

    string palavra;

    if(entrada.is_open()){
        while(entrada.good()){
            for(int i=0; i<3;i++){
                getline(entrada, palavra, ',');
                if(palavra == "\0"){
                    fimArquivo = true;
                    break;
                }
                aux.push_back(palavra); 
            }
            if(fimArquivo) break;
            getline(entrada, palavra, '\n');
            aux.push_back(palavra);

            // ----------------------------- 
            
            if(cont == 0) {
                cont++;
                aux.clear();
                continue;
            }

            Partido part = Partido(aux); 
            listaPartidos.push_back(part);

            aux.clear();
        }
    }else{
        cout << "Não foi possível abrir este arquivo" << endl;
    }
    
    entrada.close();
    vector<Partido> partidos(listaPartidos.begin(), listaPartidos.end());
    
    return partidos;
}

vector<Candidato> Inout::leCandidatos(string arq){
    ifstream entrada;
    int cont = 0;
    bool fimArquivo = false;

    entrada.open(arq);

    list<Candidato> listaCandidatos;
    list<string> aux;

    string palavra;

    if(entrada.is_open()){
        while(entrada.good()){
            for(int i=0; i<8;i++){
                getline(entrada, palavra, ',');
                if(palavra == "\0"){
                    fimArquivo = true;
                    break;
                }
                aux.push_back(palavra); 
            }
            if(fimArquivo) break;
            getline(entrada, palavra, '\n');
            aux.push_back(palavra);
            
            if(cont == 0) {
                cont++;
                aux.clear();
                continue;
            }

            Candidato cand = Candidato(aux); 
            listaCandidatos.push_back(cand);

            aux.clear();
        }
    }else{
        cout << "Não foi possível abrir este arquivo" << endl;
    }
    
    entrada.close();
    vector<Candidato> candidatos(listaCandidatos.begin(), listaCandidatos.end());
    
    return candidatos;
}

void Inout::imprimeNumVagas(int qtdEleitos){
    cout << "Número de vagas: " << qtdEleitos << "\n";
}
void Inout::imprimeVereadoresEleitos(vector<Candidato> candidatosEleitos, vector<Partido> partidos){
    cout << "Vereadores eleitos:" << endl;
    int i = 1;
    for(auto candidato : candidatosEleitos){
        cout << i << " - ";
        candidato.imprimeCandidatos(partidos);
        i++;
    }
    
}
void Inout::imprimeMaisVotados(vector<Candidato> maisVotados, vector<Partido>  partidos){
    cout << "\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl; 
    int i = 1;
    for(auto candidato : maisVotados){
        cout << i << " - ";
        candidato.imprimeCandidatos(partidos);
        i++;
    }     
    
}
void Inout::imprimeNaoEleitos(vector<Candidato> maisVotados, vector<Candidato> naoEleitos, vector<Partido> partidos){
    cout << "\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << endl;
    int i = 1;
    for(auto candidatoPrim : naoEleitos){
        for(auto candidatoSeg : maisVotados){
            if(candidatoSeg.getNome() == candidatoPrim.getNome()){
                cout << i << " - ";
                candidatoPrim.imprimeCandidatos(partidos);                
                break;
            }
            i++;
        } 
        i=1;
    } 
}
void Inout::imprimeBeneficiados(vector<Candidato> candValidos, vector<Candidato> beneficiados, vector<Partido> partidos){
    cout << "\nEleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;
    int i = 1;
    for(auto beneficiados : beneficiados){
        for(auto validos : candValidos){
            if(validos.getNome() == beneficiados.getNome()){
                cout << i << " - ";
                beneficiados.imprimeCandidatos(partidos);                
                break;
            }
            i++;
        } 
        i=1;
    } 
}
void Inout::imprimePartidos(vector<Partido> partidos){
    cout << "\nVotação dos partidos e número de candidatos eleitos:" << endl;
    int i = 1;
    for(auto partido : partidos){
        cout << i << " - ";
        partido.imprimePartido();
        i++;
    }
    
}
void Inout::imprimePrimUlt(vector<Candidato> primeiros, vector<Candidato> ultimos, vector<Partido> partidos){
    cout << "\nPrimeiro e último colocados de cada partido:" << endl;
    
    for(int m = 0, n = 1; m < primeiros.size(); m++){
        int numPartido = primeiros[m].getNumero_partido();
        for(int i = 0; i < partidos.size(); i++){
            if(partidos[i].comparaPartido(numPartido)){
                break;
            }
        }
        if(primeiros[m].getSexo() != "n" && ultimos[m].getSexo() != "n"){      
            cout << n << " - ";
            primeiros[m].imprime(partidos, ultimos[m].getNome_urna(), ultimos[m].getNumero(), ultimos[m].getVotos_nominais());
            n++;      
        }else if(primeiros[m].getSexo() != "n" && ultimos[m].getSexo() == "n"){
            cout << n << " - ";
            primeiros[m].imprime(partidos, primeiros[m].getNome_urna(), primeiros[m].getNumero(), primeiros[m].getVotos_nominais());
            n++;  
        }else if(primeiros[m].getSexo() == "n" && ultimos[m].getSexo() != "n"){
            cout << n << " - ";
            ultimos[m].imprime(partidos, ultimos[m].getNome_urna(), ultimos[m].getNumero(), ultimos[m].getVotos_nominais());
            n++;  
        }     
    } 
}

void Inout::imprimeRelatorios(
    int qtdEleitos, 
    vector<Candidato> candidatosEleitos, 
    vector<Partido> partidos, 
    vector<Candidato> maisVotados, 
    vector<Candidato> naoEleitos,
    vector<Candidato> candidatosValidos, 
    vector<Candidato> beneficiados,
    vector<Candidato> primeiros, 
    vector<Candidato> ultimos
){
    this->imprimeNumVagas(qtdEleitos);
    this->imprimeVereadoresEleitos(candidatosEleitos, partidos);
    this->imprimeMaisVotados(maisVotados, partidos);
    this->imprimeNaoEleitos(maisVotados, naoEleitos, partidos);
    this->imprimeBeneficiados(candidatosValidos, beneficiados, partidos);
    this->imprimePartidos(partidos);
    this->imprimePrimUlt(primeiros, ultimos, partidos);
}