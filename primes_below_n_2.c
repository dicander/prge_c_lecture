#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d", &n);
  char* v = (char*)malloc((n/2)*sizeof(char));
  //printf("Survived malloc!\n");
  for(int i=0; i<n/2; ++i) {
    v[i] = 1U;
  }
  //printf("Survived initialization!\n");
  //int limit = 1+(int)sqrt((double)n);
  for(int divisor = 3; ((int)divisor)*((int)divisor)<=n; divisor+=2) {
    if(v[divisor/2]==0U) continue;
    int index = divisor*divisor;
    int doublediv = divisor*2;
    for(;index <n; index+=doublediv) {
      //if(index<0) printf("evil %d\n", divisor);
      //if(index==13 || index == 12) {
      //  printf("%d %d\n", divisor, index);
      //}
      v[index/2] = 0U;
    }
  }
  //printf("Survived!\n");
  if(n>2) {
    printf("2 ");
  }
  for(int i = 3; i<n; i+=2) {
    if(v[i/2]) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
