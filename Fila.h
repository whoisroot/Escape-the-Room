#pragma once
#include <iostream>

typedef struct No_fila{
	No_fila* Ant = NULL;
	No_fila* Prox = NULL;
	int ID;
}No_fila;

class Fila{
private:
	No_fila* Head;
	No_fila* Atual;
	short size;
public:
	Fila();
	void Insere(No_fila*);
	void Inicio();
	int ElementoAtual();
	int Size();
};
