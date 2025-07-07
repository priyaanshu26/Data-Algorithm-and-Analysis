#include <stdio.h>
#include <time.h>

#define N 1000

void pivot(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        pivot(arr, low, high);
        int pi = low + (high - low) / 2;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int readArrayFromFile(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
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

int main()
{
    int arr[N];
    clock_t start, end;
    double time_taken;

    // best case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/best_case_1000.txt", arr, N))
    {
        start = clock();
        quickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)end - start) / CLOCKS_PER_SEC * 1000;
        printf("Best Case: %f\n", time_taken);
    }

    // average case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/average_case_1000.txt", arr, N))
    {
        start = clock();
        quickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)end - start) / CLOCKS_PER_SEC * 1000;
        printf("Average Case: %f\n", time_taken);
    }

    // worst case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/worst_case_1000.txt", arr, N))
    {
        start = clock();
        quickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)end - start) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case: %f\n", time_taken);
    }
}