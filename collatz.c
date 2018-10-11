#include <stdio.h>

int scanInput();
int isInputInvalid();
int collatzStep();
void collatzSprint();
int collatzSprintCount();

void main(int argc, char const *argv[]) {
  int num = 0;

  num = scanInput();
  if (isInputInvalid(num)) {
    return;
  }


  return;
}

int collatzSprintCount(int d) {
  int out = 0;
  while (num != 1) {
    num = collatzStep(num);
    out++;
  }
  return out;
}

void collatzSprint(int d) {
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
