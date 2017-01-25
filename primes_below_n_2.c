#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isprime(int n){
  int limit = fmax(n, 1+(int)sqrt((double)n));
  if(n%2==0) {
    return 0;
  }
  for(int divisor = 3; divisor < limit; divisor+=2) {
    if(n%divisor == 0) {
      return 0;
    }
  }
  return 1;
}

int main(){
  int n;
  scanf("%d", &n);
  int* v = (int*)malloc(n*sizeof(int)+10);
  //printf("Survived malloc!\n");
  for(int i=0; i<n+5; ++i) {
    v[i] = 1;
  }
  //printf("Survived initialization!\n");
  int limit = fmax(n, 1+(int)sqrt((double)n));
  for(int divisor = 3; divisor<limit; divisor+=2) {
    //if(v[divisor]==0) continue;
    int index = divisor*divisor;
    for(; index>0 && index <n; index+=divisor) {
      v[index] = 0;
    }
  }
  //printf("Survived!\n");
  if(n>2) {
    printf("2 ");
  }
  for(int i = 3; i<n; i+=2) {
    if(v[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
