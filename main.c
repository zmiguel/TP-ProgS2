#include <stdio.h>
#include <tgmath.h>
#include <ctype.h>
#include <string.h>
///headers
#include "estruturas.h"
#include "funcoes.h"

#define TAM1 10

void main(void){
    int i,c,l;
    struct GameGrid game_grid;

    printf("Bem-Vindo!\nIndique os tamanhos para a grelha de jogo [COLUNAS : LINHAS] --> ");
    scanf("%d:%d", &c, &l);

    /// VERIFICAR SE ESTA DENTRO DOS LIMITES ( número de linhas entre 4 e 8 e número de colunas entre 6 e 10)
    /// O número de colunas deve ser superior ao número de linhas

    game_grid = make_grid(c,l); ///cria a grelha de jogo

    display(game_grid);
}
