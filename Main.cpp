#include <allegro.h>
#include <iostream>
#include "ListaCadastral.h"
#include "Fila.h"
#define width 841
#define heigth 687

using namespace std;

void Tela(ListaCadastral* ObjGame, short tela, BITMAP* buffer,/* BITMAP* setaEsq,*/ BITMAP* setaDir, BITMAP* Parede1, BITMAP* Parede2, BITMAP* Parede3, BITMAP* Parede4, BITMAP* Livro, BITMAP* Martelo1){//, BITMAP* Vaso, BITMAP* , BITMAP* ,  )
	short i = 0;

	switch(tela){
		case 0:
		    cout << "Parede 1" << endl;
			blit(Parede1, buffer, 0, 0, 0, 0, width, heigth-120);
			break;
		case 1:
		    cout << "Parede 2" << endl;
		    blit(Parede2, buffer, 0, 0, 0, 0, width, heigth-120);
		    if(ObjGame->EstaNaLista(2))
                draw_sprite(buffer, Livro, 110, 87);
            if(ObjGame->EstaNaLista(9))
                draw_sprite(buffer, Martelo1, 568, 439);
			break;
		case 2:
		    cout << "Parede 3" << endl;
		    blit(Parede3, buffer, 0, 0, 0, 0, width, heigth-120);
			break;
		case 3:
		    cout << "Parede 4" << endl;
		    blit(Parede4, buffer, 0, 0, 0, 0, width, heigth-120);
			break;
		default:
			cout << "Esta tela não existe!!" << endl;
			break;
	}

	draw_sprite_h_flip(buffer, setaDir, 7, 260);
	draw_sprite(buffer, setaDir, 771, 260);

}

void gaveta(Fila* ObjPlayer, BITMAP* buffer, BITMAP* burgue, BITMAP* Gatinhos, BITMAP* Livro_gaveta, BITMAP* Faca, BITMAP* Dinheiro_gaveta, BITMAP* Bilhete_gaveta, BITMAP* Chave_gaveta , BITMAP* Martelo_gaveta){
    ObjPlayer->Inicio();
	int i, x = 50, id;
	for(i = 1; i <= ObjPlayer->Size(); i++){
        cout << "teste " << i << endl;
        id = ObjPlayer->ElementoAtual();
        if(id == 0)
            draw_sprite(buffer, burgue, x, heigth-114);
        else if(id == 1)
            draw_sprite(buffer, Gatinhos, x, heigth-114);
        else if(id == 2)
            draw_sprite(buffer, Livro_gaveta, x, heigth-114);
        else if(id == 3)
            draw_sprite(buffer, Faca, x, heigth-114);
        else if(id == 4)
            draw_sprite(buffer, Dinheiro_gaveta, x, heigth-114);
        else if(id == 5)
            draw_sprite(buffer, Bilhete_gaveta, x, heigth-114);
        else if((id == 6)||(id == 7)||(id == 8))
            draw_sprite(buffer, Chave_gaveta, x, heigth-114);
        else if((id == 9)||(id == 10))
            draw_sprite(buffer, Martelo_gaveta, x, heigth-114);

        cout << "Objeto " << i << ": " << id << endl;
        x = x + (210*i);
	}
}

