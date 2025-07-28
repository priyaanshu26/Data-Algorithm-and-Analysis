#include <stdio.h>
#include <time.h>

#define N 100000

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/best_case_100000.txt", arr, N))
    {
        start = clock();
        mergeSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)end - start) / CLOCKS_PER_SEC * 1000;
        printf("Best Case: %f\n", time_taken);
    }

    // average case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/average_case_100000.txt", arr, N))
    {
        start = clock();
        mergeSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)end - start) / CLOCKS_PER_SEC * 1000;
        printf("Average Case: %f\n", time_taken);
    }

    // worst case
    if (readArrayFromFile("E:/Darshan University/Sem-5/DAA/LAB/Array/worst_case_100000.txt", arr, N))
    {
        start = clock();
        mergeSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)end - start) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case: %f\n", time_taken);
    }
}