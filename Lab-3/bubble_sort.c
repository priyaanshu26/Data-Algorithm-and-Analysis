#include <stdio.h>
#include <time.h>

#define N 1000

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Flag to check if a swap occurred
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set flag to true
            }
        }
        // If no two elements were swapped, the array is sorted
        if (swapped == 0) {
            break;
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
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/best_case_1000.txt", arr, N)){
        start = clock();
        bubbleSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Best Case: %f", time_taken);
    }

    //average case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/average_case_1000.txt", arr, N)){
        start = clock();
        bubbleSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Average Case: %f", time_taken);
    }

    //worst case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/worst_case_1000.txt", arr, N)){
        start = clock();
        bubbleSort( arr, N);
        end = clock();
        time_taken = ((double) end - start) / CLOCKS_PER_SEC *1000;
        printf("Worst Case: %f", time_taken);
    }
}