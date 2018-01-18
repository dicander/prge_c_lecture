#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[11] = {1,2,3,4,5,6,7,8,9,10,11};
    for(int i=0; i<4; ++i) {
        printf("v[%d] = %d\n", i, v[i]);
    }
    printf("%d\n", v[10]);
}
