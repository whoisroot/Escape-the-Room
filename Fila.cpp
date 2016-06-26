#include "Fila.h"

using namespace std;

Fila::Fila(){
	Head = NULL;
	Atual = NULL;
	size = 0;
}

void Fila::Insere(int id){
	if(Head == NULL){
        No_fila* novo = new No_fila;
        novo->ID = id;
		Head = novo;
		size++;
	}
	else{
		No_fila* aux = Head;
		while(aux->Prox != NULL)
			aux = aux->Prox;
        No_fila* novo = new No_fila;
        novo->ID = id;
		aux->Prox = novo;
		size++;
	}
}

void Fila::Inicio(){
	Atual = Head;
}

int Fila::ElementoAtual(){
	int id = Atual->ID;
	cout << "Elemento atual: " << id << endl;
	Atual = Atual->Prox;
	return id;
}

int Fila::Size(){
	return size;
}
