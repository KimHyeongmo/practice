#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_NODE  32

void insert_graph(int **graph)
{
    int i, j;

    i = 1; j = 0; graph[i][j] = 1; graph[j][i] = 1;
    i = 2; j = 1; graph[i][j] = 1; graph[j][i] = 1;
    i = 3; j = 2; graph[i][j] = 1; graph[j][i] = 1;
    i = 3; j = 0; graph[i][j] = 1; graph[j][i] = 1;
    i = 1; j = 6; graph[i][j] = 1; graph[j][i] = 1;
    i = 5; j = 2; graph[i][j] = 1; graph[j][i] = 1;
    i = 4; j = 3; graph[i][j] = 1; graph[j][i] = 1;
    i = 5; j = 4; graph[i][j] = 1; graph[j][i] = 1;
    i = 6; j = 5; graph[i][j] = 1; graph[j][i] = 1;
}

int ** create_graph(int number_of_node)
{
    int **tempt;
    tempt = (int **)malloc(sizeof(int *)*number_of_node);
    for(int i = 0;i<number_of_node;i++)
    {
        tempt[i] = (int *)malloc(sizeof(int)*number_of_node);
        for(int j = 0;j<number_of_node;j++)
        {
            tempt[i][j] = 0;
        }
    }
    //임시
    printf("%d\n",tempt[3][0]);
    insert_graph(tempt);
    printf("%d\n",tempt[3][0]);
    return tempt;
}


void bfs(int **graph,int start, int number_of_node)
{
    unsigned int check = 0;
    unsigned int number = 0;
    for(int i = 0; i < number_of_node ; i++)
    {
        number = number + (1 << i);
    }
    int *queue = (int *)malloc((sizeof(int))*number_of_node);

    for(int i = 0; i<number_of_node; i++)
    {
        queue[i] = 0;
    }

    check = check + (1 << start);

    int count = 0;//다음번 넣어야 할 배열의 위치
    int count_queue = 0;//다음번 탐색할 배열의 위치
    *(queue+count) = start;
    while(count_queue < number_of_node)
    {
        start = queue[count_queue];
        fprintf(stdout,"%d\n",start);
        count_queue++;
        for(int i = 0; i<number_of_node; i++)
        {
            if(graph[start][i] == 1)
            {
                if(((check >> i)&1) == 1)
                {
                    continue;
                }
                else{
                    check = check + (1 << i);
                    queue[++count] = i;
                }
                
            }
        }


    }
}

int main()
{
    int **graph;
    int number_of_node;
    fscanf(stdin,"%d",&number_of_node);
    graph = create_graph(number_of_node);
    printf("%d\n",graph[3][0]);
    printf("hi\n");
    bfs(graph, 0, number_of_node);
    printf("hi\n");
    free(graph);

}