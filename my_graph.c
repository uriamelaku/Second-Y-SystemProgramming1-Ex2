#include <stdio.h>
#include "my_mat.h"

int main() {
    char check = ' ';
    int i = 0, j = 0;

    while (check != 'D') {
        scanf(" %c", &check);
        if (check == 'A') {
            buildMatrix();
        } else if (check == 'B') {
            scanf(" %d", &i);
            scanf(" %d", &j);
            if (isPath(i, j)) {
                printf("True\n");
            } else {
                printf("False\n");
            }
        } else if (check == 'C') {
            scanf(" %d", &i);
            scanf(" %d", &j);
            int shortest= shortestPath(i, j);
            printf("%d\n",shortest);
        }
    }
    return 0;
}
