#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

void Encription(){

    unsigned char c = ' ';
    int n = 0, i = -1, v, l = 0, d, f = 0, h = 0;
    int radix, pwr = 0, num = 0;
    float byte = 255, t = 0;

    char* str = (char*)malloc(sizeof(char ));
    int* sym_code = (int*)malloc(sizeof(int));
    char buff[8];
    char* sym_code_ns2;
    int* sym_code_ns2int;

    //Entering a string and saving writing codes
    printf("Enter:\n");
    do{
        if (c != '\n'){
            scanf("%c", &c);
            n++; i++;
            str = (char*)realloc(str, n*sizeof(char));
            sym_code = (int*)realloc(sym_code, n*sizeof(int));
            str[i] = c;
            sym_code[i] = str[i];
        }
    }
    while (c != '\n');
    n--;

    printf("Text: ");
    for (int j = 0; j < n; j++)
        printf("%c", str[j]);
    printf("\n");
    free(str);
    printf("Symbol code: ");
    for (int j = 0; j < n; j++)
        printf("%d ", sym_code[j]);

    printf ("\nEnter radix:\n");
    scanf ("%d", &radix);

    //Finding amount of numbers М
    while (byte > 1){
        t = (radix - 1) * pow(radix, pwr);
        byte = byte - t;
        pwr++;
        num++;
    }

    sym_code_ns2 = (char*)malloc(n*num*sizeof(char));
    sym_code_ns2int = (int*)calloc(n, sizeof(int));

    //Converting the symbol codes to another number system and write them to the string, adding zeros
    for (int j = 0; j < n; j++){
        itoa(sym_code[j], buff, radix); //Converting
        int k = num;
        //Finding the number of digits of the number in buff
        v = strlen(buff);
        //Move symbol code to sym_code_ns2int
        d = 0;
        for (int h = 0; h < v; h++){
            d = d * 10;
            if (buff[h] > 57){
                d = d + (int)buff[h] - 86;
                continue;
            }
            d = d + (buff[h] & 0x0F);
        }
        sym_code_ns2int[f] = d;
        //Adding zeros
        int g = 0;
        for (int h = k - v; h > 0; h--){
            sym_code_ns2[l+g] = '0';
            g++;
        }
        //Adding digits to number
        int s = 0;
        for (int j = v; j > 0; j--){
            sym_code_ns2[l + (k - v) + s] = buff[s];
            s++;
        }
        f++;
        l = l + num; //Index of the beginning of each number in the array sym_code_ns2
    }

    free(sym_code);

    printf("Symbol code: ");
    for (int j = 0; j < n * num; j++){
        h++;
        printf("%c", sym_code_ns2[j]);
        if ((h % num) == 0){
            printf(" ");
        }
    }
    printf("\n");

    printf("Cipher: ");
    //Converting numbers to symbols
    for (int j = 0; j < n; j++){
        if (sym_code_ns2int[j] > 255){
            sym_code_ns2int[j] = sym_code_ns2int[j] - 255;
        }
        printf ("%c", sym_code_ns2int[j]);
    }

}

int main() {

    Encription();

    return(0);
}