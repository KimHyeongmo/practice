/*
이 문제의 핵심은 경우의 수를 bit로 표현한 것이다.
*/
#include <stdio.h>

#define MAX_RATE 10000
#define MAX_PEOPLE 20

int main() {
	int people_number;
	int best;
	int *ability;
	int ability_people;
	fscanf(stdin,"%d %d",&people_number, &best);
	ability = (int *)malloc(sizeof(int)*people_number);
	for(int i = 0; i < people_number; i++)
	{
		fscanf(stdin,"%d",&ability_people);
		ability[i] = ability_people;
	}
	
	
	int hong;
	int pair = (1 << (people_number-1)) - 1;
	int count = 0;
	for(pair; pair >= 0; pair--)
	{
		hong = ability[0];
		for(int i = 0; i < people_number-1; i++)
		{
			if(pair & (1<<i))
			{
				hong += ability[i+1];
			}
		}
		if(hong == best)
		{
			count++;
		}
		
	}
	printf("%d",count);	
}
