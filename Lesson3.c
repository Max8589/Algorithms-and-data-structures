
#include <stdio.h>
#include <stdlib.h>

void fillArray(int* arr, int lenght) {
    int i;
    for (i = 0; i < lenght; i++) {
        arr[i] = rand() % lenght;
    }
}

void printArray(int* arr, int lenght) {
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

//1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
int bubbleSort(int* arr, int lenght) {
    int i = 0;
    int j = 0;
    int count = 0;
    int isSort = 0;
    while (i < lenght) {
        j = 0;
        isSort = 0;
        while (j < (lenght - i - 1)) {       // -i отсортированные элементы
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                count ++;
                isSort = 1;
            }
            count ++;
            j++;
        }
        if (isSort == 0) { // break; если не было перестановок
            break;
        }
       count ++;
       i++;
    }
return count;
}

//2. *Реализовать шейкерную сортировку.
int shakerSort(int* arr, int lenght) {
    int i;
    int min = 0;
    int max = lenght - 1;
    int count = 0;
    
    while (min < max) {
        i = min;
        while (i < max) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
            count ++;
            i++;
        }
        max--;
        
        i = max;
        while (i > min) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
            }
            count ++;
            i--;
        }
        min++;
    }
return count;
}

//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
int binSearch(int* arr, int lenght, int target) {
    int min = 0;
    int max = lenght - 1;
    int mid = 0;
    
    while (min <= max) {
        mid = (min + max) / 2;
        if (target < arr[mid]) {
            max = mid - 1;
        } else if (target > arr[mid]) {
            min = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

int main(int argc, const char * argv[]) {
    int e = 34;
    int arr[e];
    fillArray(arr, e);
    printArray(arr, e);
    printf("Count: %d\n", bubbleSort(arr, e)); // O(n*n)
    printArray(arr, e);
    printf("\n");
 
    
    fillArray(arr, e);
    printArray(arr, e);
    printf("Count: %d\n", shakerSort(arr, e)); // O(n*n)
    printArray(arr, e);
    printf("\n");
    
    fillArray(arr, e);
    printArray(arr, e);
    printf("Index: %d, target: %d\n", binSearch(arr, e, 30), arr[binSearch(arr, e, 30)]);
    return 0;
}
