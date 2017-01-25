#include <stdio.h>
#include <math.h>

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
  if(n>2) {
    printf("2 ");
  }
  for(int i=3; i<n; i+=2) {
    if(isprime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
