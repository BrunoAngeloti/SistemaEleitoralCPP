#include "Candidato.h"
#include <iostream>

Candidato::Candidato(int numero, int votos_nominais, string situacao, string nome, string nome_urna, char sexo, string data_nasc, string destino_voto, int numero_partido){
    this->numero = numero;
    this->votos_nominais = votos_nominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nome_urna = nome_urna;
    this->sexo = sexo;
    this->data_nasc = data_nasc;
    this->destino_voto = destino_voto;
    this->numero_partido = numero_partido;
}