#include "Inout.h"
#include <iostream>
#include <locale>
#include <fstream>
#include <iomanip>
#include <sstream>

//Método para ler os partidos do arquivo
vector<Partido> Inout::lePartidos(const string& arq){
    ifstream entrada;
    list<Partido> listaPartidos;
    list<string> aux;
    string palavra;

    bool fimArquivo = false;
    entrada.open(arq);

    //Verifica se o arquivo foi aberto 
    if(entrada.is_open()){
        //Elimina a primeira linha do arquivo
        getline(entrada, palavra); 

        //Varre o arquivo até encontrar o final
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

            //Pega ultima palavra da linha
            getline(entrada, palavra, '\n');
            aux.push_back(palavra);

            //Chama o constructor do Partido enviando a lista com as caracteristicas
            Partido part = Partido(aux); 
            listaPartidos.push_back(part);

            aux.clear();
        }
    }else{
        cout << "Não foi possível abrir este arquivo" << endl;
    }
    
    //Fecha o arquivo e transforma a lista em um vetor
    entrada.close();
    vector<Partido> partidos(listaPartidos.begin(), listaPartidos.end());
    
    return partidos;
}

//Método para ler os candidatos do arquivo
vector<Candidato> Inout::leCandidatos(const string& arq){
    ifstream entrada;
    list<Candidato> listaCandidatos;
    list<string> aux;
    string palavra;

    bool fimArquivo = false;
    entrada.open(arq);

    //Verifica se o arquivo foi aberto 
    if(entrada.is_open()){
        //Elimina a primeira linha do arquivo
        getline(entrada, palavra);

        //Varre o arquivo até encontrar o final
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

            //Pega ultima palavra da linha
            getline(entrada, palavra, '\n');
            aux.push_back(palavra);

            //Chama o constructor do Candidato enviando a lista com as caracteristicas
            Candidato cand = Candidato(aux); 
            listaCandidatos.push_back(cand);

            aux.clear();
        }
    }else{
        cout << "Não foi possível abrir este arquivo" << endl;
    }
    
    //Fecha o arquivo e transforma a lista em um vetor
    entrada.close();
    vector<Candidato> candidatos(listaCandidatos.begin(), listaCandidatos.end());
    
    return candidatos;
}

//Método para imprimir o numero de vagas
void Inout::imprimeNumVagas(int qtdEleitos) const{
    cout << "Número de vagas: " << qtdEleitos << "\n\n";
}

//Método para imprimir vereadores eleitos
void Inout::imprimeVereadoresEleitos(const vector<Candidato>& candidatosEleitos, const vector<Partido>& partidos) const{
    cout << "Vereadores eleitos:" << endl;
    int i = 1;
    for (auto candidato : candidatosEleitos){
        cout << i << " - ";
        candidato.imprimeCandidatos(partidos);
        i++;
    } 
}

//Método para imprimir vereadores mais votados
void Inout::imprimeMaisVotados(const vector<Candidato>& maisVotados, const vector<Partido>& partidos) const{
    cout << "\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl; 
    int i = 1;
    for(auto candidato : maisVotados){
        cout << i << " - ";
        candidato.imprimeCandidatos(partidos);
        i++;
    }     
}

//Método para imprimir vereadores não eleitos
void Inout::imprimeNaoEleitos(const vector<Candidato>& maisVotados, const vector<Candidato>& naoEleitos, const vector<Partido>& partidos) const{
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

//Método para imprimir vereadores beneficiados
void Inout::imprimeBeneficiados(const vector<Candidato>& candValidos, const vector<Candidato>& beneficiados, const vector<Partido>& partidos) const{
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

//Método para imprimir os partidos
void Inout::imprimePartidos(const vector<Partido>& partidos) const{
    cout << "\nVotação dos partidos e número de candidatos eleitos:" << endl;
    int i = 1;
    for(auto partido : partidos){
        cout << i << " - ";
        partido.imprimePartido();
        i++;
    }
    
}

//Método para imprimir primeiros e ultimos candidatos de cada partido
void Inout::imprimePrimUlt(const vector<Candidato>& primeiros, const vector<Candidato>& ultimos, const vector<Partido>& partidos) const{
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

//Método para imprimir tudo
void Inout::imprimeRelatorios(
    int qtdEleitos, 
    const vector<Candidato>& candidatosEleitos, 
    const vector<Partido>& partidos, 
    const vector<Candidato>& maisVotados, 
    const vector<Candidato>& naoEleitos,
    const vector<Candidato>& candidatosValidos, 
    const vector<Candidato>& beneficiados,
    const vector<Candidato>& primeiros, 
    const vector<Candidato>& ultimos
) const{
    this->imprimeNumVagas(qtdEleitos);
    this->imprimeVereadoresEleitos(candidatosEleitos, partidos);
    this->imprimeMaisVotados(maisVotados, partidos);
    this->imprimeNaoEleitos(maisVotados, naoEleitos, partidos);
    this->imprimeBeneficiados(candidatosValidos, beneficiados, partidos);
    this->imprimePartidos(partidos);
    this->imprimePrimUlt(primeiros, ultimos, partidos);
}

//Método para converter o numero double para uma string no formato de acordo com o locale definido.
string Inout::formataSaidaDouble(const double num) const {
	// Cria uma string vazia stream e aplica o locale pt-br nela.
	stringstream stream;
	stream.imbue(locale("pt_BR.UTF-8"));

	// Concatena a string com o numero passado pelo parametro e retorna a string formatada
	stream << fixed << setprecision(2) << num;
	return stream.str();
}

//Método para imprimir o ultimo relatório
void Inout::imprimeIdadeSexoVoto(const vector<int> & idades, const vector<int> & sexos, const vector<int> & votos, const int qtdEleitos) const{
        
        cout << "\nEleitos, por faixa etária (na data da eleição):" << endl;
        cout << fixed;
        cout.precision(2);
        cout << "      Idade < 30: " << idades[0] << " (" << (formataSaidaDouble((double)idades[0]/qtdEleitos*100)) << "%)" << endl;
        cout << "30 <= Idade < 40: " << idades[1] << " (" << (formataSaidaDouble((double)idades[1]/qtdEleitos*100)) << "%)" << endl;
        cout << "40 <= Idade < 50: " << idades[2] << " (" << (formataSaidaDouble((double)idades[2]/qtdEleitos*100)) << "%)" << endl; 
        cout << "50 <= Idade < 60: " << idades[3] << " (" << (formataSaidaDouble((double)idades[3]/qtdEleitos*100)) << "%)" << endl;
        cout << "60 <= Idade     : " << idades[4] << " (" << (formataSaidaDouble((double)idades[4]/qtdEleitos*100)) << "%)" << endl;

        cout << "\nEleitos, por sexo:" << endl;
        cout << "Feminino:  " << sexos[1] << " (" << (formataSaidaDouble((double)sexos[1]/qtdEleitos*100)) << "%)" << endl;
        cout << "Masculino: " << sexos[0] << " (" << (formataSaidaDouble((double)sexos[0]/qtdEleitos*100)) << "%)" << endl;

        cout << "\nTotal de votos válidos:    " << votos[0]  << endl;
        cout << "Total de votos nominais:   " << votos[1] << " (" << (formataSaidaDouble((double)votos[1]/votos[0]*100)) << "%)" << endl;
        cout << "Total de votos de Legenda: " << votos[2] << " (" << (formataSaidaDouble((double)votos[2]/votos[0]*100)) << "%)" << "\n\n";
    }