
#include "../my.h"


void freeDoubleArray(char ***tab, int height) {
    for (int i = 0; i < height; i++) {
        free((*tab)[i]);
    }
    free(*tab);
    *tab = NULL;
}
void ChangeSkin(const char *filename, Entity_t *ent){
    struct stat st;
    freeDoubleArray(&ent->skin, ent->height);
    int fd = open(filename, O_RDONLY);
    fstat(fd, &st);
    char *buf = malloc(st.st_size + 1 * sizeof(char));
    int rd = read(fd, buf, st.st_size);
    buf[rd] = '\0';
    char **tab = fromStringtoTab(buf);
    ent->width = getLongestLine(buf);
    ent->height = getNomberColumn(buf);
    copyDoubleArray(&ent->skin, &tab, ent->height, ent->width);
    free(buf);
    close(fd);
}

Entity_t *getFile(char *filename, int x, int y, int speed){
    struct stat st;
    int fd = open(filename, O_RDONLY);
    Entity_t *ent = malloc(sizeof(Entity_t));
    fstat(fd, &st);
    char *buf = malloc(st.st_size + 1 * sizeof(char));
    int rd = read(fd, buf, st.st_size);
    buf[rd] = '\0';
    char **tab = fromStringtoTab(buf);
    ent->x = x;
    ent->y = y;
    ent->speed = speed;
    ent->width = getLongestLine(buf);
    ent->height = getNomberColumn(buf);
    copyDoubleArray(&ent->skin, &tab, ent->height, ent->width);
    // printf("%s", ent->skin[0]);
    close(fd);
    free(buf);
    return ent;
}

void copyDoubleArray(char*** dest, char*** src, int rows, int cols) {
    if (src == NULL || dest == NULL) {
        return;
    }
    if (*dest == NULL) {
        *dest = (char **)malloc((rows + 1) * sizeof(char *));
        for (int i = 0; i < rows; i++) {
            (*dest)[i] = (char *)malloc(cols * sizeof(char));
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*dest)[i][j] = (*src)[i][j];
        }
    }
}

int getLongestLine(char *buffer) {

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'p') {
            return i;
        } 
    }
    return 0;
}

int getNomberColumn(char *buffer){
    int finalline = 0;
    int line = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n'){
            finalline ++;
        }   
    }
    return finalline + 1;
}

char *getuntilnextline(char *buffer, int index){
    int line = 0;
    char *returnValue = NULL;   
    int count = 0;
    int i = 0;
    int bigestLine = getLongestLine(buffer);
    for (line = index; buffer[line] != 'p'; line++);
    returnValue = (char*)malloc((bigestLine) + 1 * sizeof(char));

    for (i = index; i < line ; i++){
        count ++;
        returnValue[i - index] = buffer[index + (count -1)];
    }

    returnValue[bigestLine] = '\0';

    return returnValue;
}

char **fromStringtoTab(char *string) 
{

    int line = getLongestLine(string);
    int column = getNomberColumn(string);
    char **tab = malloc(column * sizeof(char *));
    if (tab == NULL) {
        return NULL;
    }
    int j = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        tab[j] = malloc((line + 1) * sizeof(char));
        if (tab[j] == NULL) {
            for (int k = 0; k < j; k++)
                free(tab[k]);
            free(tab);
            return NULL;
        }
        if (string[i] == 'p' && (i + 1) < strlen(string)) {
            strcpy(tab[j], getuntilnextline(string, i + 1));
            j++;
        }
        if (i == 0) {
            strcpy(tab[j], getuntilnextline(string, i));
            j++;
        }
    }
    return tab;
}