/*
This program is testing for stdin buffer.
When I write input data like "hi hi hi .....", I want to store this data a1 = hi, a2 = hi, a3 = hi.
Sequential string datas have to ignore space and splitted.
*/

#include <stdio.h>

int main()
{
    printf("hi");
    printf("ignore");
    printf("ignore2");
}