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

int Partido::getNumero_partido() const{
    return this->numero_partido;
}
void Partido::setNumero_partido(int numero_partido) {
    this->numero_partido = numero_partido;
}

int Partido::getVotos_legenda() const{
    return this->votos_legenda;
}
void Partido::setVotos_legenda(int votos_legenda) {
    this->votos_legenda = votos_legenda;
}

string Partido::getNome_partido() const{
    return this->nome_partido;
}
void Partido::setNome_partido(string nome_partido) {
    this->nome_partido = nome_partido;
}

string Partido::getSigla_partido() const{
    return this->sigla_partido;
}
void Partido::setSigla_partido(string sigla_partido) {
    this->sigla_partido = sigla_partido;
}

int Partido::getVotos_total() const{
    return this->votos_total;
}
void Partido::setVotos_total(int votos_total) {
    this->votos_total = this->votos_nominais + this->votos_legenda;
}

int Partido::getVotos_nominais() const{
    return this->votos_nominais;
}
void Partido::setVotos_nominais(int votos_nominais) {
    this->votos_nominais = votos_nominais;
}

int Partido::getCand_eleitos() const{
    return this->cand_eleitos;
}
void Partido::setCand_eleitos(int cand_eleitos) {
    this->cand_eleitos = cand_eleitos;
}

//Método para comparar partido com o numero passado
bool Partido::comparaPartido(const int numeroId) const{
    if(this->numero_partido == numeroId){
        return true;
    }
    return false;
}

//Método para imprimir partido
void Partido::imprimePartido() const{
    cout << this->sigla_partido << " - " << this->numero_partido << ", " << this->votos_total;
          
        if(this->getVotos_total() <= 1){
           cout << " voto ("; // caso seja no singular
        }
        else{
            cout << " votos ("; // caso seja no plural
        }

        cout << this->getVotos_nominais();

        if(this->getVotos_nominais() <= 1){
            cout << " nominal e "; // caso seja no singular
        }
        else{
            cout << " nominais e "; // caso seja no plural
        }

        cout << this->getVotos_legenda() << " de legenda), " << this->getCand_eleitos();

        if(this->getCand_eleitos() <= 1){
            cout << " candidato eleito"; // caso seja no singular
        }
        else{
            cout << " candidatos eleitos"; // caso seja no plural
        }

        cout << endl;
        
}

