#include "../my.h"

void printgame(char **tab, Entity_t *ent[30], int nb_entity) {
    printw("nb entity %d\n", nb_entity);
    int printed = 0;
    for (int i = 0; i < COLS; i++){
        for (int j = 0; j < LINES; j++){
            for (int k = 0; k < nb_entity - 1; k++){
                if (i >= ent[k]->y && i <= ent[k]->y + ent[k]->height - 1 &&  
                j >= ent[k]->x && j <= ent[k]->x + ent[k]->width - 1 && ent[k]->skin[i - ent[k]->y][j - ent[k]->x] != '\n'){
                    addch(ent[k]->skin[i - ent[k]->y][j - ent[k]->x]);
                    printed = 1;
                }
            }
            if (printed == 1){
                printed = 0;
            } else {
                printw("  ");
            }
        }
        addch('\n');
    }
}    