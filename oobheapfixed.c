#include <stdio.h>
#include <stdlib.h>

int main() {
    int* v = malloc(5*sizeof(int));
    printf("%d", v[4]);
    free(v);
}
