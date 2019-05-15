/*
 ============================================================================
 Name        : stepen'_for.c
 Author      : Bear
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* Программа,возводящая число в степень через цикл for */

#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
int main() {
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  int k;   // объявляем целую переменную k -число,которое возводится в степень
  int a;   // объявляем целую переменную а -степень
  int res = 1;

  printf("k = ");
  scanf("%d", &k);   // вводим значение переменной k
  printf("a = ");
  scanf("%d", &a);   // вводим значение переменной а
  for(int i=1; i<=a; i++) // цикл для переменной i от 1 до а с шагом 1
	  {
		res = res * k ; // возведение в степень
	  }
  printf("result = %d\n", res); // вывод результата

  return 0;
}
