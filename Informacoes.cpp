#include "Informacoes.h"
#include <iostream>
#include <algorithm>

bool ordenaVotosPartidos(Partido A, Partido B){
    if(A.getVotos_total() > B.getVotos_total()){
        return true;
    } 
    else if(A.getVotos_total() < B.getVotos_total()){
        return false;
    }else{
        
        if(A.getNumero_partido() < B.getNumero_partido()){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

bool ordenaVotosCandidatos(Candidato A, Candidato B){

    string dataCand1[3];
    string dataCand2[3];

    dataCand1[0] = (A.getData_nasc()).substr(0,2);
    dataCand1[1] = (A.getData_nasc()).substr(3,2);
    dataCand1[2] = (A.getData_nasc()).substr(6);
    
    dataCand2[0] = (B.getData_nasc()).substr(0,2);
    dataCand2[1] = (B.getData_nasc()).substr(3,2);
    dataCand2[2] = (B.getData_nasc()).substr(6);



    if(A.getVotos_nominais() > B.getVotos_nominais()){
        return true;
    }
    else if(A.getVotos_nominais() < B.getVotos_nominais()){
        return false;
    }else{
        // Em caso de empate, o candidato mais velho terá prioridade 
                if(stoi(dataCand1[2]) < stoi(dataCand2[2])){ // retorna -1, o cand1 é mais velho
                    return true;
                }
                else if(stoi(dataCand1[2]) > stoi(dataCand2[2])){ // retorna 1, o cand2 é o mais velho
                    return false;
                }
                else{
                    if(stoi(dataCand1[1]) < stoi(dataCand2[1])){ // retorna -1, o cand1 é mais velho
                        return true;
                    }
                    else if(stoi(dataCand1[1]) > stoi(dataCand2[1])){ // retorna 1, o cand2 é o mais velho
                        return false;
                    }
                    else{
                        if(stoi(dataCand1[0]) < stoi(dataCand2[0])){ // retorna true, o cand1 é mais velho
                            return true;
                        }
                        else if(stoi(dataCand1[0]) > stoi(dataCand2[0])){ // retorna 1, o cand2 é o mais velho
                            return false;
                        }
                        else{
                            // Caso eles tiverem a mesma idade, número do candidato irá desempatar
                            if(A.getNumero() < B.getNumero()){
                                return true;
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
    }
}

vector<Partido> Informacoes::ordenaPartidos(vector<Partido> partidos){
    sort(partidos.begin(), partidos.end(), ordenaVotosPartidos);
    return partidos;
}

vector<Candidato> Informacoes::ordenaCandidatos(vector<Candidato> candidatos){
    sort(candidatos.begin(), candidatos.end(), ordenaVotosCandidatos);
    return candidatos;
}


// ------------------ METODOS DE RETORNO DE QUANTIDADES ESPECIFICAS ------------------
int Informacoes::retornaQtdEleitos(vector<Candidato> cand){ 
    int aux = 0; 
    for(int i = 0; i < cand.size(); i++){ 
        if(cand[i].identificaEleitos()){ 
            aux++;
        }
    }
    return aux;
}

int Informacoes::retornaQtdValidos(vector<Candidato> cand){ 
    int aux = 0;
    for(int i = 0; i < cand.size(); i++){ 
        if(cand[i].identificaValidade()){ 
            aux++;
        }
    }
    return aux;
}

int Informacoes::retornaQtdBeneficiados(vector<Candidato> candEleitos, vector<Candidato> maisVotados){
    int aux = 0;
    for(int i = 0; i < candEleitos.size(); i++){
        for(int j = 0; j < candEleitos.size(); j++){
            // Se o candidato está presente nas duas listas
            if(maisVotados[j].getNome() == candEleitos[i].getNome()){              
                break; 
            }
            // Se chega no final do for, significa que o candidato eleito não está nos mais votados
            if(j == candEleitos.size() - 1) { 
                aux++;  // logo ele foi não foi beneficiado e soma 1
            }                   
        }          
    }
    return aux;
}


    // ---------------- MÉTODOS PARA RETORNAR VETORES DE CANDIDATOS ESPECIFICOS -----------------
vector<Candidato> Informacoes::retornaCandValidos(vector<Candidato> cand) {
    vector<Candidato> candValidos;//[this->retornaQtdValidos(cand)];
    for(int i = 0, j = 0; i < cand.size(); i++){ 
        if(cand[i].identificaValidade()){ 
            candValidos.push_back(cand[i]);
            j++;
        }
    }
    return candValidos;
}

/*
  vector<Candidato> Informacoes::retornaCandEleitos(vector<Candidato> candValidos, int qtdEleitos) {
        vector<Candidato> candEleitos = new Candidato[qtdEleitos];
        for(int i = 0, j = 0; i < candValidos.size(); i++){ 
            if(candValidos[i].identificaEleitos()){ 
                candEleitos[j] = candValidos[i];
                j++;
            }
        }
        return candEleitos;
    }

vector<Candidato> Informacoes::retornaCandsMaisVotados(vector<Candidato> candValidos, int qtdEleitos) {
        vector<Candidato> maisVotados = new Candidato[qtdEleitos];
        for(int i = 0; i < qtdEleitos; i++){ 
            maisVotados[i] = candValidos[i];
        }
        return maisVotados;
    }

vector<Candidato> Informacoes::identificaBeneficiados(vector<Candidato> candEleitos, vector<Candidato> maisVotados){
       vector<Candidato> beneficiados = new Candidato[this.retornaQtdBeneficiados(candEleitos, maisVotados)];
        int k = 0;
        for(int i = 0; i < candEleitos.length; i++){
            for(int j = 0; j < candEleitos.length; j++){
                // Caso o candidato se encontrar em ambas as listas, ele foi eleito e é mais votado
                if(maisVotados[j].getNome().equals(candEleitos[i].getNome())){                  
                    break;
                }
                //Caso chegue no final dos 2 fors e ele não foi encontrado, ele é um candidato não foi o mais votado mas foi eleito
                if(j == (candEleitos.length - 1)) {
                    beneficiados[k] = candEleitos[i]; 
                    k++;  
                }                   
            }          
        }
        return beneficiados;
    }

   vector<Candidato> Informacoes::identificaNaoEleitos(vector<Candidato> candEleitos, vector<Candidato> maisVotados){
        vector<Candidato> naoEleitos = new Candidato[this.retornaQtdBeneficiados(candEleitos, maisVotados)];

        int k = 0;
        for(int i = 0; i < candEleitos.length; i++){
            for(int j = 0; j < candEleitos.length; j++){
                //Caso o candidato se encontrar em ambas as listas, ele foi eleito e é mais votado
                if(maisVotados[i].getNome().equals(candEleitos[j].getNome())){
                    break;
                }
                //Caso chegue no final dos 2 fors e ele não foi encontrado, ele é um candidato mais votado e não eleito
                if(j == (candEleitos.length - 1)) {
                    naoEleitos[k] = maisVotados[i];
                    k++; 
                }                   
            }       
        }
        return naoEleitos; 
    }*/
