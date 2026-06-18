#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void f(int* a, int b, int c, int** d, int* e, int** colSizes) {
    if (b == c) {
        d[*e] = (int*)malloc((c + 1) * sizeof(int));
        (*colSizes)[*e] = (c + 1); // Har row ka size batana zaroori hai
        for (int i = 0; i <= c; i++) d[*e][i] = a[i];
        (*e)++;
        return;
    }
    for (int i = b; i <= c; i++) {
        int skip = 0;
        for (int j = b; j < i; j++) {
            if (a[j] == a[i]) { skip = 1; break; }
        }
        if (skip) continue;
        int t = a[b]; a[b] = a[i]; a[i] = t;
        f(a, b + 1, c, d, e, colSizes);
        t = a[b]; a[b] = a[i]; a[i] = t;
    }
}
int** permuteUnique(int* a, int b, int* c, int** d) {
    qsort(a, b, sizeof(int), compare);
    int e = 1;
    for (int i = 1; i <= b; i++) e *= i;
    int** g = (int**)malloc(e * sizeof(int*));
    *d = (int*)malloc(e * sizeof(int)); // Column sizes ke liye memory
    int h = 0;
    f(a, 0, b - 1, g, &h, d);
    *c = h;
    return g;
}