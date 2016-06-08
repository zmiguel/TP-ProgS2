///---Estruturas.h---

typedef struct Grid_st{
    char cont;
    int lin;
    int col;
    struct Grid_st *prox;
}Grid;

typedef struct GameSave_st{
    int id;
    int lin;
    int col;
    struct GameSave_st *prox;
}GameSave;
