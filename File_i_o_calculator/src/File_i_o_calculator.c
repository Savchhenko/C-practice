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
	int size; //размерность векторов
	fscanf(fin, "%i", &size); //прочли символ = размер векторов
	A = malloc(size *sizeof(float)); //выделение памяти под векторы
    B = malloc(size *sizeof(float));
    for (int i=0; i<size; i++)
        fscanf(fin,"%f", &A[i]);
    for (int k=0; k<size; k++)
        fscanf(fin,"%f", &B[k]);

    fscanf (fin,"%i",&first) ;
        switch (first){
            case '+':

            case '-':

            case '*':
            }
}









int main(void) { //главная функция

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *fin, *fout; //указатели для обоих файлов
	char first, second; // переменные, отвечающие за первый и второй символ в файле
	fin = fonpen("content.txt","r");
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
    	simple_calc(fin, fout, second);
    }
    else {
    	printf("Error: invalid value in input file.");
    }

    fclose(fin); //закрыли оба файла
	fclose(fout);

	return EXIT_SUCCESS;
}


