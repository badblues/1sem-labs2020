#include <stdio.h>
#include <malloc.h>

int Func1() {
    int n = 1, i = 0;
    char c;
    int *Arr = (int *) malloc(n * sizeof(int));

    printf("Enter the array elements \n");
    scanf("%c", &c);
    while (1) {
        scanf("%c", &c);
        if ( c == '\n') { break; }
        if ((c<=57)&&(c>=48)){
            Arr = (int *) realloc(Arr, n * sizeof(int));
            Arr[i] = (int)c-48;
            i++;
            n++;
        }
    }

    int s = 0; //сумма отрицательных чисел
    for (i = 0; i <= n - 1; i++)
        if (Arr[i] < 0) s++;
    return (s);
}

int Func2() {
    int n = 1;
    printf("Enter a number\n");
    scanf("%d", &n);
    int s; //Сумма цифр числа
    int k;
    for (s = 0; n != 0; n = n / 10) {
        k = n % 10;
        s = s + k;
    }
    return (s);
}

int Func3() {
    printf("Enter elements of array (5)\n");
    int A[5];
    int n = 4;
    int i, s;
    for (i = 0; i <= n; i++)
        scanf("%d", &A[i]);
    for (i = 0, s = 0; i <= n; i++)
        if (A[i] > s) s = A[i];
    return (s);
}

int main() {
    printf("Choose function: 1 - Number of negative, 2 - Sum of characters, 3 - Max elem of array\n");
    int f;
    scanf("%d", &f);
    switch (f) {
        case 1:
            printf("\nNumber of negative: %d", Func1());
            break;
        case 2:
            printf("\nSum of characters: %3d", Func2());
            break;
        case 3:
            printf("\nMax elem of array is: %d", Func3());
            break;
    }
    return 0;
}
