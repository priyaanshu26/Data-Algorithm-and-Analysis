#include <stdio.h>
#include <time.h>

#define N 100

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/best_case_100.txt", arr, N)){
        start = clock();
        insertionSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Best Case: %f", time_taken);
    }

    //average case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/average_case_100.txt", arr, N)){
        start = clock();
        insertionSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Average Case: %f", time_taken);
    }

    //worst case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/worst_case_100.txt", arr, N)){
        start = clock();
        insertionSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Worst Case: %f", time_taken);
    }
}