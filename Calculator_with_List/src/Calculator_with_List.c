/*
 ============================================================================
 Name        : Calculator_with_List.c
 Author      : Bear
 Copyright   : This work belongs to the student Alexandra Savchenko
 Description : Программа калькулятора,которая читает данные из внешнего файла и записывает их в список element,после чего файл закрывается,
               проводятся вычисления, и их результаты заносятся в новый список list_with_result и выводятся в другой внешний файл.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//создаем список(в виде структуры),в котором будут храниться данные
typedef struct element {
    char choice; //первый символ в файле,отвечающий за выбор операции
    char type; //второй символ,отвечающий за тип калькулятора (v/s)
    int number; //третий символ,отвечающий за размерность векторов (в случае численного калькулятора number=1)
    float *value1; //указатели на массивы, в которых сохраняются значения координат векторов
    float *value2;
    struct element *next;
} element;
element *last = NULL;
element *head = NULL;

//создаем список,в котором будут храниться данные с результатами вычислений
typedef struct list_with_result {
    char oper;
    int size;
    float *result;
    struct list_with_result *next;
} res;
res *lastres = NULL;
res *headres = NULL;

//функция,заполняющая список element данными из файла
void filling( FILE* fin) {
    element *tmp = (element*)malloc(sizeof(element));
    fscanf(fin, " %c %c", &tmp->choice, &tmp->type);
    if (tmp->type == 'v')
        fscanf(fin, "%d", &tmp->number);
    else
        tmp->number = 1;
    tmp->value1 = malloc(tmp->number*sizeof(float)); //выделили память под координаты первого вектора
    tmp->value2 = malloc(tmp->number*sizeof(float)); //выделили память под координаты второго вектора
    for (int i = 0; i < tmp->number; i++)
        fscanf(fin, "%f", &tmp->value1[i]);
    if (tmp->choice !='!')
    {
        tmp->value2 = malloc(tmp->number*sizeof(float));
        for (int i = 0; i < tmp->number; i++)
            fscanf(fin, "%f", &tmp->value2[i]);
    }
if  (last != NULL)
{
    last->next = tmp;
    tmp->next = NULL;
    last = tmp;
}
else {
    head = tmp; //передали head,который был пустой,значение переменной
    last = tmp; //передали last,который был пустой,значение переменной
}
}
void fill_res ()
{
    res *tmp_res = (res*)malloc(sizeof(element));
    tmp_res->result = malloc(last->number*sizeof(float));
    tmp_res->size = last->number;
    tmp_res->oper = last->type;
    switch(last->type)
    {
        case 's' :
        	switch(last->choice)
			{
				case '+' :
					tmp_res->result[0] = last->value1[0] + last->value2[0];
					break;
				case '-' :
					tmp_res->result[0] = last->value1[0] - last->value2[0];
					break;
				case '!' :
					tmp_res->result[0] =1 ;
					for (int n = 0; n<=last->value1[0]; n++)
					 {
									 tmp_res->result[0]=tmp_res->result[0]*n;
					 }
					break;
				case '*' :
					tmp_res->result[0] = last->value1[0] * (last->value2[0]);
					break;
				case '/' :
					tmp_res->result[0] = last->value1[0] / last->value2[0];
					break;
				case '^' :
					tmp_res->result[0] = last->value1[0] ;
					for (float n = 1 ; n<last->value2[0]; n++)
					{
						tmp_res->result[0]= tmp_res->result[0] * last->value1[0];
					}
					break;
        }break;
        case 'v' :switch(last->choice)
        {
            case '+':
                for (int m = 0;m<last->number;m++)
                {
                    tmp_res->result[m]= last->value1[m] +last->value2[m];
                }
                break;
           case '-':
               for (int m = 0;m<last->number;m++)
               {
                   tmp_res->result[m]= last->value1[m] - last->value2[m];
               }
               break;
          case '*':
              for (int m = 0;m<last->number;m++)
               {
                  tmp_res->result[m]=last->value1[m] * last->value2[m];
               }
              break;
        }
    }
	if  (lastres != NULL)
	{
		lastres->next = tmp_res;
		tmp_res->next = NULL;
		lastres = tmp_res;
	}
	else {
		headres = tmp_res;
	  lastres = tmp_res;
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


    FILE *fin;
    fin = fopen("input.txt","r");
    while (!feof(fin)) //пока не конец файла
    {
        filling( fin); //заполняем список данными
    }
    fclose(fin);
    last = head;
    while(last !=NULL)
    {
        fill_res() ; //делаем вычисления и заносим их в другой список
        last =last->next;
    }
    lastres = headres;
    FILE  *fout;
    fout = fopen("output.txt","w");
    while(lastres !=NULL)
    {
        for (int y =0;y<lastres->size;y++)
        {
            fprintf (fout,"%.2f ",lastres->result[y]);
        }
        lastres =lastres->next;
    }
        fclose(fout);
    return EXIT_SUCCESS;
}
