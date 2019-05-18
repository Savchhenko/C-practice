/*
 ============================================================================
 Name        : Calculator.c
 Author      : Bear
 Version     :
 Copyright   : It belongs to Alexandra Savchenko
 Description : Simple Calculator with 6 options (+,-,*,/,^,!)
 ============================================================================
 */
/* This work belongs to the student Alexandra Savchenko */
/* C Program - Simple Calculator */

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
     int k; //переменная, отвечающая за продолжение или остановку программы
     do {
			float a, b, operation;
			float res = 1;
			char choice;

			printf("'+' - Addition\n'-' - Subtraction\n'*' - Multiplication\n'/' - Division\n'^' - Exponentiation\n'!' - Factorial\n"); //пользовательский интерфейс
			printf("Enter your choice : ");
			scanf(" %c",&choice);
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
			printf("\n-------------------------------------\n");


			printf("Enter 1, if you want to continue;\nEnter 0, if you want to end:"); //запрос на повторение работы
			scanf(" %i", &k);
			printf("-------------------------------------\n");

			if( k == 1)   //условие для повторения работы
		       continue;
			else
				break;
      }
      while(1); // цикл do-while, позволяющий вернуться в начало программы
	return EXIT_SUCCESS;
}
