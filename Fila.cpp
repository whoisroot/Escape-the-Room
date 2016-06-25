#include "Fila.h"

using namespace std;

Fila::Fila(){
	Head = NULL;
	Atual = NULL;
	size = 0;
}

void Fila::Insere(No_fila* novo){
	cout << "novo: " << novo->ID << " " << novo << " Head: " << Head << endl;
	if(Head == NULL){
		Head = novo;
		size++;
	}
	else{
		cout << "Chegou aqui?" << endl;
		No_fila* aux = Head;
		cout << "aux: " << aux << " aux->Prox: " << aux->Prox << endl;
		while(aux->Prox != NULL){
			cout << "Aux: " << aux << endl;
			cout << "penis ";
			cout << "aux: " << aux->ID << endl;
			aux = aux->Prox;
		}
		aux->Prox = novo;
		cout << "aux->ID: ";
		cout << aux->ID << endl;
		size++;
	}
}

void Fila::Inicio(){
	Atual = Head;
}

int Fila::ElementoAtual(){
	cout << "Entrou! " << endl;
	cout << "Atual: " << Atual << " Atual->Prox: " << Atual->Prox << endl;
	int id = Atual->ID;
	cout << "Elemento atual: " << id << endl;
	Atual = Atual->Prox;
	return id;
}

int Fila::Size(){
	return size;
}
