/** Personagem do jogo*/
typedef struct personagem Personagem;

/**
 * Cria um novo personagem
 */
Personagem* personagem_cria(int x, int y, char simbolo, int cor);

/**
 * Insere um personagem no mapa
 */
Mapa* personagem_insere_mapa(Mapa* mapa, Personagem* personagem);

/**
 * Move um personagem no mapa
 */
int personagem_move(Mapa* mapa, Personagem* personagem, int x, int y);

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

/**
 * Verifica se coordenadas sao a posição atual do personagem
 */
int personagem_na_posicao(Personagem* personagem, int x, int y);
