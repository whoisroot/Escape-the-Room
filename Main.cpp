#include <allegro.h>
#include <iostream>
#include "ListaCadastral.h"
#include "Fila.h"
#define width 841
#define heigth 687

using namespace std;

//Imprime as telas com a visão da sala e os objetos a serem coletados
void Tela(ListaCadastral* ObjGame, short tela, BITMAP* buffer,/* BITMAP* setaEsq,*/ BITMAP* setaDir, BITMAP* Parede1, BITMAP* Parede2, BITMAP* Parede3, BITMAP* Parede4, BITMAP* burgue, BITMAP* Gatinhos, BITMAP* Livro, BITMAP* Faca, BITMAP* Dinheiro, BITMAP* Quadro, BITMAP* Chave1,/*  BITMAP* Chave2 , BITMAP* Chave3,*/ BITMAP* Martelo1,/* BITMAP* Martelo2,*/ BITMAP* Vaso, BITMAP* Tulipas, BITMAP* Madeira, bool porta, bool quadro, bool vaso, bool tulipas){

	switch(tela){
		case 0:
		    cout << "Parede 1" << endl;
			blit(Parede1, buffer, 0, 0, 0, 0, width, heigth-120);
		    if(vaso)
                draw_sprite(buffer, Vaso, 584, 25);
            if(ObjGame->EstaNaLista(4))
                draw_sprite(buffer, Dinheiro, 28, 228);
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
            if(ObjGame->EstaNaLista(0))
                draw_sprite(buffer, burgue, 348, 118);
            if(ObjGame->EstaNaLista(1))
                draw_sprite(buffer, Gatinhos, 144, 95);
			break;
		case 3:
		    cout << "Parede 4" << endl;
            blit(Parede4, buffer, 0, 0, 0, 0, width, heigth-120);
            if(porta)
                draw_sprite(buffer, Madeira, 116, 1);
            if(quadro)
                draw_sprite(buffer, Quadro, 647, 12);
            if(tulipas)
                draw_sprite(buffer, Tulipas, 353, 157);
            if(ObjGame->EstaNaLista(3))
                draw_sprite(buffer, Faca, 669, 151);
			break;
		default:
			cout << "Esta tela não existe!!" << endl;
			break;
	}

	draw_sprite_h_flip(buffer, setaDir, 7, 260);
	draw_sprite(buffer, setaDir, 771, 260);

}

//Imprime na gaveta inferior os objetos já coletados
void gaveta(Fila* ObjPlayer, BITMAP* buffer, BITMAP* burgue_gaveta, BITMAP* Gatinhos, BITMAP* Livro_gaveta, BITMAP* Faca, BITMAP* Dinheiro_gaveta, BITMAP* Bilhete_gaveta, BITMAP* Chave_gaveta , BITMAP* Martelo_gaveta){
    ObjPlayer->Inicio();
	int i, x = 50, id;
	for(i = 1; i <= ObjPlayer->Size(); i++){
        cout << "teste " << i << endl;
        id = ObjPlayer->ElementoAtual();
        if(id == 0)
            draw_sprite(buffer, burgue_gaveta, x, heigth-114);
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
        x = x + 210;
	}
}

