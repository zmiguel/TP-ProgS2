///---Funcoes.h---

int display(struct GameGrid grid){
    int i, i2, ptop, gridcount=0;
    char top[50] = "\\ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for(ptop=0;ptop<grid.cols+1;ptop++){
        printf("%c ",top[ptop]);
    }
    for(i=0;i<grid.linhs;i++){
        printf("\n%d",i+1);
        for(i2=0;i2<grid.cols;i2++){
            printf(" %c", grid.grid[gridcount]);
            gridcount++;
        }
        gridcount++;
    }
}

struct GameGrid make_grid(int c, int l){
    struct GameGrid grid;
    int linhas, colunas;
    *grid.grid = NULL;

    for(linhas=0;linhas<l;linhas++){
        for(colunas=0;colunas<c;colunas++){
            if(linhas==l-1 && colunas==c-1){
                strcat(grid.grid,"X");
            }else{
                strcat(grid.grid,"*");
            }
        }
            strcat(grid.grid," ");
    }

    grid.cols = c;
    grid.linhs = l;

    return grid;
}
