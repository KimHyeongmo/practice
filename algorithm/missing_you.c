//가장 먼 두 사람 구하기
//앞 사람 뒷 사람 모두 적은 번호로!
#include <stdio.h>
#define MAX_PEOPLE 1000

int people_place[MAX_PEOPLE][2] = {{0,0}};

int main() {
	int people_number;
	int x,y;
	int people_a, people_b;
	long long max = 0;
	fscanf(stdin,"%d",&people_number);
	for(int i = 0; i < people_number; i++)
	{
		fscanf(stdin,"%d %d",&x,&y);
		people_place[i][0] = x;
		people_place[i][1] = y;
	}
	
	for(int i = 0; i < people_number; i++)
	{
		for(int j = i+1; j < people_number; j++)
		{
			long long xx;
	
			xx = (long long)people_place[i][0] - (long long)people_place[j][0];
			xx = xx*xx;
			long long yy;
			yy = (long long)people_place[i][1] - (long long)people_place[j][1];
			yy = yy*yy;
			
			long long sum = xx+yy;
			
			if(max < sum)
			{
				people_a = i;
				people_b = j;
				max = sum;
			}
		}
	}
	
	
	printf("%d %d",people_a+1,people_b+1);
}
