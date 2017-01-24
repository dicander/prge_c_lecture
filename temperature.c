#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d\n", &n);
  //int* vector = malloc(n*sizeof(int));
  int counter=0;
  for(int i=0; i<n; ++i) {
    int temperature;
    scanf("%d",&temperature);
    if (temperature<0) {
      ++counter;
    }
  }
  printf("%d\n",counter);
}
