#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"
#include "personagem.h"
#include "console.h"
#include "inimigos.h"


struct inimigo {
    int x,y;
    char simbolo;
    int cor;
};


Inimigo* inimigo_cria(int x, int y, char simbolo, int cor) {
    Inimigo* inimigo = (Inimigo*) malloc(sizeof(Inimigo));
    inimigo->x = x;
    inimigo->y = y;
    inimigo->simbolo = simbolo;
    inimigo->cor = cor;

    return inimigo;
}

Mapa* inimigo_insere_mapa(Mapa* mapa, Inimigo* inimigo) {
    return mapa_insere(
        mapa,
        inimigo->x,
        inimigo->y,
        inimigo->simbolo,
        ELEMENTO_INIMIGO,
        inimigo->cor
    );
}
