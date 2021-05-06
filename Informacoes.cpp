#include "Informacoes.h"
#include <iostream>
#include <algorithm>

//Método privado de ordenação dos partidos por numero de votos e desempate por numero do partido
bool Informacoes::ordenaVotosPartidos(const Partido& A, const Partido& B) {
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

//Método privado de ordenação dos candidatos por numero de votos e desempate por idade
bool Informacoes::ordenaVotosCandidatos(const Candidato& A, const Candidato& B) {

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

//Método privado de ordenação dos candidatos por numero de votos e desempate por numero do partido
bool Informacoes::ordenaVotosCandidatos2(const Candidato& A, const Candidato& B) {
    if(A.getVotos_nominais() > B.getVotos_nominais()){
        return true; 
    }
    else if(A.getVotos_nominais() < B.getVotos_nominais()){
        return false;
    }else{
        //Em caso de empate, o menor numero partidário terá prioridade
        if(A.getNumero_partido() < B.getNumero_partido()){
            return true;
        }else{
            return false;
        }
    }
}


// ------------------ METODOS DE ORDENAÇÃO DE VETORES ------------------
void Informacoes::ordenaPartidos(vector<Partido> & partidos){
    sort(partidos.begin(), partidos.end(), ordenaVotosPartidos);
}

void Informacoes::ordenaCandidatos(vector<Candidato> & candidatos){
    sort(candidatos.begin(), candidatos.end(), ordenaVotosCandidatos);  
}

void Informacoes::ordenaCandidatosNumPartido(vector<Candidato> & candidatos){
    sort(candidatos.begin(), candidatos.end(), ordenaVotosCandidatos2);
}


// ------------------ METODOS DE RETORNO DE QUANTIDADES ESPECIFICAS ------------------
int Informacoes::retornaQtdEleitos(const vector<Candidato>& cand) const{ 
    int aux = 0; 
    for(int i = 0; i < cand.size(); i++){ 
        if(cand[i].identificaEleitos()){ 
            aux++;
        }
    }
    return aux;
}

int Informacoes::retornaQtdValidos(const vector<Candidato>& cand) const{ 
    int aux = 0;
    for(int i = 0; i < cand.size(); i++){ 
        if(cand[i].identificaValidade()){ 
            aux++;
        }
    }
    return aux;
}

int Informacoes::retornaQtdBeneficiados(const vector<Candidato>& candEleitos, const vector<Candidato>& maisVotados) const{
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
vector<Candidato> Informacoes::retornaCandValidos(const vector<Candidato>& cand) const{
    vector<Candidato> candValidos;
    for(int i = 0, j = 0; i < cand.size(); i++){ 
        if(cand[i].identificaValidade()){ 
            candValidos.push_back(cand[i]);
            j++;
        }       
    }
    return candValidos;
}

vector<Candidato> Informacoes::retornaCandEleitos(const vector<Candidato>& candValidos) const{
    vector<Candidato> candEleitos;
    for(int i = 0, j = 0; i < candValidos.size(); i++){ 
        if(candValidos[i].identificaEleitos()){ 
            candEleitos.push_back(candValidos[i]);
            j++;
        }
    }
    return candEleitos;
}

vector<Candidato> Informacoes::retornaCandsMaisVotados(const vector<Candidato>& candValidos, const int qtdEleitos) const{
    vector<Candidato> maisVotados;
    for(int i = 0; i < qtdEleitos; i++){ 
        maisVotados.push_back(candValidos[i]);
    }
    return maisVotados;
}

vector<Candidato> Informacoes::identificaBeneficiados(const vector<Candidato>& candEleitos, const vector<Candidato>& maisVotados) const{
    vector<Candidato> beneficiados;
    for(int i = 0; i < candEleitos.size(); i++){
        for(int j = 0; j < candEleitos.size(); j++){
            // Caso o candidato se encontrar em ambas as listas, ele foi eleito e é mais votado
            if(maisVotados[j].getNome() == candEleitos[i].getNome()){                  
                break;
            }
            //Caso chegue no final dos 2 fors e ele não foi encontrado, ele é um candidato não foi o mais votado mas foi eleito
            if(j == (candEleitos.size() - 1)) {
                beneficiados.push_back(candEleitos[i]);       
            }                   
        }          
    }
    return beneficiados;
}

vector<Candidato> Informacoes::identificaNaoEleitos(const vector<Candidato>& candEleitos, const vector<Candidato>& maisVotados) const{
    vector<Candidato> naoEleitos;

    for(int i = 0; i < candEleitos.size(); i++){
        for(int j = 0; j < candEleitos.size(); j++){
            //Caso o candidato se encontrar em ambas as listas, ele foi eleito e é mais votado
            if(maisVotados[i].getNome() == candEleitos[j].getNome()){
                break;
            }
            //Caso chegue no final dos 2 fors e ele não foi encontrado, ele é um candidato mais votado e não eleito
            if(j == (candEleitos.size() - 1)) {
                naoEleitos.push_back(maisVotados[i]);
            }                   
        }       
    }
    return naoEleitos; 
}

void Informacoes::analisaVotosPartidos(vector<Partido>& p, vector<Candidato>& candValidos){
    for(int i = 0; i < p.size(); i++){
        int total = 0;
        for(int j = 0; j < candValidos.size(); j++){
            if(p[i].comparaPartido(candValidos[j].getNumero_partido())){// caso o candidato seja do partido em questão
                total = total + candValidos[j].getVotos_nominais(); //os votos dele são somados ao partido                
            }
        }
        p[i].setVotos_nominais(total);
        p[i].setVotos_total(total);
    }
}

void Informacoes::identificaEleitosPartidos(vector<Partido>& p, vector<Candidato>& candEleitos){
    for(int i = 0; i < p.size(); i++){
        int eleitos = 0;
        for(int j = 0; j < candEleitos.size(); j++){ 
            if(p[i].comparaPartido(candEleitos[j].getNumero_partido())){
                eleitos++;
            }
        }
        p[i].setCand_eleitos(eleitos);
    }
}

vector<Candidato> Informacoes::identificaPrimeirosPartido(const vector<Partido>& p, const vector<Candidato>& candValidos) const{
    vector<Candidato> primeiros;
    for(int i = 0; i < p.size(); i++){
        bool naoValido = true;
        for(int j = 0; j < candValidos.size(); j++){
            if(p[i].comparaPartido(candValidos[j].getNumero_partido())){
                primeiros.push_back(candValidos[j]);  
                naoValido = false;
                break;       
            }
        }
        // Caso nao encontrar um candidato válido do partido, setar candidato como nullo
        if(naoValido){
            list<string>aux;  
            aux.push_back("0");
            aux.push_back("0");
            aux.push_back("\0");
            aux.push_back("\0");
            aux.push_back("\0");
            aux.push_back("n");
            aux.push_back("\0");
            aux.push_back("\0");
            aux.push_back(to_string(p[i].getNumero_partido()));
            Candidato cand = Candidato(aux);
            primeiros.push_back(cand);
        }
    }
    return primeiros;
}

vector<Candidato> Informacoes::identificaUltimosPartido(const vector<Partido>& p, const vector<Candidato>& candValidos, const vector<Candidato>& prim) const{
    vector<Candidato> ultimos;

    for(int i = 0; i < p.size(); i++){
        bool naoValido = true;
        for(int j = (candValidos.size() - 1); j >= 0; j--){               
            if(prim[i].comparaNumPartido(candValidos[j].getNumero_partido())){                      
                ultimos.push_back(candValidos[j]); 
                naoValido = false;
                break;     
            }                          
        }
        // Caso nao encontrar um candidato válido do partido, setar candidato como nullo
        if(naoValido){  
            list<string>aux;  
            aux.push_back("0");
            aux.push_back("0");
            aux.push_back("\0");
            aux.push_back("\0");
            aux.push_back("\0");
            aux.push_back("n");
            aux.push_back("\0");
            aux.push_back("\0");
            aux.push_back(to_string(p[i].getNumero_partido()));
            Candidato cand = Candidato(aux);
            ultimos.push_back(cand);
        }
    }
    return ultimos;
}


// ---------------- MÉTODOS PARA RETORNAR IDADES, SEXOS E O NUMERO DE VOTOS TOTAL -----------------
vector<int> Informacoes::retornaIdades(const vector<Candidato>& candEleitos, const string& data) const{
    vector<int> idades = {0, 0, 0, 0, 0};

    for(int i=0; i<candEleitos.size(); i++){
        int idade = candEleitos[i].retornaIdadeCandidato(data);
        if(idade < 30){
            idades[0]++; // MENORES DE 30
        }else if(idade >= 30 && idade < 40){
            idades[1]++; // MAIORES DE 30 E MENORES DE 40
        }else if(idade >= 40 && idade < 50){
            idades[2]++; // MAIORES DE 40 E MENORES DE 50
        }else if(idade >= 50 && idade < 60){
            idades[3]++; // MAIORES DE 50 E MENORES DE 60
        }else if(idade >= 60){
            idades[4]++; // MAIORES DE 60
        }
    }
    return idades; 
}

vector<int> Informacoes::retornaSexos(const vector<Candidato> & candEleitos) const{
    vector<int> sexos = {0, 0};
    for(int i=0; i<candEleitos.size(); i++){
        if(candEleitos[i].getSexo() == "M"){
            sexos[0]++; // MASCULINO
        }else{
            sexos[1]++; // FEMININO
        }
    }
    return sexos;
}

vector<int> Informacoes::retornaVotos(const vector<Partido> & partidos) const{
    vector<int> votos = {0, 0, 0};
    for(int i=0; i<partidos.size(); i++){
        votos[2] = votos[2] + partidos[i].getVotos_legenda(); // Total votos legenda
        votos[1] = votos[1] + partidos[i].getVotos_nominais(); // Total votos nominais        
    }
    votos[0] = votos[1] + votos[2]; // Total de votos

    return votos;
}