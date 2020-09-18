#include <stdio.h>
#include <stdlib.h>

#include "inimigos.h"
#include "mapa.h"
#include "console.h"
#include "helpers.h"

#define MAX_INIMIGOS 17

struct inimigos {
    int x, y;
    int ativo;
    struct inimigos* prox;
};

Inimigos* inimigos_cria() {
    return NULL;
}

Inimigos* inimigos_insere(Inimigos* ini) {
    Inimigos* novo = (Inimigos*) malloc(sizeof(Inimigos));
    novo->x = int_random(1, MAPA_LARGURA -1);
    novo->y = 1;
    novo->ativo = 1;
    novo->prox = ini;
    return novo;
}

int inimigos_contagem(Inimigos* ini) {
    int total = 0;
    for (Inimigos* aux = ini; aux != NULL; aux = aux->prox) {
        if (aux->ativo == 1) {
            total++;
        }
    }
    return total;
}

Inimigos* inimigos_retira(Inimigos* ini) {
    Inimigos* anterior = NULL;
    Inimigos* atual = ini;

    while(atual != NULL && atual->ativo == 1) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return ini;
    }
    if (anterior == NULL) {
        ini = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);// libera memoria do elemento atual

    return ini;
}

Inimigos* inimigos_atualiza_pos(Inimigos* ini, Mapa* mapa) {
    for (Inimigos* aux = ini; aux != NULL; aux = aux->prox) {
        if (aux->ativo == 1) {
            aux->y++;
        }
        if (mapa_tipo(mapa, aux->x, aux->y) == ELEMENTO_PAREDE) {
            aux->ativo = 0;
        }
    }

    if (inimigos_contagem(ini) < MAX_INIMIGOS) {
        ini = inimigos_insere(ini);
    }

    return ini;
}

Mapa* inimigos_atualiza_mapa(Inimigos* ini, Mapa* mapa) {
    for (Inimigos* aux = ini; aux != NULL; aux = aux->prox) {
        if ((aux->y - 1) > 0) {
            mapa = mapa_retira(mapa, aux->x, aux->y -1);
        }
        if (aux->ativo == 1) {
            mapa = mapa_insere(mapa, aux->x, aux->y, '*', ELEMENTO_INIMIGO, COLOR_RED);
        }
    }

    return mapa;
}

int inimigos_colidiu(Inimigos* ini, Personagem* per) {
    for (Inimigos* aux = ini; aux != NULL; aux = aux->prox) {
        if (aux->ativo == 1 && personagem_na_posicao(per, aux->x, aux->y) == 1) {
            return 1;
        }
    }
    return 0;
}
