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