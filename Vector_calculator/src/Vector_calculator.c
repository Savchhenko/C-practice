/*
 ============================================================================
 Name        : Vector_calculator.c
 Author      : Bear
 Version     :
 Copyright   : This work belongs to the student Alexandra Savchenko
 Description : Vector Calculator in C, Ansi-style
 ============================================================================
 */
/* C программа - векторный калькулятор с использованием указателей, выполняющая три операции: сложение,вычитание и скалярное произведение векторов с заранее неизвестной длиной */


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int k; //переменная, отвечающая за продолжение или остановку программы
	do {
		float *A, *B;
		int size; //размерность векторов
		printf("Enter the number of coordinates of vectors: ");
		scanf("%i", &size);
		if (size != 0) {
			A = calloc(size, sizeof(A)); //выделение памяти под вектор
			B = calloc(size, sizeof(B));
		}
		printf("Enter coordinates of first vector: ");
		for (int i = 0; i < size; i++) { //заполнение элементов массива значениями координат
			scanf("%f", &A[i]);
		}
		printf("Enter coordinates of second vector: ");
		for (int i = 0; i < size; i++ ) {
			scanf("%f", &B[i]);
		}

		char choice;
		printf("\"+\"-Vector addition\n\"-\"-Vector difference\n\"*\"-Scalar multiplication of vectors\n ");
		printf("Choose the operation:\n");
		scanf(" %c", &choice);

		float t = 0; //переменная,участвующая в скалярном умножении
		switch (choice) {
		case '+':
			printf("New vector: ");
			for (int i = 0; i < size; i++) {
				printf("%.1f", A[i] + B[i]); //сложение элементов массива(координат)
			}
			break;
		case '-':
			printf("New vector: ");
			for (int i = 0; i < size; i++) {
				printf("%.1f", A[i] - B[i]);//вычитание
			}
			break;
		case '*':
			for (int i = 0; i < size; i++) {
				t = t + A[i] * B[i];//умножение
			}
			printf("%.1f", t);
			break;
		}
		free(A);
		free(B);
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
