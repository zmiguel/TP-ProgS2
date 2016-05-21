#include <stdio.h>
#include <tgmath.h>
#include <ctype.h>
#include <string.h>
///headers
#include "estruturas.h"
#include "funcoes.h"

#define TAM1 10

void main(void){
    int i,c=0,l=0;
    struct GameGrid game_grid;

    printf("Bem-Vindo!\n");

    do{
        printf("Indique os tamanhos para a grelha de jogo [COLUNAS   LINHAS] --> ");
        scanf("%d %d", &c, &l);
    }while(grid_size_check(c,l)==0);
    game_grid = make_grid(c,l); ///cria a grelha de jogo

    display(game_grid); ///mostra grelha de jogo
}
