#include <stdio.h>
#include <stdlib.h>

int Func1(){
    int A[5];
    int n = 4;
    printf("Enter the array elements (5)\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    int s = 0; //сумма отрицательных чисел
    for (int i = 0; i <= n; i++)
        if (A[i] < 0) s++;
    printf("\nNumber of negative: %d\n", s);
    return 0;
}

int Func2(){
    int n = 1;
    printf("Enter a number\n");
    scanf("%d", &n);
    int s; //Сумма цифр числа
    int k;
    for (s=0; n!=0; n=n/10){
        k=n%10;
        s =s + k;
    }
    printf("\nSum of characters: %3d\n", s);
    return 0;
}

int Func3 (){
        printf ("Enter elements of array (5)\n");
        int A[5];
        int n = 4;
        int i,s;
        for (i=0; i<=n; i++)
            scanf("%d", &A[i]);
        for (i=0,s=0; i<=n; i++)
            if (A[i]>s) s=A[i];
        printf("\nMax elem of array is: %d\n", s);
        return 0;
}

int main() {
   printf("Choose function: 1 - Number of negative, 2 - Sum of characters, 3 - Max elem of array\n");
   int f;
   scanf("%d", &f);
   switch (f){
       case 1:
           Func1();
           break;
       case 2:
           Func2();
           break;
       case 3:
           Func3();
           break;
   }
   system ("pause");
   return 0;
}