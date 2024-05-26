#ifndef MY_MAT_H
#define MY_MAT_H

#define N 10
#define ITEMS 5
#define CAPCITY 20
#define NAMES 20

int min(int a, int b);
void buildMatrix();
int isPath(int i, int j);
int shortestPath(int i, int j);
int FloydWarshall(int i, int j);
int knapSack (int weights[], int values[] , int selected_bool[]);
double fmax(double x, double y);

#endif