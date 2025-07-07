#include <stdio.h>
#include <time.h>

#define N 100000

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        //Swap minimum element
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
void print_array(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i] );
    }
    printf("\n");
}

int readArrayFromFile(const char *filename, int arr[], int n){
    FILE *f = fopen(filename, "r");
    if (!f){
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d ", &arr[i]);
    }
    fclose(f);
    return 1;
    
}

int main(){
    int arr[N];
    clock_t start,end;
    double time_taken;

    //best case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/worst_case_100000.txt", arr, N)){
        start = clock();
        selectionSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Best Case: %f", time_taken);
    }

    //average case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/average_case_100000.txt", arr, N)){
        start = clock();
        selectionSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Average Case: %f", time_taken);
    }

    //worst case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/worst_case_100000.txt", arr, N)){
        start = clock();
        selectionSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Worst Case: %f", time_taken);
    }
}