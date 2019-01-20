

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. Рассчитать индекс массы тела
float bodyMassIndex(float m, float h) {
    float index = m / (h * h);
    return index;
}

// 2.a Написать программу обмена значениями двух целочисленных переменных c использованием третьей переменной.
int exchangeValue3(int a, int b) {
    int c = a;
    a = b;
    b = c;
    return printf("%d " "%d\n", a, b);
}
// 2.b Написать программу обмена значениями двух целочисленных переменных без использованием третьей переменной.
int exchangeValue(int a, int b) {
    a += b;
    b = a - b;
    a = a - b;
    return printf("%d " "%d\n", a, b);
}

// 3. Написать программу нахождения корней заданного квадратного уравнения.
float quadraticEquation(float a, float b, float c) {
    float x1 = 0.0;
    float x2 = 0.0;
    double d = b * b - 4 * a * c;
    if (d > 0) {
        if (a != 0) {
            x1 = - b + sqrt(d) / (2 * a);
            x2 = - b - sqrt(d) / (2 * a);
        } else {
            x1 = - b + sqrt(d);
            x2 = - b - sqrt(d);
        }
        printf("%.2f " "%.2f\n", x1, x2);
    } else if (d == 0) {
        x1 = - b / (2 * a);
        printf("%.2f\n", x1);
    } else {
        printf("No roots\n");
    }
    return 0;
}

// 4. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
void seasonByMonth() {
    int month;
    scanf("%d", &month);
    if ((month == 12) && (month == 12) && (month == 12)) {
        printf("Winter\n");
    } else if ((month >= 3) && (month <= 5)) {
        printf("Spring\n");
    } else if ((month >= 6) && (month <= 8)) {
        printf("Summer\n");
    } else if ((month >= 9) && (month <= 11)) {
        printf("Autumn\n");
    } else {
        printf("Wrong month value\n");
    }
}

//5. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void yearDeclension() {
    int year;
    scanf("%d", &year);
    if ((year % 10 == 1) && (year % 100 != 11)) {
        printf("%d год\n", year);
    } else if ((year % 10 >= 2) && (year % 10 <= 4) && ((year % 100 < 10) || (year % 100 >= 20))) {
        printf("%d года\n", year);
    } else {
        printf("%d лет\n", year);
    }
}

//6. *С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся ли к поля к одному цвету или нет.
int isEven(int number) {
    if (number % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int cageColorCompare(int x1, int y1, int x2, int y2) {
    if (((isEven(x1) == isEven(y1)) && (isEven(x2) == isEven(y2))) ||
       ((isEven(x1) != isEven(y1)) && (isEven(x2) != isEven(y2)))) {
       return printf("Same color\n");
    } else {
       return printf("Diffirent color\n");
    }
}

//7. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
int quotientAndRemainder(int n, int k) {
    int q = 0;
    while (n >= k) {
        q += 1;
        n -= k;
    }
    return printf("Quotient = %d, Remainder = %d\n", q, n);
}

//8. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
int oddNunbers(int n) {
    while (n > 0) {
        if (n % 2 == 1) {
            printf("True\n");
        } else {
            printf("False\n");
        }
        n /= 10;
    }
    return 0;
}

//9. * Написать функцию, генерирующую случайное число от 1 до 100. без использования стандартной функции rand()


//10. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. Например, 25 \ :sup: 2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
long automorphicNumber(long n) {
    long x = 1;
    long y = 1;
    
    while (y < n) {
        while (x <= (y * 10)) {
           if ((x * x) % (y * 10) == x) { printf("%ld ",x); }
        x++;
        }
    y *= 10;
    }
printf("\n");
return 0;
}

//11. В тексте программы, написанной на уроке избавиться от условия в цикле.
void average() {
    int counter = 0;
    float sum = 0;
    int in;
    
    do {
        scanf("%d", &in);
        sum += in;
        counter++;
    } while (in != -1);
    
    if (counter != 0)
        printf("mean = %.2f\n", (float) ((sum - in) / (counter - 1)));
    else
        printf("%s\n", "No input");
}

int main(int argc, const char** argv) {
    printf("%.2f\n", bodyMassIndex(91, 1.83));
    exchangeValue3(74, 46);
    exchangeValue(34, 21);
    quadraticEquation(3, 6, 2);
    seasonByMonth();
    yearDeclension();
    cageColorCompare(5, 4, 3, 5);
    quotientAndRemainder(15, 4);
    oddNunbers(4382);
    automorphicNumber(10023450);
    average();
    return 0;
}


