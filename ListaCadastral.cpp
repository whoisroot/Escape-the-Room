#include "ListaCadastral.h"
#include <stdlib.h>

using namespace std;

ListaCadastral::ListaCadastral(){
	head = NULL;
	size = 0;
}

bool ListaCadastral::Vazia(){
	if(head == NULL || size == 0)
		return 1;
	else
		return 0;
}

bool ListaCadastral::Cheia(){
	if(size <= MAX){
		return 0;}
	else
		return 1;
}

bool ListaCadastral::Remove(int id){
	cout << "Removendo " << id << endl;
	if(!Vazia()){
        No* atual = head;
        if(head->ID == id){
            head = atual->Prox;
            free(atual);
        }
        else{
	    No* aux;
            while(atual->ID != id && atual != NULL){
                aux = atual;
		atual = atual->Prox;
		if(atual == NULL)
			return 0;
		atual->Ant = aux;
            }
            atual->Ant->Prox = atual->Prox;
            if(atual->Prox != NULL)
                atual->Prox->Ant = atual->Ant;
            free(atual);
        }
        size--;
        return 1;
    }
    else{
        return 0;
    }
}

bool ListaCadastral::Insere(No* novo){
	cout << "novo: " << novo << endl;
	if(Vazia()){
        head = novo;
        size ++;
        cout << "Inseriu head" << endl;
	}
	else if(!Cheia()){
        No* aux = head;
        while(aux->Prox != NULL)
            aux = aux->Prox;
        cout << aux << endl;
        aux->Prox = novo;
        size++;
        cout << "Inseriu outro" << endl;
        return 1;
	}else{
		return 0;
	}
}

void ListaCadastral::ImprimeLista(){
    No* aux = head;
    cout << "\nInicio da lista" << endl;
    while(aux != NULL){
        cout << aux->ID << endl;
        aux = aux->Prox;
    }
    cout << "Fim da lista\n" << endl;
}

bool ListaCadastral::EstaNaLista(int id){
	No* atual = head;
	while(atual != NULL){
		if(atual->ID == id)
			return 1;
	}
	return 0;
}

int ListaCadastral::Size(){
	return size;
}
