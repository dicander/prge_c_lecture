#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

static int LINE_WIDTH = 80;

int readInt() {
  char* line = (char*)malloc(LINE_WIDTH*sizeof(char));
  for(int i=1; i<=10; ++i) {
    fgets(line, LINE_WIDTH, stdin);
    for(int i=0; i<LINE_WIDTH; ++i) {
      //printf("position %d, %d\n",i,(int)line[i]);
      if(line[i]=='\0' || line[i]== 10) {
        int answer =  atoi(line);
        free(line);
        return answer;
      }
      if(!isdigit(line[i])) {
        break;
      }
    }
    printf("Attempt %d: %s is not an integer.\n",
            i, line);
  }
  printf("10 attempts and still no integer.\n");
  exit(1);
}


int main () {
  //printf("%d\n", readInt());
  srand(((unsigned int)time(NULL))%1354);
  int answer = 1+rand()%100;
  int n_guesses = 0;
  int guess = -1;
  printf("Jag tänker på ett tal mellan 1 och 100.");
  while(1) {
    printf("Gissa talet: ");
    guess = readInt();
    ++n_guesses;
    if(answer == guess) {
      printf("Rätt! Efter %d gissningar.\n",
        n_guesses);
        exit(0);
    } else if (answer < guess) {
      printf("Jag tänker på ett mindre tal!\n");
    } else {
      printf("Jag tänker på ett större tal!\n");
    }
  }
}
