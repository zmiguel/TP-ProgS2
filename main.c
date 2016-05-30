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
    Grid *GameGrid = NULL;
    GameGrid = malloc(sizeof(Grid));
    if(GameGrid == NULL) printf("ERRO a criar GameGrid");

    printf("Bem-Vindo!\n");

    do{
        printf("Indique os tamanhos para a grelha de jogo [COLUNAS   LINHAS] --> ");
        scanf("%d %d", &c, &l);
    }while(grid_size_check(c,l)==0);
    printf("\n");
    GameGrid = make_grid(GameGrid,c,l); ///cria a grelha de jogo
    display(GameGrid); ///mostra grelha de jogo

    int jog=0, jogada=0, linha;
    char coluna;

    do{///ciclo de jogo principal aqui:
        jog=jogada%2 +1;
        printf("\n[Jogador %d]:[LIN COL]:[3 B] -> ", jog);
        scanf("%d %c", &linha, &coluna);

    jogada++;
    }while(win_cond(GameGrid, jog)!=1);
}
