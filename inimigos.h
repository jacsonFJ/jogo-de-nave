#include "mapa.h"
#include "personagem.h"

typedef struct inimigos Inimigos;

Inimigos* inimigos_cria();

Inimigos* inimigos_insere(Inimigos* ini);

int inimigos_contagem(Inimigos* ini);

/**
 * Retira da lista todos os inimigos desativados
 */
Inimigos* inimigos_retira(Inimigos* ini);

/**
 * Atualiza as coordenadas dos inimigos, mas sem atualizar o mapa
 */
Inimigos* inimigos_atualiza_pos(Inimigos* ini, Mapa* mapa);

/**
 * Atualiza a posição dos inimigos no mapa
 */
 Mapa* inimigos_atualiza_mapa(Inimigos* ini, Mapa* mapa);

 /**
  * Verifica se algum inimigo colidiu com o personagem
  */
int inimigos_colidiu(Inimigos* ini, Personagem* per);
