#include "../my.h"

char **initScene(char ***tab) 
{
    if (*tab == NULL)
        *tab = (char **)malloc(HEIGHT * sizeof(char *));
    char *line = (char*)malloc((WIDTH + 1) * sizeof(char));
    for (int i = 0; i < WIDTH; i++)
        line[i] = 'p';
    line[WIDTH] = '\0';
    for (int i = 0; i < HEIGHT; i++){
        if ((*tab)[i] == NULL)
            (*tab)[i] = (char*)malloc((WIDTH + 1) * sizeof(char));
        strcpy((*tab)[i], line);
    }
    free(line);
}

char **addShape(char ***tab, Entity_t *ent)
{
    for (int i = 0; i < COLS; i++){
        for (int j = 0; j < LINES; j++){
            if (i >= ent->y && i <= ent->y + ent->height - 1 &&  
            j >= ent->x && j <= ent->x + ent->width - 1 && ent->skin[i - ent->y][j - ent->x] != '\n'){
                    addch(ent->skin[i - ent->y][j - ent->x]);
            }else{
                printw("  ");
            }
        }
        addch('\n');
    }    
}