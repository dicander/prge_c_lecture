#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(int a) {
  return a;
}

int calculate(int a, int b) {
  return a + b;
}

int main(){
  char src[50], dest[50];

  strcpy(src,  "42");
  strcpy(dest, "The answer is: ");
  strcat(dest, src);
  printf("%s\n", dest);
  char* announcement = "The answer is: ";
  char* the_answer = "42";
  char three = '3';
  int n = (int)(three - '0');
  int from_string = atoi(the_answer);
  //char* total = announcement + the_answer;
  printf("%d\n", n + from_string);
}
