#pragma once
#include <iostream>
#define MAX 5

typedef struct No{
	No* Ant = NULL;
	No* Prox = NULL;
	int ID;
}No;

class ListaCadastral{
private:
	int size;
	//No* Raiz;
public:
	No* head;
	ListaCadastral();
	bool Vazia();
	bool Cheia();
	bool Remove(int);
	bool Insere(No*);
	void ImprimeLista();
	bool EstaNaLista(int);
	int Size();
};
