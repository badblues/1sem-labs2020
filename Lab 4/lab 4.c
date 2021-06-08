#include <stdio.h>
#include <stdlib.h>

int main() {
    int A,B,V,G,D;
    printf("If AB*VG=DDD and D*VG-AB=VV, then what's AB*G?\n");
    //Циклы перебора переменных
    for (A = 1; A < 10; A++)
        for (B = 1; B < 10; B++)
            for (V = 1; V < 10; V++)
                for (G = 1; G < 10; G++)
                    for (D = 1; D < 10; D++){
                        //Условие из задачи, если оно выполняется - цифры подобранны верно
                        if (((A*10+B)*(V*10+G) == D*111) && (D*(V*10+G)-(A*10+B) == V*11)){
                            int sol = (A * 10 + B) * G;
                            printf("A - %d\nB - %d\nV - %d\nG - %d\nD - %d\n", A,B,V,G,D);
                            printf("Solution: %d\n", sol);
                        }
                    }
    system ("pause");
    return 0;
}
