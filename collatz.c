#include <stdio.h>

int scanInput();
int isInputInvalid();
int collatzStep();
void sprint();
int sprintCount();
void sprintRange();
void sprintRangeCount();
void sprintRangeMax();


void main(int argc, char const *argv[]) {
  int num = 0;

  //num = scanInput();
  //if (isInputInvalid(num)) {
  //  return;
  //}

  sprintRangeCount(22,222);
  sprintRangeMax(22,222);

  return;
}

void sprintRangeMax(int a, int b) {
  int swap = 0, max = 0;
  for (int i = a; i < b; i++) {
    swap = sprintCount(i);
    if (swap > max) {
      max = swap;
    }
  }
  printf("max number of iterations is: %d\n", max);
  return;
}

void sprintRangeCount(int a, int b) {
  int swap = 0;
  for (int i = a; i < b; i++) {
    swap = sprintCount(i);
    printf(" %d \t %d\n", i,swap);
  }
  return;
}

void sprintRange(int a, int b) {
  for (int i = a; i < b; i++) {
    sprint(i);
  }
  return;
}

int sprintCount(int num) {
  int out = 0;
  while (num != 1) {
    num = collatzStep(num);
    out++;
  }
  return out;
}

void sprint(int num) {
  while (num != 1) {
    num = collatzStep(num);
    printf("%d\n", num);
  }
}

int collatzStep(int d) {
  if (d%2==0) {
    d=d/2;
  } else {
    d=d*3+1;
  }
  return d;
}

int isInputInvalid(int d) {
  if (d < 1 || d > 1000) {
    return 1;
  }
  return 0;
}

int scanInput() {
  int d = 0;
  printf("%s\n", "Enter number in range 1 to 1000");
  scanf("%d", &d);
  return d;
}
