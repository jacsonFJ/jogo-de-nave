// Define codigos de algumas teclas
#define TECLA_CIMA 72
#define TECLA_BAIXO 80
#define TECLA_ESQUERDA 75
#define TECLA_DIREITA 77
#define TECLA_ENTER 13
#define TECLA_ESPACO 32
#define TECLA_ESC 27
#define TECLA_s 115
#define TECLA_S 83
#define TECLA_n 110
#define TECLA_N 78

// Define os status possiveis para o jogo e suas a��es
#define STATUS_SUCESSO 0
#define STATUS_FALHA 1
#define STATUS_COLISAO 2
#define STATUS_GAME_OVER 3

// Define cores
enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARKGREY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTCYAN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
};

/**
 * Define coordenadas da janela
 */
void set_window(int width, int height);

/**
 * Posiciona cursor em x e y
 */
void gotoxy(int x, int y);

/**
 * Define cor de fundo
 */
void set_background_color(int color);

/**
 * Define cor do caracter
 */
void set_color(int color);

/**
 * Esconde o cursor do terminal
 */
void hide_cursor();
