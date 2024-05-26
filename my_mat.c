#include "my_mat.h"
#include <stdio.h>

int matrix[N][N];

int min(int a, int b) {
    return (a < b) ? a : b;
}

void buildMatrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }
    FloydWarshall(0,0);
}

int FloydWarshall(int a, int b) {
    int x;
    int y;
    int z;
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                x = matrix[i][j];
                y = matrix[i][k];
                z = matrix[k][j];
                if(i!=j){
                    if(x!=0){
                        if(y!=0 && z!=0){
                            if(x>y+z) matrix[i][j]=z+y;
                        }
                    }
                    else if(y!=0 && z!=0){
                        matrix[i][j] = y + z;
                    }
                }
            }
        }
    }
    return matrix[a][b];
}

int isPath(int i, int j) {
    return (matrix[i][j] > 0);
}

int shortestPath(int i, int j) {
    if (isPath(i, j)) {
        return matrix[i][j];
    }
    return -1;
}
int knapSack(int weights[], int values[], int selected_bool[]) {

  int help[ITEMS + 1][CAPCITY + 1];

  for (int i = 0; i <= ITEMS; i++) {
    for (int j = 0; j <= CAPCITY; j++) {
      if (i == 0 || j == 0) {
        help[i][j] = 0;
      } else if (weights[i - 1] > j) {
        help[i][j] = help[i - 1][j];
      } else {
        help[i][j] = fmax(help[i - 1][j], help[i - 1][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }


  int i = ITEMS;
  int j = CAPCITY;
  while (i > 0 && j > 0) {
    if (help[i][j] != help[i - 1][j]) {
      selected_bool[i - 1] = 1;
      j -= weights[i - 1];
    }
    i--;
  }

  return help[ITEMS][CAPCITY];
}
double fmax(double x, double y) {
  if(x>y) return x;
  return y;
}

    