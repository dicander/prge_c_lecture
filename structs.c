#include <stdio.h>
#include <stdlib.h>
struct foo {
  int first;
  int second;
};

typedef struct foo foo;

void swapper(foo* victim) {
  int temp = victim->first;
  victim->first = victim->second;
  victim->second = temp;
}

void printer(foo* victim) {
  printf("%d %d\n", victim->first, victim->second);
}

void setFirst(foo* victim, int value) {
  victim->first = value;
}

int main() {
  foo* current = (foo*)malloc(sizeof(foo));
  foo* evil = (foo*)malloc(sizeof(char));
  current->first = 13;
  current->second = 42;
  printer(current);
  swapper(current);
  printer(current);
  free(current);
}
