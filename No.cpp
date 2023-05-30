#include <iostream>
#include "Aresta.h"
#include "No.h"

using namespace std;

No::No(){
    this->primeira_aresta = nullptr;
    this->proximo_no = nullptr;
}

No::No(int id, int peso){
    this->id = id;
    this->peso = peso;
    this->grau = 0;
    this->primeira_aresta = nullptr;
    this->proximo_no = nullptr;
}

No::~No(){}

void No::setProxNo(No *proximo){
    this->proximo_no = proximo;
}

No *No::getProxNo(){
    return this->proximo_no;
}

int No::getId(){
    return this->id;
}

void No::setId(int id){
    this->id = id;
}

Aresta *No::getPrimeiraAresta(){
    return this->primeira_aresta;
}

void No::insereAresta( int id_cabeca, int peso){
    Aresta *nova_aresta = new Aresta(id_cabeca, peso);

    nova_aresta->setProxAresta(getPrimeiraAresta());
    primeira_aresta = nova_aresta;

    /*
    if(this->primeira_aresta == nullptr){
        this->primeira_aresta = nova_aresta;
    }else{
        Aresta *aux = this->primeira_aresta;

        while (aux->getProxAresta() != nullptr)
        {
            aux = aux->getProxAresta();
        }
        
        aux->setProxAresta(nova_aresta);
    }*/
}

/*Aresta* No::buscaAresta(int id_cauda, int id_cabeca){
    Aresta *Aresta = this->primeira_aresta;

    if(this->primeira_aresta == nullptr){
        return nullptr;
    }

    while(Aresta != nullptr){
        if(Aresta->getIdCabeca() == id_cabeca && Aresta->getIdCauda() == id_cauda){
            break;
        }
        Aresta = Aresta->getProxAresta();
    }

    if(Aresta == nullptr){
        return nullptr;
    }

    return Aresta;
}*/


bool No::removeAresta(int id_cauda, int id_cabeca){
    Aresta *aresta = this->primeira_aresta;
    Aresta *aresta_anteriror = nullptr;

    if(this->primeira_aresta == nullptr){
        cout << "Aresta inexistente" << endl;
        return false;
    }

    while(aresta != nullptr){
        if(aresta->getIdCabeca() == id_cabeca)
            break;
        
        aresta_anteriror = aresta;
        aresta = aresta->getProxAresta();
    }

    if(aresta == nullptr){
        cout << "Aresta não encotrada!" << endl;
        return false;
    }

    if(aresta_anteriror == nullptr)
        this->primeira_aresta = aresta->getProxAresta();
    else if(aresta->getProxAresta() == nullptr)
        aresta_anteriror->setProxAresta(nullptr);
    else
        aresta_anteriror->setProxAresta(aresta->getProxAresta());
    
    aresta = nullptr;
    return true;
}

int No::getGrauNo(){
    return this->grau;
}

int No::getEntrada(){
    return this->grau_entrada;
}

int No::getSaida(){
    return this->grau_saida;
}

void No::setGrau(int grau){
    this->grau = grau;
}

void No::setEntrada(int grau){
    this->grau_entrada = grau;
}

void No::setSaida(int grau){
    this->grau_saida = grau;
}
