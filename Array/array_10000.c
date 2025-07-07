#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void write_best_case(){
    FILE *f = fopen("best_case_10000.txt","w");
    for (int i = 1 ; i <= N ; i++){
        fprintf(f, "%d ", i);
    }
    fclose(f);
    return;
}


void write_worst_case(){
    FILE *f = fopen("worst_case_10000.txt","w");
    for (int i = N ; i >= 1 ; i--){
        fprintf(f, "%d ", i);
    }
    fclose(f);
    return;
}

void write_average_case(){
    int array[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = i+1;
    }

    //Swap array
    srand(time(NULL));
    for (int i = N - 1; i > 0 ; i--)
    {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    FILE *f = fopen("average_case_10000.txt", "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(f, "%d ", array[i]);
    }
    fclose(f);
}

void main(){
    write_best_case();
    write_worst_case();
    write_average_case();
}