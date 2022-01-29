#include <stdio.h>
#include <stdlib.h>

// 5by2행렬

int main()
{
    int **array;
    int **array_store;
    array = (int**)malloc(sizeof(int*)*5);
    array_store = (int**)malloc(sizeof(int*)*5);
    for(int i = 0; i < 5; i ++)
    {
        array[i] = (int *)malloc(sizeof(int)*2);
        array[i][0] = i;
        array[i][1] = i*5;
        array_store[i] = (int *)malloc(sizeof(int)*2);
        array_store[i][0] = i;
        array_store[i][1] = i*5;
    }

    

}