int main(){

srand(time(NULL));
	ListaCadastral* ObjGame = new ListaCadastral;
	Fila* ObjPlayer = new Fila;
	short i, tela = 0;
	bool aux, click;
/*for(i = 0; i < 4; i++){
    int id = rand()%8;
    if(!ObjGame->EstaNaLista(id))
        aux = ObjGame->Insere(id);
    else
        i--;
}*/
ObjGame->Insere(2);
ObjGame->Insere(9);

ObjGame->ImprimeLista();


//________________________________________Inicio_Allegro_______________________________________________________
    if (allegro_init() != 0){
       cout << "Erro ao iniciar o Allegro" << endl;
        return 1;
    }
    install_keyboard();
    install_mouse();

   // set a graphics mode sized 844x567
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, heigth, 0, 0);
    BITMAP *buffer  = create_bitmap(width, heigth);

    //BITMAP* setaEsq = load_bitmap("Imagens/setaEsq.bmp", NULL);
    BITMAP* setaDir = load_bitmap("Imagens/setaDir.bmp", NULL);
    BITMAP* Parede1 = load_bitmap("Imagens/Parede1.bmp", NULL);
    BITMAP *Parede2 = load_bitmap("Imagens/Parede2.bmp", NULL);
    BITMAP *Parede3 = load_bitmap("Imagens/Parede3.bmp", NULL);
    BITMAP *Parede4 = load_bitmap("Imagens/Parede4.bmp", NULL);
    BITMAP *Gaveta = load_bitmap("Imagens/gaveta2.bmp", NULL);

    BITMAP* burgue = load_bitmap("Imagens/burgue.bmp", NULL);
    BITMAP* Gatinhos = load_bitmap("Imagens/Gatinhos.bmp", NULL);
    BITMAP *Livro = load_bitmap("Imagens/Livro.bmp", NULL);
    BITMAP *Livro_gaveta = load_bitmap("Imagens/Livro_gaveta.bmp", NULL);
    BITMAP* Faca = load_bitmap("Imagens/Faca.bmp", NULL);
    BITMAP* Dinheiro = load_bitmap("Imagens/Dinheiro.bmp", NULL);
    BITMAP* Dinheiro_gaveta = load_bitmap("Imagens/Dinheiro_gaveta.bmp", NULL);
    BITMAP* Quadro = load_bitmap("Imagens/Quadro.bmp", NULL);
    BITMAP* Bilhete_gaveta = load_bitmap("Imagens/Bilhete_gaveta.bmp", NULL);
    BITMAP* Chave1 = load_bitmap("Imagens/Chave1.bmp", NULL);
    BITMAP* Chave_gaveta = load_bitmap("Imagens/Chave_gaveta.bmp", NULL);
    BITMAP* Martelo1 = load_bitmap("Imagens/Martelo1.bmp", NULL);
    BITMAP* Martelo_gaveta = load_bitmap("Imagens/Martelo_gaveta.bmp", NULL);



    show_mouse(buffer);

//________________________________________Fim_Allegro______________________________________________________

    Tela(ObjGame, tela, buffer, setaDir, Parede1, Parede2, Parede3, Parede4, Livro, Martelo1);
    blit(Gaveta, buffer, 0, 0, 0, 568, width, heigth);
    gaveta(ObjPlayer, buffer, burgue, Gatinhos, Livro_gaveta, Faca, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
    //blit(buffer, screen, 0, 0, 0, 0, width, heigth);

    do{
        if(!(mouse_b & 1)){
            click = 0;
        }else{
            click = 1;
        }

        if(click){
            while(mouse_b){}
            click = 0;

            cout << "X: " << mouse_x << " Y: " << mouse_y << endl;

            if(mouse_y < 568){
            if((mouse_x > 7 && mouse_x < 70) && (mouse_y > 260 && mouse_y < 307)){
                if(tela > 0)
                    tela--;
                else
                    tela = 3;
            }
            else if((mouse_x > 771 && mouse_x < 834) && (mouse_y > 260 && mouse_y < 307)){
                if(tela < 3)
                    tela++;
                else
                    tela = 0;
            }

            if(tela == 1){
                if((mouse_x > 110 && mouse_x < 132) && (mouse_y > 87 && mouse_y < 151)){
                    ObjGame->Remove(2);
                    ObjPlayer->Insere(2);
                    gaveta(ObjPlayer, buffer, burgue, Gatinhos, Livro_gaveta, Faca, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
                else if((mouse_x > 568 && mouse_x < 607) && (mouse_y > 439 && mouse_y < 468)){
                    ObjGame->Remove(9);
                    ObjPlayer->Insere(9);
                    gaveta(ObjPlayer, buffer, burgue, Gatinhos, Livro_gaveta, Faca, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
            }

            Tela(ObjGame, tela, buffer, setaDir, Parede1, Parede2, Parede3, Parede4, Livro, Martelo1);
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, width, heigth);
    }
    while(!key[KEY_ESC]);

	//readkey();
	return 0;
}
