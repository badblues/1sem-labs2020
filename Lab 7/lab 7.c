#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define size 10


void bubble_sort(int *num, int n){
    int i, found;
    do{
        found=0;
        for(i=0; i<n-1; i++)
            if (num[i]>num[i+1]){
                int tmp=num[i]; num[i]=num[i+1]; num[i+1]=tmp;
                found++;
            }
    }
    while(found!=0);
}

int merge(int Array[], int N){

    int n=sqrt(N)+1;
    int h=-1, max=0;

    if ((n-1)*(n-1)==N) n=n-1;

    int **Matrix=(int*) malloc(n*sizeof(int*));
    for (int p=0; p<n; p++) Matrix[p]=(int*) malloc(n*sizeof(int));

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (h==N-1){
                Matrix[i][j]=max+1;
                printf("%d ", Matrix[i][j]);
                continue;
            }
            h++;
            Matrix[i][j]=Array[h];
            if (Array[h]>max) max=Array[h];
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int q=0; q<n; q++){
        bubble_sort(Matrix[q], n);
    }

    for (int i=0; i<n; i++) {
        for (int j = 0; j<n; j++)
            printf("%d ", Matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<N; i++){
        int min=0;
        for (int j=0; j<n; j++)
            if (Matrix[j][0]<Matrix[min][0])
                min=j;
            Array[i]=Matrix[min][0];
            for (int k=1; k<n; k++){
                Matrix[min][k-1]=Matrix[min][k];
            }
            Matrix[min][n-1]=max+1;
    }

    return(Array);
}

int main() {

    //Filling array by random numbers
    int Arr[size];
    srand(time(NULL));
    for (int i=0; i<size; i++){
        Arr[i]=rand()%1000;
        printf("%d ",Arr[i]);}
    printf("\n");

    merge(Arr, size);
    for (int i=0; i<size; i++)
        printf ("%d ", Arr[i]);
    
    return 0;
}