#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n, int *check);
int search(int *a, int n);
void output(int a);
double mean(int *a, int n);
double variance(int n);

int main() {
  int n, data[NMAX], check = 0;
  input(data, &n, &check);
  if (check == 0) {
    output(search(data, n));
  }
}

int input(int *a, int *n, int *check) {
  printf("Напиши сколько элементов будешь вводить: ");
  if (scanf("%d", n) == 1 && getchar() == '\n' && *n <= 30) {
    for (int i = 0; i < *n; i++) {
      printf("Введи число %d: ", i + 1);
      if (scanf("%d", &a[i]) != 1 || getchar() != '\n') {
        printf("n/a\n");
        *check = 1;
        break;
      }
    }
  } else {
    printf("n/a\n");
    *check = 1;
  }
  return 0;
}

void output(int a) { printf("%d\n", a); }

int search(int *a, int n) {
  for (int i = 0; i < n; i++) {
    double mean_value = mean(a, n);
    if ((a[i] % 2 == 0) && (a[i] >= mean_value) &&
        (a[i] <= mean_value + 3 * sqrt(variance(n))) && (a[i] != 0)) {
      return a[i];
    }
  }
  return 0;
}
double mean(int *a, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum / n;
}

double variance(int n) { return ((n * n) - 1) / 12.0; }
