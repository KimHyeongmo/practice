#include <stdio.h>
#include <stdbool.h>

bool check[5] = {0,};

bool data[5][5] = {{0,},};

void create()
{
    data[0][1] = 1;
    data[1][0] = 1;

    data[0][2] = 1;
    data[2][0] = 1;

    data[2][4] = 1;
    data[4][2] = 1;

    data[0][3] = 1;
    data[3][0] = 1;

    data[2][3] = 1;
    data[3][2] = 1;

    data[3][4] = 1;
    data[4][3] = 1;
}

void dfs(int start)
{
    if(check[start]) return;
    check[start] = 1;

    for(int i = 0; i < 5; i++)
    {
        if(data[start][i] == 1)
        {
            dfs(i);
        }
    }
    printf("%d\n",start+1);
}

int main()
{
    int start = 0;
    create();
    dfs(start);
}