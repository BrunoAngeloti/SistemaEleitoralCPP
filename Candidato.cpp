#include "Candidato.h"
#include <iostream>

Candidato::Candidato(list<string> lista){
    
    vector<string> aux(lista.begin(), lista.end());
    setNumero(stoi(aux[0]));

    setVotos_nominais(stoi(aux[1]));

    setSituacao(aux[2]);
    
    setNome(aux[3]);

    setNome_urna(aux[4]);

    setSexo(aux[5]);

    setData_nasc(aux[6]);
    
    setDestino_voto(aux[7]);
    
    setNumero_partido(stoi(aux[8]));
}

string Candidato::getNome(){
    return nome;
} 
void Candidato::setNome(string nome){
    this->nome = nome;
}

string Candidato::getSexo(){
    return sexo;
}
void Candidato::setSexo(string sexo){
    this->sexo = sexo;
} 

string Candidato::getData_nasc(){
    return data_nasc;
} 
void Candidato::setData_nasc(string data_nasc){
    this->data_nasc = data_nasc;
} 

int Candidato::getNumero(){
    return numero;
}
void Candidato::setNumero(int numero){
    this->numero = numero;
}

int Candidato::getNumero_partido(){
    return numero_partido;
}
void Candidato::setNumero_partido(int numero_partido){
    this->numero_partido = numero_partido;
}

int Candidato::getVotos_nominais(){
    return votos_nominais;
} 
void Candidato::setVotos_nominais(int votos_nominais){
    this->votos_nominais = votos_nominais;
}

string Candidato::getSituacao(){
    return situacao;
} 
void Candidato::setSituacao(string situacao){
    this->situacao = situacao;
}

string Candidato::getNome_urna(){
    return nome_urna;
} 
void Candidato::setNome_urna(string nome_urna){
    this->nome_urna = nome_urna;
} 

string Candidato::getDestino_voto(){
    return destino_voto;
} 
void Candidato::setDestino_voto(string destino_voto){
    this->destino_voto = destino_voto;
}

bool Candidato::identificaEleitos(){
    return (this->getSituacao() == "Eleito");
}

bool Candidato::identificaValidade(){
    return (this->getDestino_voto() == "Válido");
}

//------------------- MÉTODO DE COMPARAÇÃO PELO NÚMERO DO PARTIDO ------------------
bool Candidato::comparaNumPartido(int numeroId){
    if(this->numero_partido == numeroId){
        return true;
    }
    return false;
}

//------------------- MÉTODO PARA RETORNAR IDADE DO CANDIDATO ------------------
int Candidato::retornaIdadeCandidato(string dataRef){
    string dataCand[3];
    string dataAtual[3];

    dataCand[0] = (this->data_nasc).substr(0,2);
    dataCand[1] = (this->data_nasc).substr(3,2);
    dataCand[2] = (this->data_nasc).substr(6);
    
    dataAtual[0] = (dataRef).substr(0,2);
    dataAtual[1] = (dataRef).substr(3,2);
    dataAtual[2] = (dataRef).substr(6);

    if(stoi(dataCand[1]) < stoi(dataAtual[1])){
        return (stoi(dataAtual[2]) - stoi(dataCand[2]));
    }else if(stoi(dataCand[1]) == stoi(dataAtual[1]) && stoi(dataCand[0]) <= stoi(dataAtual[0])){
        return (stoi(dataAtual[2]) - stoi(dataCand[2]));
    }else{
        return (stoi(dataAtual[2]) - stoi(dataCand[2]) - 1);
    }
        
}

void Candidato::imprimeCandidato(){
    cout 
    << this->getNome() 
    << ", " 
    << this->getNumero_partido() 
    << ", " 
    << this->getData_nasc() 
    << ", " 
    << this->getSexo() 
    << endl;
}

/*/------------------- MÉTODOS DE IMPRESSÃO TOSTRING ------------------

    public String toString(Partido[] part){
        for(int i = 0; i < part.length; i++){
            if(part[i].comparaPartido(this.numero_partido)){
                String print = this.getNome() + " / " + this.getNome_urna() + " (" + part[i].getSigla_partido() + ", " + Integer.toString(this.getVotos_nominais());
                StringBuilder s = new StringBuilder(print);
                if(this.getVotos_nominais() <= 1){
                    s.append(" voto)"); // caso seja no singular
                }
                else{
                    s.append(" votos)"); // caso seja no plural
                }
                print = s.toString();
                return print;
            }
        }
        return "erro";
    }

    public String toString(Partido[] part, String nome, int num, int votos){
        for(int i = 0; i < part.length; i++){
            if(part[i].comparaPartido(this.numero_partido)){  
                String print = part[i].getSigla_partido() + " - " + this.getNumero_partido() + ", " + this.getNome_urna() + " (" + this.getNumero() + ", " + this.getVotos_nominais();
                StringBuilder s = new StringBuilder(print);
                if(this.getVotos_nominais() <= 1){
                    s.append(" voto) / " + nome + " (" + num + ", " + votos); // caso seja no singular
                }
                else{
                    s.append(" votos) / " + nome + " (" + num + ", " + votos); // caso seja no plural
                }
                
                if(votos <= 1){
                    s.append(" voto)"); // caso seja no singular
                }
                else{
                    s.append(" votos)"); // caso seja no plural
                }
                
                print = s.toString();
                return print;
            }
        }
        return "erro";
    }
    */


 /*//------------------- MÉTODO DE COMPARAÇÃO PARA O ARRAYS.SORT ------------------

    @Override
    public int compareTo(Candidato cand) {
        if(cand != null){
            String[] dataCand1 = new String[3];
            String[] dataCand2 = new String[3];
            
            dataCand1 = this.data_nasc.split("/");
            dataCand2 = cand.getData_nasc().split("/");
            
            if(this.votos_nominais > cand.getVotos_nominais()){
                return -1;
            }
            else if(this.votos_nominais < cand.getVotos_nominais()){
                return 1;
            }
            else{
                // Em caso de empate, o candidato mais velho terá prioridade 
                if(Integer.parseInt(dataCand1[2]) < Integer.parseInt(dataCand2[2])){ // retorna -1, o cand1 é mais velho
                    return -1;
                }
                else if(Integer.parseInt(dataCand1[2]) > Integer.parseInt(dataCand2[2])){ // retorna 1, o cand2 é o mais velho
                    return 1;
                }
                else{
                    if(Integer.parseInt(dataCand1[1]) < Integer.parseInt(dataCand2[1])){ // retorna -1, o cand1 é mais velho
                        return -1;
                    }
                    else if(Integer.parseInt(dataCand1[1]) > Integer.parseInt(dataCand2[1])){ // retorna 1, o cand2 é o mais velho
                        return 1;
                    }
                    else{
                        if(Integer.parseInt(dataCand1[0]) < Integer.parseInt(dataCand2[0])){ // retorna -1, o cand1 é mais velho
                            return -1;
                        }
                        else if(Integer.parseInt(dataCand1[0]) > Integer.parseInt(dataCand2[0])){ // retorna 1, o cand2 é o mais velho
                            return 1;
                        }
                        else{
                            // Caso eles tiverem a mesma idade, número do candidato irá desempatar
                            if(this.getNumero() < cand.getNumero()){
                                return -1;
                            }
                            else{
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }*/