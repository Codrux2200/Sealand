#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <string.h>
#include <ncurses.h>
#define HEIGHT LINES
#define WIDTH COLS
struct Entity {
    char **skin;
    int x;
    int y;
    int width;
    int height;
    int speed;

}; typedef struct Entity Entity_t;

char **initScene(char ***tab);
Entity_t *getFile(char *filename, int x, int y, int speed);
char **fromStringtoTab(char *string);
void ChangeSkin(const char *filename, Entity_t *ent);
int getLongestLine(char *buffer);
int getNomberColumn(char *buffer);
void copyDoubleArray(char*** dest, char*** src, int rows, int cols);
void printgame(char **tab, Entity_t *ent[30], int nb_entity);
char **addShape(char ***tab, Entity_t *ent);