#include <iostream>
#include "ListaCadastral.h"

using namespace std;

int main(){
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
	return 0;
}
