
#include "my.h"
#include <time.h>
int main() {
    int nb_entity = 8;
    int indexAlgues = 1;
    srand( time( NULL ) );
    const char *algues[] = {
    "./environement/algues/1.sealand",
    "./environement/algues/3.sealand"
    };
    Entity_t *ent[30];
    ent[0] = getFile("./environement/poisson/1.sealand", 0, 1, 1);
    ent[1] = getFile("./environement/respi.sealand", ent[0]->x, ent[0]->y, 1);
    ent[2] = getFile("./environement/poisson/3.sealand", 0, 30, 3);
    ent[3] = getFile("./environement/respi.sealand", ent[2]->x, ent[2]->y, 1);
    ent[4] = getFile("./environement/poisson/1.sealand", 0, 20, 1);
    ent[5] = getFile("./environement/respi.sealand", ent[3]->x, ent[3]->y, 1);
    ent[6] = getFile("./environement/poisson/3.sealand", 0, 10, 3);
    ent[7] = getFile("./environement/respi.sealand", ent[4]->x, ent[4]->y, 1);

    char **tab = NULL;
    initscr();
     for (int i = 0; i < LINES; i += 3){
        ent[nb_entity] = getFile("./environement/algues/1.sealand", i, 40, 1);
        nb_entity ++;
    }
    while (1) {
        initScene(&tab);
        clear();

        printw("la valeur de ent est de %d\n", ent[0]->x);
        printgame(tab, ent, nb_entity);
        if (ent[0]->x < 0){
            ent[0]->x = LINES;
        }
        if (ent[2]->x < 0){
            ent[2]->x = LINES;
        }
        ent[0]->x -= ent[0]->speed;
        ent[2]->x -= ent[2]->speed;
        if (ent[4]->x < 0){
            ent[4]->x = LINES;
        }
        if (ent[6]->x < 0){
            ent[6]->x = LINES;
        }        
        ent[6]->x -= ent[6]->speed;
        ent[4]->x -= ent[4]->speed;


        if (ent[1]->y < 0 && ent[0]->x > 0){
            ent[1]->x = ent[0]->x;
            ent[1]->y = ent[0]->y;
        }
        ent[1]->y -= ent[1]->speed;



        if (ent[3]->y < 0){
            ent[3]->x = ent[2]->x;
            ent[3]->y = ent[2]->y;
        }
        ent[3]->y -= ent[3]->speed;

        if (ent[5]->y < 0){
            ent[5]->x = ent[4]->x;
            ent[5]->y = ent[4]->y;
        }
        ent[5]->y -= ent[5]->speed;

         if (ent[7]->y < 0){
            ent[7]->x = ent[6]->x;
            ent[7]->y = ent[6]->y;
        }
        ent[7]->y -= ent[7]->speed; 
        
        indexAlgues =  rand() % 2; 

        for (int i = 8; i < nb_entity - 1; i += 1){
            ChangeSkin(algues[indexAlgues], ent[i]);
        }

        refresh();
        usleep(100000);
    }

    endwin();

    return 0;
}