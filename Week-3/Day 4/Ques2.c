#include <stdio.h>
#include <stdlib.h>
void f(int* a, int b, int c, int* d, int e, int** g, int* h, int** colSizes) {
    g[*h] = (int*)malloc(e * sizeof(int));
    (*colSizes)[*h] = e;
    for (int i = 0; i < e; i++) g[*h][i] = d[i];
    (*h)++;

    for (int i = c; i < b; i++) {
        d[e] = a[i];
        f(a, b, i + 1, d, e + 1, g, h, colSizes);
    }
}
int** subsets(int* a, int b, int* c, int** d) {
    int e = 1 << b; // Power set size is 2^n
    int** g = (int**)malloc(e * sizeof(int*));
    *d = (int*)malloc(e * sizeof(int));
    int* temp = (int*)malloc(b * sizeof(int));
    int h = 0;
    f(a, b, 0, temp, 0, g, &h, d);
    *c = h;
    free(temp);
    return g;
}