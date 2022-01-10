/*
This program is testing for stdin buffer.
When I write input data like "hi hi hi .....", I want to store this data a1 = hi, a2 = hi, a3 = hi.
Sequential string datas have to ignore space and splitted.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[4][4];
    for (int i = 0; i < 4; i++)
    {
        fscanf(stdin,"%s",buf[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        fprintf(stdout,"%s",buf[i]);
        fprintf(stdout,"\n");
    }

    getchar();//for buffer flush \n?
    char buff[10];
    fgets(buff,sizeof(buff),stdin);//for space included in string
    buff[strlen(buff)-1] = '\0';
    printf("%s finish",buff);
    
}