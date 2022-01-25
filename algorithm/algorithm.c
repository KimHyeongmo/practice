#include <stdio.h>

void two_pointer()
{
    int array[13] = {1,3,5,6,9,11,
    12,16,17,19,22,25,28};

    int count = 0;

    int S = 27;
    int l = 0;
    int r = 12;

    while(l<=r)
    {
        int sum = array[l] + array[r];
        if(sum > S)
            r--;
        else if(sum < S)
            l++;
        else
        {
            l++;
            r--;
            count++;
        }
    }

    fprintf(stdout,"%d",count);
}




int main()
{

    two_pointer();
}