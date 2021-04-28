#include "Partido.h"
#include <iostream>

Partido::Partido(list<string> lista){
    vector<string> aux(lista.begin(), lista.end());
    setNumero_partido(stoi(aux[0]));
    setVotos_legenda(stoi(aux[1]));
    setNome_partido(aux[2]);
    setSigla_partido(aux[3]);  
    setVotos_nominais(0);
    setVotos_total(0);
    setCand_eleitos(0);
}

int Partido::getNumero_partido() {
    return this->numero_partido;
}
void Partido::setNumero_partido(int numero_partido) {
    this->numero_partido = numero_partido;
}
int Partido::getVotos_legenda() {
    return this->votos_legenda;
}
void Partido::setVotos_legenda(int votos_legenda) {
    this->votos_legenda = votos_legenda;
}
string Partido::getNome_partido() {
    return this->nome_partido;
}
void Partido::setNome_partido(string nome_partido) {
    this->nome_partido = nome_partido;
}
string Partido::getSigla_partido() {
    return this->sigla_partido;
}
void Partido::setSigla_partido(string sigla_partido) {
    this->sigla_partido = sigla_partido;
}
int Partido::getVotos_total() {
    return this->votos_total;
}
void Partido::setVotos_total(int votos_total) {
    this->votos_total = this->votos_nominais + this->votos_legenda + votos_total;
}
int Partido::getVotos_nominais() {
    return this->votos_nominais;
}
void Partido::setVotos_nominais(int votos_nominais) {
    this->votos_nominais = votos_nominais;
}
int Partido::getCand_eleitos() {
    return this->cand_eleitos;
}
void Partido::setCand_eleitos(int cand_eleitos) {
    this->cand_eleitos = cand_eleitos;
}


bool Partido::comparaPartido(int numeroId){
    if(this->numero_partido == numeroId){
        return true;
    }
    return false;
}

void Partido::imprimePartido(){
    cout 
    << this->getNome_partido() 
    << ", " 
    << this->getNumero_partido() 
    << ", " 
    << this->getSigla_partido() 
    << ", " 
    << this->getVotos_legenda() 
    << endl;
}

