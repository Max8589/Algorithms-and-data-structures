
#include <stdio.h>
#include <stdlib.h>

void fillArray(int arr[], int lenght) {
    int i;
    for (i = 0; i < lenght; i++) {
        arr[i] = rand() % lenght;
    }
}

void printArray(int arr[], int lenght) {
    int i;
    for (i = 0; i < lenght; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n ");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//1. Реализовать сортировку подсчетом.
int countingSort(int arr[], int lenght) {
    int max_value = 1000000;
    int counts[max_value];
    for (int i = 0; i < max_value; i++)
        counts[i] = 0;
    
    for (int i = 0; i < lenght; i++)
        counts[arr[i]]++;
    
    int count = max_value + lenght;
    int index = 0;
    for (int i = 0; i < max_value; i++) {
        while (counts[i] > 0) {
            counts[i]--;
            arr[index++] = i;
            count++;
        }
    }
    return count;
}

//2. Реализовать быструю сортировку.
void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int divider = start;
        int i = start;
        int j = end;
        while (i < j){
            while (arr[i] <= arr[divider] && i < end)
                i++;
            while (arr[j] > arr[divider])
                j--;
            if (i < j) {
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[divider], &arr[j]);
        quicksort(arr, start, j-1);
        quicksort(arr, j+1, end);
    }
}

int main(int argc, const char * argv[]) {
    int e = 100;
    int arr[e];
    
    fillArray(arr, e);
    printArray(arr, e);
    printf("Count: %d\n", countingSort(arr, e));
    printArray(arr, e);
    printf("\n");
    
    fillArray(arr, e);
    printArray(arr, e);
    quicksort(arr, 0, e - 1);
    printArray(arr, e);
    printf("\n");
    
    return 0;
}