int main(){

srand(time(NULL));
	ListaCadastral* ObjGame = new ListaCadastral;
	Fila* ObjPlayer = new Fila;
	short i, tela = 0;
	bool porta = 1 , martelo = 0, chave = 0, tulipas = 1, vaso = 1, quadro = 1, click;

    //Popula a lista cadastral com os objetos a serem coletados, sempre gerando uma chave e um martelo
    short cHave = (6 + (rand()%2));
    ObjGame->Insere(cHave);
    ObjGame->Insere(9);
    for(i = 0; i < 2; i++){
        int id = rand()%6;
        if(!(ObjGame->EstaNaLista(id)))
            ObjGame->Insere(id);
        else
            i--;
    }

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

    BITMAP* Iniciar = load_bitmap("Imagens/iniciar.bmp", NULL);
    //BITMAP* setaEsq = load_bitmap("Imagens/setaEsq.bmp", NULL);
    BITMAP* setaDir = load_bitmap("Imagens/setaDir.bmp", NULL);
    BITMAP* Parede1 = load_bitmap("Imagens/Parede1.bmp", NULL);
    BITMAP *Parede2 = load_bitmap("Imagens/Parede2.bmp", NULL);
    BITMAP *Parede3 = load_bitmap("Imagens/Parede3.bmp", NULL);
    BITMAP *Parede4 = load_bitmap("Imagens/Parede4.bmp", NULL);
    BITMAP *Gaveta = load_bitmap("Imagens/Gaveta.bmp", NULL);
    BITMAP* GameOver = load_bitmap("Imagens/gameover.bmp", NULL);

    BITMAP* burgue = load_bitmap("Imagens/burgue.bmp", NULL);
    BITMAP* burgue_gaveta = load_bitmap("Imagens/burgue_gaveta.bmp", NULL);
    BITMAP* Gatinhos = load_bitmap("Imagens/Gatinhos.bmp", NULL);
    BITMAP *Livro = load_bitmap("Imagens/Livro.bmp", NULL);
    BITMAP *Livro_gaveta = load_bitmap("Imagens/Livro_gaveta.bmp", NULL);
    BITMAP* Faca = load_bitmap("Imagens/Faca2.bmp", NULL);
    BITMAP* Faca_gaveta = load_bitmap("Imagens/Faca_gaveta.bmp", NULL);
    BITMAP* Dinheiro = load_bitmap("Imagens/Dinheiro.bmp", NULL);
    BITMAP* Dinheiro_gaveta = load_bitmap("Imagens/Dinheiro_gaveta.bmp", NULL);
    BITMAP* Quadro = load_bitmap("Imagens/Quadro.bmp", NULL);
    BITMAP* Bilhete_gaveta = load_bitmap("Imagens/Bilhete_gaveta.bmp", NULL);
    BITMAP* Chave1 = load_bitmap("Imagens/Chave1.bmp", NULL);
    BITMAP* Chave_gaveta = load_bitmap("Imagens/Chave_gaveta.bmp", NULL);
    BITMAP* Martelo1 = load_bitmap("Imagens/Martelo1.bmp", NULL);
    BITMAP* Martelo_gaveta = load_bitmap("Imagens/Martelo_gaveta.bmp", NULL);
    BITMAP* Vaso = load_bitmap("Imagens/Vaso.bmp", NULL);
    BITMAP* Tulipas = load_bitmap("Imagens/Tulipas.bmp", NULL);
    BITMAP* Madeira = load_bitmap("Imagens/Madeira.bmp", NULL);



    show_mouse(buffer);

//________________________________________Fim_Allegro______________________________________________________

    Tela(ObjGame, tela, buffer,/* setaEsq,*/ setaDir, Parede1, Parede2, Parede3, Parede4, burgue, Gatinhos, Livro, Faca, Dinheiro, Quadro, Chave1,/*  Chave2 , Chave3,*/ Martelo1,/* Martelo2,*/ Vaso, Tulipas, Madeira, porta, quadro, vaso, tulipas);
    blit(Gaveta, buffer, 0, 0, 0, 568, width, heigth);
    gaveta(ObjPlayer, buffer, burgue, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
    //blit(buffer, screen, 0, 0, 0, 0, width, heigth);

    blit(Iniciar, screen, 0, 0, 0, 0, width, heigth);
    readkey();

    do{
        if(!(mouse_b & 1)){
            click = 0;
        }else{
            click = 1;
        }

        if(click){
            while(mouse_b){}
            click = 0;

            //cout << "X: " << mouse_x << " Y: " << mouse_y << endl;

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

            if(tela == 0){
                if((mouse_x > 28 && mouse_x < 64) && (mouse_y > 228 && mouse_y < 262) && ObjGame->EstaNaLista(4)){
                    ObjGame->Remove(4);
                    ObjPlayer->Insere(4);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
                else if((mouse_x > 584 && mouse_x < 757) && (mouse_y > 25 && mouse_y < 276) && ObjGame->EstaNaLista(6)){
                    ObjGame->Remove(6);
                    vaso = 0;
                    chave = 1;
                    ObjPlayer->Insere(6);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
            }
            else if(tela == 1){
                if((mouse_x > 110 && mouse_x < 132) && (mouse_y > 87 && mouse_y < 151) && ObjGame->EstaNaLista(2)){
                    ObjGame->Remove(2);
                    ObjPlayer->Insere(2);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
                else if((mouse_x > 568 && mouse_x < 607) && (mouse_y > 439 && mouse_y < 468) && ObjGame->EstaNaLista(9)){
                    ObjGame->Remove(9);
                    martelo = 1;
                    ObjPlayer->Insere(9);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
            }
            else if(tela == 2){
                if((mouse_x > 348 && mouse_x < 423) && (mouse_y > 118 && mouse_y < 193) && ObjGame->EstaNaLista(0)){
                    ObjGame->Remove(0);
                    ObjPlayer->Insere(0);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
                else if((mouse_x > 144 && mouse_x < 254) && (mouse_y > 95 && mouse_y < 205) && ObjGame->EstaNaLista(1)){
                    ObjGame->Remove(1);
                    ObjPlayer->Insere(1);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
            }
            else if(tela == 3){
                if((mouse_x > 647 && mouse_x < 757) && (mouse_y > 12 && mouse_y < 131) && ObjGame->EstaNaLista(5)){
                    ObjGame->Remove(5);
                    quadro = 0;
                    ObjPlayer->Insere(5);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
                else if((mouse_x > 353 && mouse_x < 557) && (mouse_y > 157 && mouse_y < 376) && ObjGame->EstaNaLista(7)){
                    ObjGame->Remove(7);
                    tulipas = 0;
                    chave = 1;
                    ObjPlayer->Insere(7);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
                else if((mouse_x > 116 && mouse_x < 360) && (mouse_y > 1 && mouse_y < 354) && martelo){
                    if(porta)
                        porta = 0;
                    else if(chave && ObjGame->Vazia())
                        break;
                }
                else if((mouse_x > 669 && mouse_x < 740) && (mouse_y > 151 && mouse_y < 172) && ObjGame->EstaNaLista(3)){
                    ObjGame->Remove(3);
                    ObjPlayer->Insere(3);
                    gaveta(ObjPlayer, buffer, burgue_gaveta, Gatinhos, Livro_gaveta, Faca_gaveta, Dinheiro_gaveta, Bilhete_gaveta, Chave_gaveta , Martelo_gaveta);
                }
            }


            Tela(ObjGame, tela, buffer,/* setaEsq,*/ setaDir, Parede1, Parede2, Parede3, Parede4, burgue, Gatinhos, Livro, Faca, Dinheiro, Quadro, Chave1,/*  Chave2 , Chave3,*/ Martelo1,/* Martelo2,*/ Vaso, Tulipas, Madeira, porta, quadro, vaso, tulipas);
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, width, heigth);
    }
    while(!key[KEY_ESC]);

    if(chave && !porta && ObjGame->Vazia()){
        blit(GameOver, screen, 0, 0, 0, 0, width, heigth);
        readkey();
    }

	return 0;
}
END_OF_MAIN ()
