/*
 ============================================================================
 Name        : File_i_o_calculator.c
 Author      : Bear
 Copyright   : This work belongs to the student Savchenko Alexandra.
 Description : Это программа,которая считывает из внешнего файла данные,которые определяют тип калькулятора
               (калькулятор с обычными числами или векторный калькулятор), операцию и численные значения,с которыми будет проводиться операция.
               Результат вычислений выводится в другой внешний файл.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//функция с векторными операциями
void vector_calc(FILE *fin, FILE *fout, char first) {
	float *A, *B;
	float answer;
	int size; //размерность векторов
	fscanf(fin, "%i", &size); //прочли символ - размерность векторов
	A = calloc(size, sizeof(float)); //выделение память под векторы
    B = calloc(size, sizeof(float));
    for (int i=0; i<size; i++) //считываем координаты вектора А
        fscanf(fin, "%f", &A[i]);
    for (int k=0; k<size; k++) //считываем координаты вектора В
        fscanf(fin, "%f", &B[k]);

    fscanf(fin,"%c",&first);
	switch (first){
		case '+':
			fprintf(fout, "(");
			for (int i = 0; i < size; i++){
				fprintf(fout," %.2f ", A[i]);
			}
			fprintf(fout, ") + (");
			for (int i = 0; i < size; i++){
				fprintf(fout," %.2f ", B[i]);
			}
			fprintf(fout, ") = (");
			for (int i = 0; i < size; i++) {
				answer = A[i] + B[i];
				fprintf(fout," %.2f ", answer);
			}
			fprintf(fout, ")");

			free(A);
			free(B);
			break;
		case '-':
			fprintf(fout, "(");
			for (int i = 0; i < size; i++){
				fprintf(fout," %.2f ", A[i]);
			}
			fprintf(fout, ") - (");
			for (int i = 0; i < size; i++){
				fprintf(fout," %.2f ", B[i]);
			}
			fprintf(fout, ") = (");
			for (int i = 0; i < size; i++) {
				answer = A[i] - B[i];
				fprintf(fout," %.2f ", answer);
			}
			fprintf(fout, ")");

			free(A);
			free(B);
			break;
		case '*':
			fprintf(fout, " ( ");
			for (int i = 0; i < size; i++){
				fprintf(fout," %.2f ", A[i]);
			}
			fprintf(fout, " ) * (");
			for (int i = 0; i < size; i++){
				fprintf(fout," %.2f ", B[i]);
			}
			fprintf(fout, " ) = ");
			answer = 0;
			for (int i = 0; i < size; i++) {
				answer = answer + (A[i] * B[i]);
			}
			fprintf(fout," %.2f", answer);

			free(A);
			free(B);
			break;
		}
}

//функция простого численного калькулятора
void simple_calc(FILE *fin, FILE *fout, char first) {
	float *A, *B;
	float answer;
	A = calloc(1, sizeof(float));
	 fscanf(fin, "%f ", A);
	B = calloc(1, sizeof(float));
	 fscanf(fout, "%f ", B);

	switch(first){
	case '+':
		answer = *A + *B;
		fprintf(fout, "%.0f %c %.0f = %f", *A, first, *B, answer); //делаем запись результата операции в файл
		free(A);
		free(B);
		break;
	case '-':
		answer = *A - *B;
		fprintf(fout, "%.0f %c %.0f = %f", *A, first, *B, answer);
		free(A);
		free(B);
		break;
	case '*':
		answer = *A * *B;
		fprintf(fout, "%.0f %c %.0f = %f", *A, first, *B, answer);
		free(A);
		free(B);
		break;
	case '/':
		answer = *A / *B;
		fprintf(fout, "%.0f %c %.0f = %f", *A, first, *B, answer);
		free(A);
		free(B);
		break;
	case '^':
		answer = 1;
		for (int i = 1; i <= *B; i++) {
			answer = answer * *A;
		}
		fprintf(fout, "%.0f %c %.0f = %f", *A, first, *B, answer);
		free(A);
		free(B);
		break;
	case '!':
		answer = 1;
		for(int i=1; i <= *A; i++) {
		   answer = answer * i;
	    }
		fprintf(fout, "%.0f! = %f", *A, answer);
		free(A);
		break;
	}
}

//главная функция
int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *fin, *fout; //указатели для обоих файлов
	char first, second; // переменные, отвечающие за первый и второй символ в файле(операция и тип калькулятора)
	fin = fopen("content.txt", "r");
	if (fin == NULL)
	    {
	         puts("Input file cannot be opened.");
	    }
	fout = fopen("output.txt", "w");
	fscanf(fin, "%c %c", &first, &second); //прочли первые два символа и присвоили их переменным
	printf("Type of calculator: %c\n", second);
	printf("Operation: %c\n", first);
	//выбор калькулятора:
    if(second == 'v') {
    	vector_calc(fin, fout, first);
    }
    else  {
    	simple_calc(fin, fout, first);
    }
    printf("See the result in the external file.");

    fclose(fin); //закрыли оба файла
	fclose(fout);

	return EXIT_SUCCESS;
}


