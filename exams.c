#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

void solve(int size, int* v) {
  qsort(v, size, sizeof(int), compare_ints);
}

int main() {
  int n;
  scanf("%d", &n);
  int* v = (int*)malloc(n*sizeof(int));
  for(int i=0; i<n; ++i) {
    scanf("%d", &(v[i]));
  }
  //for(int i=0; i<n; ++i) {
  //  printf("%d ", v[i]);
  //}
  //printf("\n");
  solve(n, v);
  for(int i=0; i<n; ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
  free(v);
}
