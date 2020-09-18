#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "console.h"

struct mapa {
    int x, y; // coordenadas do elemento
    int tipo;
    char simbolo; // simbolo do elemento
    int cor;
    struct mapa* prox;
};

Mapa* mapa_cria() {
    system("cls");

    Mapa* mapa = NULL;

    // parede superior
    for (int i = 1; i < MAPA_LARGURA; i++) {
        mapa =  mapa_insere(mapa, i, 0, '_', ELEMENTO_PAREDE, COLOR_YELLOW);
    }
    // parede inferior
    int limite_inferior = MAPA_ALTURA - 1;
    for (int i = 1; i < MAPA_LARGURA; i++) {
        mapa =  mapa_insere(mapa, i, limite_inferior, '_', ELEMENTO_PAREDE, COLOR_YELLOW);
    }
    // parede direita
    for (int i = 1; i < MAPA_ALTURA; i++) {
        mapa = mapa_insere(mapa, 0, i, '|', ELEMENTO_PAREDE, COLOR_YELLOW);
    }
    // parede esquerda
    for (int i = 1; i < MAPA_ALTURA; i++) {
        mapa = mapa_insere(mapa, MAPA_LARGURA, i, '|', ELEMENTO_PAREDE, COLOR_YELLOW);
    }

    return mapa;
}

Mapa* mapa_insere(Mapa* mapa, int x, int y, char simbolo, int tipo, int cor) {
    Mapa* novo = (Mapa*) malloc(sizeof(Mapa));
    novo->x = x;
    novo->y = y;
    novo->simbolo = simbolo;
    novo->tipo = tipo;
    novo->cor = cor;
    novo->prox = mapa;

    mapa_imprime(novo->x, novo->y, novo->simbolo, novo->cor);

    return novo;
}

Mapa* mapa_retira(Mapa* mapa, int x, int y) {
    Mapa* anterior = NULL;
    Mapa* atual = mapa;

    while(atual != NULL && (atual->x != x || atual->y != y)) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return mapa;
    }
    if (anterior == NULL) {
        mapa = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    mapa_imprime(x, y, ' ', COLOR_WHITE);
    free(atual);// libera memoria do elemento atual

    return mapa;
}

Mapa* mapa_move(Mapa* mapa, int de_x, int de_y, int para_x, int para_y) {
    Mapa* aux = mapa;
    while (aux != NULL && (aux->x != de_x || aux->y != de_y)) {
        aux = aux->prox;
    }

    if (aux != NULL) {
        mapa_imprime(aux->x, aux->y, ' ', COLOR_WHITE);
        aux->x = para_x;
        aux->y = para_y;
        mapa_imprime(aux->x, aux->y, aux->simbolo, aux->cor);
    }

    return mapa;
}

void mapa_imprime(int x, int y, char simbolo, int cor) {
    set_color(cor);
    gotoxy(x, y);
    printf("%c", simbolo);
    set_color(COLOR_WHITE);// volta para a cor padrão do terminal
}

int mapa_tipo(Mapa* mapa, int x, int y) {
    int tipo = NULL;
    Mapa* aux = mapa;

    while (tipo == NULL && aux != NULL) {
        if (aux->x == x && aux->y == y) {
            tipo = aux->tipo;
        }
        aux = aux->prox;
    }

    return tipo;
}
