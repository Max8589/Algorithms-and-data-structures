

#include <stdio.h>

//1 Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
int decToBin(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 2 + decToBin(n / 2) * 10);
}

//2.a Реализовать функцию возведения числа a в степень b
int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        result = result * a;
        b--;
    }
    return result;
}

//2.b Реализовать функцию возведения числа a в степень b, используя реурсию.
int powerRecursion(int a, int b) {
    if (b == 0)
        return 1;
    else
        return a * powerRecursion(a, b - 1);
}

//2.c Реализовать функцию возведения числа a в степень b используя реурсию., используя свойство чётности степени.
int powerRecursionEven(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        int x = powerRecursionEven(a, b / 2);
        return x * x;
    } else {
        return a * powerRecursionEven(a, b - 1);
    }
}

//3. * Программа преобразует целое число. У программы две команды:
//Прибавь 1
//Умножь на 2
//Сколько существует путей для данной программы, которые число 3 преобразуют в число 20?
int solutions(int a, int b) {
    if (a > b)
        return 0;
    if (a == b)
        return 1;
    if (b % 2 != 0)
        return solutions(a, b - 1);
    return (solutions(a, b - 1) + solutions(a, b / 2));
}

int main(int argc, const char * argv[]) {
    printf("DecToBin: %d -> %d\n",545, decToBin(545));  // O(n)
    printf("%d to the power of %d: %d\n", 2, 10, power(2, 10)); // O(n)
    printf("%d to the power of %d (recursion): %d\n", 3, 5, powerRecursion(3, 5)); // O(n)
    printf("%d to the power of %d (even property): %d\n", 4, 6, powerRecursionEven(4, 6)); // O(logn)
    printf("%d solutions\n", solutions(3, 20)); // O(logn)
    return 0;
}
