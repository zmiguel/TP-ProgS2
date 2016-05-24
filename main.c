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
    Grid GameGrid;
    Grid *pGameGrid;
    GameGrid = *make_new(); ///cria a grelha de jogo

    printf("Bem-Vindo!\n");

    do{
        printf("Indique os tamanhos para a grelha de jogo [COLUNAS   LINHAS] --> ");
        scanf("%d %d", &c, &l);
    }while(grid_size_check(c,l)==0);
    GameGrid = *make_grid(c,l); ///cria a grelha de jogo

    display(&GameGrid); ///mostra grelha de jogo
}
