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
	char choice;

	printf("'+' - Addition\n" );
	printf("'-' - Subtraction\n");
	printf("'*' - Multiplication\n");
	printf("'/' - Division\n");
	printf("Enter your choice : ");
	scanf("%c",&choice);
	switch(choice)
		{
		case '+' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a+b;
			printf("Result = %f",operation);
			break;
		case '-' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a-b;
			printf("Result = %f",operation);
			break;
		case '*' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a*b;
			printf("Result = %f",operation);
			break;
		case '/' :
			printf("Enter two number : ");
			scanf("%f%f",&a,&b);
			operation=a/b;
			printf("Result = %f",operation);
			break;
		default : printf("Wrong choice.");
			break;
		}
	printf("\n------------------------------------\n");

	return EXIT_SUCCESS;
}
