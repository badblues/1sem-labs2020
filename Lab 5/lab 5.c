#include <stdio.h>
#include <math.h>

int Func_Sum(){
    int flag;
    double contr_func, n, c1, z1, y, x, sum;

    for (x = 0.1; x <= 0.9; x += 0.1){
        flag = 0;
        n = 0;
        c1 = 1; z1 = 1;
        sum = 1; // sum = 1 because zero element is 1
        contr_func = 1/pow((1+x), 0.5);
        while (flag == 0){
            n++;
            y = pow(-1, n) * pow(x, n) * ((c1 * (2 * n - 1)) / (z1 * (2 * n))); //formula of n element
            c1 = c1 * (2 * n - 1); //Variables that save values of last numerator and
            z1 = z1 * (2 * n);     //denominator
            sum = sum + y;
            if (round(sum * 10000) == round(contr_func * 10000))
                flag = 1;
        }
        printf("x=%0.1lf  line sum=%lf  func=%lf  n=%1.0lf\n", x, sum, contr_func, n);
    }
    return 0;
}

int main() {
    Func_Sum();
    return 0;
}