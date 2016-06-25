#include <iostream>
#include "ListaCadastral.h"
#include "Fila.h"

using namespace std;

int main(){
	cout << "Testando ListaCadastral\n" << endl;
	ListaCadastral *teste = new ListaCadastral;
	No* testando = new No;
	No* testando2 = new No;
	No* testando3 = new No;
	testando->ID = 2;
	testando2->ID = 99;
	testando3->ID = 11;
	cout << "ID_1: " << testando->ID << " ID_2: " << testando2->ID << " ID_3: " << testando3->ID << endl;
	teste->ImprimeLista();
	teste->Insere(testando);
	teste->Insere(testando2);
	teste->Insere(testando3);
	teste->ImprimeLista();
	cout << "head antes do remove: " << teste->head->ID << endl;

	bool b = teste->Remove(99);
	bool c = teste->Remove(3);
	cout << "b deu certo? " << b << "\nE c, deu errado? " << c << endl;
	cout << "Head depois do remove: " << teste->head->ID << endl;
	teste->ImprimeLista();

	cout << "\n\n\nTestando fila\n" << endl;
	Fila *teste2 = new Fila;
	No_fila *testando4 = new No_fila;
	No_fila *testando5 = new No_fila;
	No_fila *testando6 = new No_fila;
	testando4->ID = 6;
	testando5->ID = 9;
	testando6->ID = 8;
	teste2->Insere(testando4);
	teste2->Insere(testando5);
	teste2->Insere(testando6);
	cout << "ID_4: " << testando4->ID << " ID_5: " << testando5->ID << " ID_6: " << testando6->ID << endl;

	teste2->Inicio();
	int i;
	for(i = 0; i < teste2->Size(); i++)
	cout << "Objeto " << i << ": " << teste2->ElementoAtual() << endl;

	return 0;
}
