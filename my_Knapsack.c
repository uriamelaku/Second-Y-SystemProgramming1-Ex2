#include <stdio.h>
#include "my_mat.h"



int main() {
    char temp[ITEMS][NAMES];
    int result[ITEMS] = {0};
    int values[ITEMS] = {0};
    int weights[ITEMS] = {0};

    for (int i = 0; i < ITEMS; i++) {
            scanf(" %s", temp[i]);
            scanf("%d", &values[i]);
            scanf("%d", &weights[i]);
    }

    int max=knapSack(weights, values, result);
    printf("Maximum profit: %d\n",max);
    printf("Selected items:");
    for (int i = 0; i < ITEMS; i++) {
        if (result[i]) {
            printf(" %s", temp[i]);
        }
    }
    return 0;
}

