#include "Partido.h"
#include <iostream>

Partido::Partido(int numero_partido, int votos_legenda, string nome_partido, string sigla_partido){
    this->numero_partido = numero_partido;
    this->votos_legenda = votos_legenda;
    this->nome_partido = nome_partido;
    this->sigla_partido = sigla_partido;
    this->votos_total = 0;
    this->votos_nominais = 0;
    this->cand_eleitos = 0;
}