/*
 ============================================================================
 Name        : Calculator.c
 Author      : Bear
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/* C Program - Simple Calculator */

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a, b, operation;
	float res = 1;
	char choice;

	printf("'+' - Addition\n" );
	printf("'-' - Subtraction\n");
	printf("'*' - Multiplication\n");
	printf("'/' - Division\n");
	printf("'^' - Exponentiation\n");
	printf("'!' - Factorial\n");
	printf("Enter your choice : ");
	scanf("%c",&choice);
	switch(choice)
		{
		case '+' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a+b; // сумма двух чисел
			printf("Result = %f",operation);
			break;
		case '-' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a-b;  // разность двух чисел
			printf("Result = %f",operation);
			break;
		case '*' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a*b;  // умножение двух чисел
			printf("Result = %f",operation);
			break;
		case '/' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a/b;  // деление двух чисел
			printf("Result = %f",operation);
			break;
		case '^' :
			printf("Enter number : ");
			scanf("%f",&a);
			printf("Enter degree : ");
			scanf("%f",&b);
			for(int i=1; i<=b; i++) // цикл для переменной i от 1 до b с шагом 1
				  {
					res = res * a ; // возведение в степень
				  }
			  printf("Result = %f\n", res);
			break;
		case '!' :
			printf("Enter number : ");
			scanf("%f",&a);
			for(int i=1; i<=a; i++) // цикл для переменной i от 1 до a с шагом 1
				  {
					res = res * i; // считаем факториал числа
				  }
			printf("Result = %f\n", res);
			break;
		default : printf("Wrong choice.");
			break;
		}
	printf("\n----------------------------------------\n");

	return EXIT_SUCCESS;
}
