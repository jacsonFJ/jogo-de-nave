#define ELEMENTO_OBJETO 0
#define ELEMENTO_PAREDE 1
#define ELEMENTO_PERSONAGEM 2
#define ELEMENTO_INIMIGO 3
#define MAPA_LARGURA 30
#define MAPA_ALTURA 20

/** Mapa do jogo */
typedef struct mapa Mapa;

/**
 *Cria um novo mapa
 */
Mapa* mapa_cria();

/**
 * Insere um novo elemento no mapa com as coordenadas informadas
 */
Mapa* mapa_insere(Mapa* mapa, int x, int y, char simbolo, int tipo, int cor);

/**
 * Retira um elemento do mapa nas coordenadas informadas
 */
Mapa* mapa_retira(Mapa* mapa, int x, int y);

/**
 * Move um elemento no mapa
 */
Mapa* mapa_move(Mapa* mapa, int de_x, int de_y, int para_x, int para_y);

/**
 * Busca o tipo do elemento nas coordenadas informadas
 */
int mapa_tipo(Mapa* mapa, int x, int y);
