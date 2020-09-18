#include <stdio.h>
#include <stdlib.h>

#include "console.h"
#include "mapa.h"
#include "personagem.h"
#include "inimigos.h"

Mapa* mapa;
Personagem* personagem;
Inimigos* inimigos;
int game_status = STATUS_SUCESSO;

void inicia_jogo() {
    set_window(80, 80);
    hide_cursor();

    mapa = mapa_cria();
    personagem = personagem_cria(
        (int) MAPA_LARGURA / 2,
        MAPA_ALTURA - 2,
        'A',
        COLOR_LIGHTCYAN
    );
    inimigos = inimigos_cria();
    mapa = personagem_insere_mapa(mapa, personagem);
}

void controle() {
    if(kbhit()) {
        switch(getch()) {
            case TECLA_CIMA:
                game_status = personagem_move_cima(mapa, personagem);
                break;
            case TECLA_BAIXO:
                game_status = personagem_move_baixo(mapa, personagem);
                break;
            case TECLA_ESQUERDA:
                game_status = personagem_move_esquerda(mapa, personagem);
                break;
            case TECLA_DIREITA:
                game_status = personagem_move_direita(mapa, personagem);
                break;
            case TECLA_ESC:
                game_status = STATUS_GAME_OVER;
                break;
        }

        if (game_status == STATUS_COLISAO) {
            game_status = STATUS_GAME_OVER;
        }
    }
}

int main() {
    int inimigos_sleep = 0;
    inicia_jogo();

    while (game_status != STATUS_GAME_OVER) {
        controle();

        Sleep(25);

        inimigos_sleep += 25;
        if (inimigos_sleep >= 200) {
            inimigos_sleep = 0;
            inimigos = inimigos_atualiza_pos(inimigos, mapa);
            mapa = inimigos_atualiza_mapa(inimigos, mapa);
            inimigos = inimigos_retira(inimigos);
            if (inimigos_colidiu(inimigos, personagem) == 1) {
                game_status = STATUS_GAME_OVER;
            }
        }
    }

    mapa = mapa_cria();
    gotoxy(11, 9);
    printf("GAME OVER");
    Sleep(2000);

    return 0;
}
