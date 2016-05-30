///---Estruturas.h---

typedef struct Grid_st{
    char cont;
    int lin;
    int col;
    struct Grid_st *prox;
}Grid;
