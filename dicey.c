#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int* v = (int*) malloc((m+n+1)*sizeof(int));
  int total = m + n;
  for(int i = 0; i<= total; ++i) {
    v[i] = 0;
  }
  int highest_number = 0;
  for(int i = 1; i<= m; ++i) {
    for(int j = 1; j<= n; ++j) {
      int index = i+j;
      v[index]++;
      if(v[index] > highest_number) {
        highest_number = v[index];
      }
    }
  }
  for(int i=2; i<=total; ++i) {
    if(v[i] == highest_number) {
      printf("%d\n", i);
    }
  }
  free(v);
}
