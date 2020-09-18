#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"
#include "personagem.h"
#include "console.h"

struct personagem {
    int x,y;
    char simbolo;
    int cor;
};

Personagem* personagem_cria(int x, int y, char simbolo, int cor) {
    Personagem* personagem = (Personagem*) malloc(sizeof(Personagem));
    personagem->x = x;
    personagem->y = y;
    personagem->simbolo = simbolo;
    personagem->cor = cor;

    return personagem;
}

Mapa* personagem_insere_mapa(Mapa* mapa, Personagem* personagem) {
    return mapa_insere(
        mapa,
        personagem->x,
        personagem->y,
        personagem->simbolo,
        ELEMENTO_PERSONAGEM,
        personagem->cor
    );
}

int personagem_move(Mapa* mapa, Personagem* personagem, int x, int y) {
    int status = STATUS_SUCESSO;

    switch (mapa_tipo(mapa, x, y)) {
    case ELEMENTO_PAREDE:
        status = STATUS_FALHA;
        break;
    case ELEMENTO_INIMIGO:
        status = STATUS_COLISAO;
        break;
    }

    if (status == STATUS_SUCESSO) {
        mapa_move(mapa, personagem->x, personagem->y, x, y);
        personagem->x = x;
        personagem->y = y;
    }

    return status;
}

int personagem_move_cima(Mapa* mapa, Personagem* personagem) {
    return personagem_move(mapa, personagem, personagem->x, personagem->y - 1);
}

int personagem_move_baixo(Mapa* mapa, Personagem* personagem) {
    return personagem_move(mapa, personagem, personagem->x, personagem->y + 1);
}

int personagem_move_esquerda(Mapa* mapa, Personagem* personagem) {
    return personagem_move(mapa, personagem, personagem->x - 1, personagem->y);
}

int personagem_move_direita(Mapa* mapa, Personagem* personagem) {
    return personagem_move(mapa, personagem, personagem->x + 1, personagem->y);
}

int personagem_na_posicao(Personagem* personagem, int x, int y) {
    if (personagem->x == x && personagem->y == y) {
        return 1;
    }
    return 0;
}
