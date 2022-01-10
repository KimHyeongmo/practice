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
        fscanf(stdin,"%s",buf[i]); //fscanf process about space and \n char. so we don't need to getchar() before fscanf. but when we finish fscanf, and we write additional input data using another input function not to process \n or space, we need to use getchar().
        //buffer can have space and \n. If input = "h1 h2 h3 h4 \n", buffer has " \n". so we need to use getchar twice.
    }
    for (int i = 0; i < 4; i++)
    {
        fprintf(stdout,"%s",buf[i]);
        fprintf(stdout,"\n");
    }

    //getchar();//for buffer flush ' '?
    getchar();//for buffer flush \n?
    char buff[10];
    fgets(buff,sizeof(buff),stdin);//for space included in string
    buff[strlen(buff)-1] = '\0';
    printf("%s finish",buff);
    
}