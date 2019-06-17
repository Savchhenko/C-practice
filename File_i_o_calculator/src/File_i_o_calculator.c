/*
 ============================================================================
 Name        : File_i_o_calculator.c
 Author      : Bear
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//функция с векторными операциями
void vector_calc(FILE *fin, FILE *fout, char first) {
	float *A, *B;
	float answer;
	int size; //размерность векторов
	fscanf(fin, "%i", &size); //прочли символ = размерерность векторов
	A = malloc(size *sizeof(float)); //выделение памяти под векторы
    B = malloc(size *sizeof(float));
    for (int i=0; i<size; i++)
        fscanf(fin,"%f", &A[i]);
    for (int k=0; k<size; k++)
        fscanf(fin,"%f", &B[k]);

    fscanf(fin,"%c",&first);
	switch (first){
		case '+':
			fprintf(fout, "(");
			for (int i = 0; i < size; i++){
				fprintf(fin," %.2f ", A[i]);
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

			free(A);
			free(B);
			break;
		case '*':

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
	 fscanf(fin, "%f", A);
	B = calloc(1, sizeof(float));
	 fscanf(fout, "%f", B);

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
	char first, second; // переменные, отвечающие за первый и второй символ в файле
	fin = fopen("content.txt","r");
	if (fin == NULL)
	    {
	         puts("Input file cannot be opened");
	    }
	fout = fopen("output.txt", "w");
	if (fout == NULL)
	    {
	       puts("Output file cannot be opened");
	    }

	fscanf(fout,"%c %c", &first, &second); //прочли первые два символа и присвоили их переменным
    if(second == 'v') {
    	vector_calc(fin, fout, first);
    }
    if(second == 's') {
    	simple_calc(fin, fout, first);
    }
    else {
    	printf("Error: invalid value in input file.");
    }

    fclose(fin); //закрыли оба файла
	fclose(fout);

	return EXIT_SUCCESS;
}


