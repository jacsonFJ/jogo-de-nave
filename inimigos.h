/** Inimigos*/
typedef struct inimigo Inimigo;

/**
 * Cria um novo inimigo
 */
Inimigo* inimigo_cria(int x, int y, char simbolo, int cor);

/**
 * Insere um inimigo no mapa
 */
Mapa* inimigo_insere_mapa(Mapa* mapa, Inimigo* inimigo);

/**
 * Move um inimigo no mapa
 */
int inimigo_move(Mapa* mapa, Inimigo* inimigo, int x, int y);

/**
 * Move um personagem para cima
 */
int personagem_move_cima(Mapa* mapa, Personagem* personagem);

/**
 * Move um personagem para baixo
 */
int personagem_move_baixo(Mapa* mapa, Personagem* personagem);

/**
 * Move um personagem para esquerda
 */
int personagem_move_esquerda(Mapa* mapa, Personagem* personagem);

/**
 * Move um personagem para direita
 */
int personagem_move_direita(Mapa* mapa, Personagem* personagem);

